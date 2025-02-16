#pragma once
#include <iostream>

/*
    Everything done on 2/15/25 follows The Cherno's tutorial to start:
    https://youtu.be/ryRf4Jh_YC0?si=QJgzHvqrqvKwkWyv
*/


constexpr static size_t INIT_SIZE = 1;
constexpr static size_t GROW_FACTOR = 2;

template<typename T>
class Vector
{
public:
    Vector() { std::cerr << "Created empty vec" << std::endl; }
    ~Vector() {
        delete[] m_data;
        m_data = nullptr;
        m_len = m_cap = 0;
        std::cerr << "Deleted vec" << std::endl;
    }

    /* MEMBER ACCESS */
    constexpr size_t len() const { return m_len; }
    constexpr size_t cap() const { return m_cap; }
    T* data() { return m_data; }
    const T* data() const { return m_data; }
    constexpr size_t data_size() const { return sizeof(T)*m_len; }
    constexpr size_t container_size() const { return sizeof(*this); }

    /* DATA OPERATIONS */
    void push(const T& item) {
        if (!m_data)
            this->realloc(INIT_SIZE);
        else if (m_len >= m_cap)
            this->realloc(m_cap * GROW_FACTOR);

        m_data[m_len] = item;
        m_len++;
        return;
    }
    void push(T&& item) {
        if (!m_data)
            this->realloc(INIT_SIZE);
        else if (m_len >= m_cap)
            this->realloc(m_cap * GROW_FACTOR);

        m_data[m_len] = std::move(item);
        m_len++;
        return;
    }
    void pop() {    // also want a version that returns what was popped (std::optional??)
        if (m_data) {
            //m_data[m_len].~T(); // will cause double deletions???
            m_len--;
        }
    }
    template<typename... Args>  // explore variatic(?) templates, std::forward()
    T& emplace(Args&&... args) {    // and arg expansion
        if (!m_data)
            this->realloc(INIT_SIZE);
        else if (m_len >= m_cap)
            this->realloc(m_cap * GROW_FACTOR);

        m_data[m_len] = T(std::forward<Args>(args)...);
        return m_data[m_len++];
    }
    void clear() {
        for (size_t i = 0; i < m_len; i++)
            m_data[i].~T();
        m_len = 0;
    }


    /* OTHER UTILITIES */
    void print() const {    // requires T to overload `ostream <<` (change???)
        std::cout << "[";
        for (size_t i = 0; i < m_len; i++)
        {
            std::cout << m_data[i];
            if (i < m_len - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
    /*
    emplace (placement new()???)
    iterators
    insert (index & iter versions)
    erase (index & iter versions)
    fill
    swap
    empty
    reserve
    shrink_to_fit
    front, back
    negative indices
    resize
    alternate constructors
    copy & move constructors
    comparison operators
    */


    /* OPERATORS */
    T& operator[] (const size_t i) {
        if (i >= m_len) {
            std::cerr << "Index " << i << " out of bounds "
                << "(len = " << m_len << ")"
                << std::endl;
            return m_data[m_len - 1];
        }
        return m_data[i];
    }
    const T& operator[] (const size_t i) const {
        if (i >= m_len) {
            std::cerr << "Index " << i << " out of bounds "
                << "(len = " << m_len << ")"
                << std::endl;
            return m_data[m_len - 1];
        }
        return m_data[i];
    }


private:
    T* m_data = nullptr;
    size_t m_len = 0;
    size_t m_cap = 0;

    void realloc(size_t new_cap) {
        std::cerr << "(Re)allocated vector. (Old cap = " << m_cap <<
            "; New cap = " << new_cap << ")" << std::endl;
        T* old = m_data;

        if (new_cap < m_len)
            m_len = m_cap = new_cap;
        else
            m_cap = new_cap;
        m_data = new T[m_cap];

        for (size_t i = 0; i < m_len; i++)
            m_data[i] = std::move(old[i]);
        delete[] old;
        return;
    }
};