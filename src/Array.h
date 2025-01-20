#pragma once
#include <iostream>
/*
    Everything done on 1/13/25 follows The Cherno's tutorial to start:
    https://youtu.be/TzB5ZeKQIHM?si=dz1Awx4u894hgcSN
*/

template<typename T, size_t S>
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
    
    Array(const Array<T, S>& src) {
        for (size_t i = 0; i < S; i++)
            m_data[i] = src.m_data[i];  // calls potential copy constructors
        std::cerr << "Copied array" << std::endl;
    }

    /*
    operator=
    cmp operators
    iterators
    filter, sort, map, slice/take
    rename size to len, use size for num bytes
    constructor that takes ptr (replacement for aggregate init?)
        make m_data public for aggregate initialization???
    front & back???
    split(), reverse() ???

    add bounds checking
    */

    constexpr size_t size() const { return S; }
    T* data() { return m_data; }
    const T* data() const { return m_data; }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < S; i++)
        {
            std::cout << m_data[i];
            if (i < S-1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }

    void fill(const T& item) {
        for (size_t i = 0; i < S; i++)
            m_data[i] = item;
    }

    void swap(Array<T, S>& other) {
        if (&other == this) return;

        for (size_t i = 0; i < S; i++)
        {
            T temp = m_data[i];
            m_data[i] = other.m_data[i];
            other.m_data[i] = temp;
        }
    }

    T& operator[] (const size_t i) { return m_data[i]; }
    const T& operator[] (const size_t i) const { return m_data[i]; }

private:
    T m_data[S];
};