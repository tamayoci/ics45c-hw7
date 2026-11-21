#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

template<typename T>
class Array {
public:

    Array()
        : len{0},
        buf{nullptr} {
    }

    explicit Array(int len)
        : len{len},
        buf{new T[len]} {
    }

    Array(const Array& other)
        : len{other.len},
          buf{new T[other.len]} {
        for (int i = 0; i < len; ++i) {
            buf[i] = other.buf[i];
        }
    }

    Array(Array&& other) noexcept
        : len{other.len},
        buf{other.buf} {
        other.len = 0;
        other.buf = nullptr;
    }

    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            Array temp(other);
            swap(*this, temp);
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            swap(*this, other);
        }
        return *this;
    }

}