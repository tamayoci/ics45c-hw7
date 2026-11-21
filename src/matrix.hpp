#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template<typename T>
class Matrix {
public:
    Matrix()
    : rows{0}, cols{0}, data{0} {
}

    Matrix(int rows, int cols)
        : rows{rows},
        cols{cols},
        data{rows} {
        for (int i = 0; i < rows; ++i) {
            data[i] = Array<T>{cols};
        }
    }

    Array<T>& operator[](int row) {
        return data[row];
    }

    const Array<T>& operator[](int row) const {
        return data[row];
    }

    int num_rows() const {
        return rows;
    }

    int num_cols() const {
        return cols;
    }

    void fill(const T& val) {
        for (int i = 0; i < rows; ++i) {
            data[i].fill(val);
        }
    }

    template<typename Fn>
    void fill_with_fn(Fn fn) {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                data[r][c] = fn(r, c);
            }
        }
    }

private:
    int rows, cols;
    Array<Array<T>> data;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (int r = 0; r < matrix.num_rows(); ++r) {
        out << matrix[r] << '\n';
    }
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix) {
    for (int r = 0; r < matrix.num_rows(); ++r) {
        in >> matrix[r];
    }
    return in;
}

#endif