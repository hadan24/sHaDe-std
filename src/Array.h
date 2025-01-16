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
    ~Array() { std::cerr << "Destroyed array" << std::endl; }
    
    Array(Array<T, S>& const src) {
        for (size_t i = 0; i < S; i++)
            m_data[i] = src.m_data[i];  // calls potential copy constructors
        std::cerr << "Copied array" << std::endl;
    }

    /*
    print()
    fill()
    empty()
    swap()
    operator=
    cmp operators
    iterators
    filter, sort, map
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

    T& operator[] (size_t const i) { return m_data[i]; }
    const T& operator[] (size_t const i) const { return m_data[i]; }

private:
    T m_data[S];
};