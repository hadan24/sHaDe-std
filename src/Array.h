#pragma once
#include <iostream>
/*
    Everything done on 1/13/25 follows The Cherno's tutorial to start:
    https://youtu.be/TzB5ZeKQIHM?si=dz1Awx4u894hgcSN
*/

template<typename T, size_t L>
class Array
{
public:
    Array() { std::cerr << "Created empty array" << std::endl; }
    Array(const T& item)
    {
        fill(item);
        std::cerr << "Created & filled array" << std::endl;
    }
    Array(const T* arr) {
        // unfortunately necessary replacement for aggregate initialization :(
        // agg init requires no user-made constructors or non-public data members
        // (impossible here when I'd like to see when objs are created/destroyed)
        for (size_t i = 0; i < L; i++)
            m_data[i] = arr[i];
        std::cerr << "Created array from pointer" << std::endl;
    }
    Array(const Array<T, L>& src) {
        for (size_t i = 0; i < L; i++)
            m_data[i] = src.m_data[i];  // calls potential copy constructors
        std::cerr << "Copied array" << std::endl;
    }
    Array(Array<T, L>&& src) noexcept {
        memcpy(m_data, src.m_data, this->size());
        memset(src.m_data, NULL, src.size());
        std::cerr << "Moved array" << std::endl;
    }
    ~Array() { std::cerr << "Destroyed array" << std::endl; }

    /*
    iterators
    filter, sort, map, slice/take
    split(), reverse() ???
    */

    constexpr size_t len() const { return L; }
    constexpr size_t size() const { return sizeof(*this); }
    T* data() { return m_data; }
    const T* data() const { return m_data; }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < L; i++)
        {
            std::cout << m_data[i];
            if (i < L-1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
    void fill(const T& item) {
        for (size_t i = 0; i < L; i++)
            m_data[i] = item;
    }
    void swap(Array<T, L>& other) {
        if (&other == this) return;

        for (size_t i = 0; i < L; i++)
        {
            T temp = m_data[i];
            m_data[i] = other.m_data[i];
            other.m_data[i] = temp;
        }
    }

    T& front() { return m_data[0]; }
    const T& front() const { return m_data[0]; }
    T& back() { return m_data[L-1]; }
    const T& back() const { return m_data[L-1]; }

    T& operator[] (const size_t i) {
        if (i >= L) {
            std::cerr << "Index " << i << " out of bounds "
                << "(len = " << L << ")"
                << std::endl;
            return m_data[L-1];
        }
        return m_data[i];
    }
    const T& operator[] (const size_t i) const {
        if (i >= L) {
            std::cerr << "Index " << i << " out of bounds "
                << "(len = " << L << ")"
                << std::endl;
            return m_data[L-1];
        }
        return m_data[i];
    }
    Array<T, L>& operator= (Array<T,L>&& src) {
        if (this != &src) {
            // how to properly delete current data before moving src into here???
            // like if T were ptrs to heap data, how do I properly detect and
            //  delete those heap objects before moving?
            memcpy(m_data, src.m_data, this->size());
            memset(src.m_data, NULL, src.size());
            std::cerr << "Moved array" << std::endl;
        }
        return *this;
    }
    const bool operator== (const Array<T, L>& other) const {
        size_t i = 0;
        while (i < L) {
            if (m_data[i] != other.m_data[i])
                return false;
            i++;
        }
        return true;
    }
    const bool operator<= (const Array<T, L>& other) const {
        size_t i = 0;
        while (i < L) {
            if (m_data[i] > other.m_data[i])
                return false;
            i++;
        }
        return true;
    }
    const bool operator>= (const Array<T, L>& other) const {
        size_t i = 0;
        while (i < L) {
            if (m_data[i] < other.m_data[i])
                return false;
            i++;
        }
        return true;
    }
    const bool operator!= (const Array<T, L>& other) const {
        return !( (*this) == other );
    }
    const bool operator< (const Array<T, L>& other) const {
        return other >= (*this);
    }
    const bool operator> (const Array<T, L>& other) const {
        return other <= (*this);
    }
    

private:
    T m_data[L];
};