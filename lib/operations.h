#pragma once

#include "matrix.h"

#include <cassert>


namespace NMatrixLib {

// multiplication's functions

// basic matrix x vector multiplication
template<size_t size>
void Multiply(const TMatrix<size>& lhs, const TVector<size>& rhs, TVector<size>& result) {
    size_t i, j;
    float tmp;
    for (i = 0; i < size; ++i) {
        tmp = {};
        for (j = 0; j < size; ++j) {
            tmp += lhs._vecs[i]._vec4[j] * rhs._vec4[j];
        }
        result._vec4[i] = tmp;
    }
}

// sse matrix vector multiplication for 3 size
void MultiplySSE(const TMatrix<3>& lhs, const TVector<3>& rhs, TVector<3>& result);

// sse matrix vector multiplication for 4 size
void MultiplySSE(const TMatrix<4>& lhs, const TVector<4>& rhs, TVector<4>& result);

// basic matrix x matrix multiplication
template<size_t size>
void Multiply(const TMatrix<size>& lhs, const TMatrix<size>& rhs, TMatrix<size>& result) {
    size_t i, j, l;
    float tmp;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            tmp = {};
            for (l = 0; l < size; ++l) {
                tmp += lhs._vecs[i]._vec4[l] * rhs._vecs[l]._vec4[j];
            }
            result._vecs[i]._vec4[j] = tmp;
        }
    }
}

// sse matrix multiplication for 4x4 matrix
void MultiplySSE(const TMatrix<3>& lhs, const TMatrix<3>& rhs, TMatrix<3>& result);

// sse matrix multiplication for 4x4 matrix
void MultiplySSE(const TMatrix<4>& lhs, const TMatrix<4>& rhs, TMatrix<4>& result);

}
