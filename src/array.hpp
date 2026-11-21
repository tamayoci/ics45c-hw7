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

    


}