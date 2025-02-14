#pragma once
#include <iostream>

constexpr size_t DEFAULT_INIT_SIZE = 1;

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
        if (!m_data) {
            m_data = new T[DEFAULT_INIT_SIZE];
            m_cap = DEFAULT_INIT_SIZE;
        }
        else if (m_len == m_cap)
            m_data = this->realloc();

        m_data[m_len] = item;
        m_len++;
        return;
    }
    void pop() {    // also want a version that returns what was popped (std::optional??)
        if (m_data)
            m_len--;
    }

    /* OTHER UTILITIES */


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

    T* realloc() {
        T* temp = m_data;
        m_cap *= 2;
        m_data = new T[m_cap];

        for (size_t i = 0; i < m_len; i++)
            m_data[i] = temp[i];
        delete[] temp;
        return m_data;
    }
};