#pragma once
#include <iostream>
#include "ContiguousIter.h"
/*
    Everything done on 1/13/25 follows The Cherno's tutorial to start:
    https://youtu.be/TzB5ZeKQIHM?si=dz1Awx4u894hgcSN

    Iterator code moved to ContiguousIter.h
*/


template<typename T, size_t L>
class Array
{
public:
    using Iter = ArrIter<Array<T,L>>;
    using ConstIter = ConstArrIter<Array<T,L>>;
    using ValueType = T;    // for iterator

    Array() { std::cerr << "Created empty array" << std::endl; }
    Array(const T& item) {
        fill(item);
        std::cerr << "Created & filled array from l-val" << std::endl;
    }
    Array(T&& item) {
        for (size_t i = 0; i < L; i++)
            m_data[i] = std::move(item);
        std::cerr << "Created & filled array from r-val" << std::endl;
    }
    template<typename... Args>
    Array(Args&&... args) {
        for (size_t i = 0; i < L; i++)
            new(&m_data[i]) T(std::forward<Args>(args)...);
    }
    Array(const T* arr) {
        // unfortunately necessary replacement for aggregate initialization :(
        // agg init requires no user-made constructors nor non-public data
        // (impossible here when I want to see when objs are created/destroyed)
        for (size_t i = 0; i < L; i++)
            m_data[i] = arr[i];
        std::cerr << "Created array from pointer" << std::endl;
    }
    Array(const Array<T, L>& src) {
        for (size_t i = 0; i < L; i++)
            m_data[i] = src[i];  // calls potential copy constructors
        std::cerr << "Copied array" << std::endl;
    }
    Array(Array<T, L>&& src) noexcept {
        for (size_t i = 0; i < L; i++) {
            m_data[i] = std::move(src[i]);
            src[i].~T();
        }
        std::cerr << "Moved array" << std::endl;
    }
    ~Array() { std::cerr << "Destroyed array" << std::endl; }


    /* DATA ACCESS */
    constexpr size_t len() const { return L; }
    constexpr size_t size() const { return sizeof(*this); }
    T* data() { return m_data; }
    const T* data() const { return m_data; }

    T& front() { return m_data[0]; }
    const T& front() const { return m_data[0]; }
    T& back() { return m_data[L - 1]; }
    const T& back() const { return m_data[L - 1]; }

    Iter begin() { return Iter(m_data); }
    Iter end() { return Iter(m_data + L); }
    ConstIter begin() const { return ConstIter(m_data); }
    ConstIter const_begin() const { return ConstIter(m_data); }
    ConstIter end() const { return ConstIter(m_data + L); }
    ConstIter const_end() const { return ConstIter(m_data + L); }


    /* OTHER UTILITIES */
    void print() const {    // requires T to overload `ostream <<` (change???)
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
    void fill(T&& item) {
        for (size_t i = 0; i < L; i++)
            m_data[i] = std::move(item);
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

    /*
    filter  ->  <algorithm> std::remove_if
    map     ->  <algorithm> std::transform
    reverse ->  <algorithm> std::reverse
    sort    ->  yknow
    slice   ->  <span> std::span
    split   ->  do manually :/
    */


    /* OPERATORS */
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
    bool operator== (const Array<T, L>& other) const {
        size_t i = 0;
        while (i < L) {
            if (m_data[i] != other.m_data[i])
                return false;
            i++;
        }
        return true;
    }
    bool operator<= (const Array<T, L>& other) const {
        size_t i = 0;
        while (i < L) {
            if (m_data[i] > other.m_data[i])
                return false;
            i++;
        }
        return true;
    }
    bool operator>= (const Array<T, L>& other) const {
        size_t i = 0;
        while (i < L) {
            if (m_data[i] < other.m_data[i])
                return false;
            i++;
        }
        return true;
    }
    bool operator!= (const Array<T, L>& other) const {
        return !( (*this) == other );
    }
    bool operator< (const Array<T, L>& other) const {
        return other >= (*this);
    }
    bool operator> (const Array<T, L>& other) const {
        return other <= (*this);
    }
    

private:
    T m_data[L] = {};
};