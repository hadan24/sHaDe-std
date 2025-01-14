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
    constexpr size_t size() const { return S; }
    T* data() { return m_data; }
    const T* data() const { return m_data; }

    T& operator[] (size_t i) { return m_data[i]; }
    const T& operator[] (size_t i) const { return m_data[i]; }

private:
    T m_data[S];
};