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
    Array() { std::cerr << "Created array" << std::endl; }
    Array(const T& item)
    {
        fill(item);
        std::cerr << "Created & filled array" << std::endl;
    }
    ~Array() { std::cerr << "Destroyed array" << std::endl; }
    
    Array(const Array<T, L>& src) {
        for (size_t i = 0; i < L; i++)
            m_data[i] = src.m_data[i];  // calls potential copy constructors
        std::cerr << "Copied array" << std::endl;
    }

    /*
    iterators
    filter, sort, map, slice/take
    constructor that takes ptr (replacement for aggregate init?)
        make m_data public for aggregate initialization???
    front & back???
    split(), reverse() ???

    add bounds checking
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

    T& operator[] (const size_t i) { return m_data[i]; }
    const T& operator[] (const size_t i) const { return m_data[i]; }
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