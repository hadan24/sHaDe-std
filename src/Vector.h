#pragma once
#include <iostream>
#include "ContiguousIter.h"

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
    using Iter = ArrIter<Vector<T>>;
    using ConstIter = ConstArrIter<Vector<T>>;
    using ValueType = T;    // for iterator

    Vector() {
        this->realloc(INIT_SIZE);
        std::cerr << "Created empty vec" << std::endl;
    }
    ~Vector() { // explore global operators new() and delete()
        // call item destructors separately due to realloc w/ global new()
        this->clear();
        ::operator delete(m_data, m_cap * sizeof(T));

        m_data = nullptr;
        m_cap = 0;
        std::cerr << "Deleted vec" << std::endl;
    }

    /* DATA/MEMBER ACCESS */
    constexpr size_t len() const { return m_len; }
    constexpr size_t cap() const { return m_cap; }
    T* data() { return m_data; }
    const T* data() const { return m_data; }
    constexpr size_t data_size() const { return sizeof(T)*m_len; }
    constexpr size_t container_size() const { return sizeof(*this); }

    bool empty() { return m_len <= 0; }
    T& front() { return m_data[0]; }
    const T& front() const { return m_data[0]; }
    T& back() { return m_data[m_len - 1]; }
    const T& back() const { return m_data[m_len - 1]; }

    /* DATA OPERATIONS */
    void push(const T& item) {
        if (!m_data)
            this->realloc(INIT_SIZE);
        else if (m_len >= m_cap)
            this->realloc(m_cap * GROW_FACTOR);

        m_data[m_len++] = item;
    }
    void push(T&& item) {
        if (!m_data)
            this->realloc(INIT_SIZE);
        else if (m_len >= m_cap)
            this->realloc(m_cap * GROW_FACTOR);

        m_data[m_len++] = std::move(item);
    }

    template<typename... Args>  // explore variatic(?) templates, forward()
    T& emplace(Args&&... args) {    // and arg expansion
        if (!m_data)
            this->realloc(INIT_SIZE);
        else if (m_len >= m_cap)
            this->realloc(m_cap * GROW_FACTOR);

        // constructs item literally in its place on the heap
        new(&m_data[m_len]) T(std::forward<Args>(args)...); // explore placement new
        return m_data[m_len++];
    }
    // also want a version that returns what was popped (std::optional??)
    void pop() { if (m_data) m_data[--m_len].~T(); }

    void fill(const T& item) {
        for (size_t i = 0; i < m_len; i++)
            m_data[i] = item;
    }
    void clear() {
        for (size_t i = 0; i < m_len; i++)
            m_data[i].~T();
        m_len = 0;
    }

    Iter begin() { return Iter(m_data); }
    Iter end() { return Iter(m_data + m_len); }
    ConstIter begin() const { return ConstIter(m_data); }
    ConstIter const_begin() const { return ConstIter(m_data); }
    ConstIter end() const { return ConstIter(m_data + m_len); }
    ConstIter const_end() const { return ConstIter(m_data + m_len); }


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
    insert (index & iter versions)
    erase (index & iter versions)
    swap
    reserve
    shrink_to_fit
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

    void realloc(size_t new_cap) {  // explore global operators new(), delete()
        std::cerr << "(Re)allocated vector. (Old cap = " << m_cap <<
            "; New cap = " << new_cap << ")" << std::endl;

        T* old = m_data;
        size_t old_len = m_len;
        if (new_cap < m_len)
            m_len = new_cap;

        // ONLY alloc memory, don't call constructors w/ basic `new`
        // b/c we're move constructing in that place immediately
        m_data = (T*) ::operator new(new_cap * sizeof(T));
        for (size_t i = 0; i < m_len; i++)
            new(&m_data[i]) T( std::move(old[i]) );
            // can't just assign (=) here b/c that requires an object to exist
            // at the new m_data[i] location to move into

        // call item destructors separately due to realloc w/ global new()
        for (size_t i = 0; i < old_len; i++)
            old[i].~T();
        ::operator delete(old, m_cap * sizeof(T));

        m_cap = new_cap;
    }
};