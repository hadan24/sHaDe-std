#pragma once

/*
    Iterator code follows The Cherno's tutorial to start:
    https://youtu.be/F9eDv-YIOQ0?si=whoGh06QaVCZMorn
*/

template<typename Arr>
class ConstArrIter;

template<typename Arr>
class ArrIter {
public:
    using T = typename Arr::ValueType;

    T* m_ptr;   // DONT'T USE, for conversions between Const and non-Const

    ArrIter(T* ptr) : m_ptr(ptr) {}
    ArrIter(ConstArrIter<Arr> ptr) : m_ptr(const_cast<T*>(ptr.m_ptr)) {}

    ArrIter& operator++ () {
        m_ptr++;
        return *this;
    }
    ArrIter operator++ (int) {
        return ArrIter(m_ptr++);
    }
    ArrIter& operator+= (size_t i) {
        m_ptr += i;
        return *this;
    }
    ArrIter operator+ (size_t i) const {
        return ArrIter(m_ptr + i);
    }
    ArrIter operator+ (const ArrIter& other) const {
        return ArrIter(m_ptr + other.m_ptr);
    }
    ArrIter& operator-- () {
        m_ptr--;
        return *this;
    }
    ArrIter operator-- (int) {
        return ArrIter(m_ptr--);
    }
    ArrIter& operator-= (size_t i) {
        m_ptr -= i;
        return *this;
    }
    ArrIter operator- (size_t i) const {
        return ArrIter(m_ptr - i);
    }
    ptrdiff_t operator- (const ArrIter& other) const {
        return m_ptr - other.m_ptr;
    }
    T& operator[] (size_t i) const { return m_ptr[i]; }
    T& operator* () const { return *m_ptr; }
    T* operator-> () const { return m_ptr; }

    bool operator== (const ArrIter& other) const { return m_ptr == other.m_ptr; }
    bool operator!= (const ArrIter& other) const { return m_ptr != other.m_ptr; }
    bool operator<= (const ArrIter& other) const { return m_ptr <= other.m_ptr; }
    bool operator>= (const ArrIter& other) const { return m_ptr >= other.m_ptr; }
    bool operator< (const ArrIter& other) const { return m_ptr < other.m_ptr; }
    bool operator> (const ArrIter& other) const { return m_ptr > other.m_ptr; }

    bool operator== (const T* other) const { return m_ptr == other; }
    bool operator!= (const T* other) const { return m_ptr != other; }
    bool operator<= (const T* other) const { return m_ptr <= other; }
    bool operator>= (const T* other) const { return m_ptr >= other; }
    bool operator< (const T* other) const { return m_ptr < other; }
    bool operator> (const T* other) const { return m_ptr > other; }
};

template<typename Arr>
class ConstArrIter {
public:
    using T = typename Arr::ValueType;

    const T* m_ptr; // DONT'T USE, for conversions between Const and non-Const

    ConstArrIter(const T* ptr) : m_ptr(ptr) {}
    ConstArrIter(ArrIter<Arr> ptr) : m_ptr(const_cast<const T*>(ptr.m_ptr)) {}

    ConstArrIter& operator++ () {
        m_ptr++;
        return *this;
    }
    ConstArrIter operator++ (int) {
        return ConstArrIter(m_ptr++);
    }
    ConstArrIter& operator+= (size_t i) {
        m_ptr += i;
        return *this;
    }
    ConstArrIter operator+ (size_t i) const {
        return ConstArrIter(m_ptr + i);
    }
    ConstArrIter operator+ (const ConstArrIter& other) const {
        return ConstArrIter(m_ptr + other.m_ptr);
    }
    ConstArrIter& operator-- () {
        m_ptr--;
        return *this;
    }
    ConstArrIter operator-- (int) {
        return ConstArrIter(m_ptr--);
    }
    ConstArrIter& operator-= (size_t i) {
        m_ptr -= i;
        return *this;
    }
    ConstArrIter operator- (size_t i) const {
        return ConstArrIter(m_ptr - i);
    }
    ptrdiff_t operator- (const ConstArrIter& other) const {
        return m_ptr - other.m_ptr;
    }
    const T& operator[] (size_t i) const { return m_ptr[i]; }
    const T& operator* () const { return *m_ptr; }
    const T* operator-> () const { return m_ptr; }

    bool operator== (const ConstArrIter& other) const { return m_ptr == other.m_ptr; }
    bool operator!= (const ConstArrIter& other) const { return m_ptr != other.m_ptr; }
    bool operator<= (const ConstArrIter& other) const { return m_ptr <= other.m_ptr; }
    bool operator>= (const ConstArrIter& other) const { return m_ptr >= other.m_ptr; }
    bool operator< (const ConstArrIter& other) const { return m_ptr < other.m_ptr; }
    bool operator> (const ConstArrIter& other) const { return m_ptr > other.m_ptr; }

    bool operator== (const T* other) const { return m_ptr == other; }
    bool operator!= (const T* other) const { return m_ptr != other; }
    bool operator<= (const T* other) const { return m_ptr <= other; }
    bool operator>= (const T* other) const { return m_ptr >= other; }
    bool operator< (const T* other) const { return m_ptr < other; }
    bool operator> (const T* other) const { return m_ptr > other; }
};