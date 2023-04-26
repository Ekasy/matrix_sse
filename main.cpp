#include <iostream>
#include <ctime>

#include "lib/matrix.h"
#include "lib/operations.h"
#include "lib/vector.h"
#include "util/timer.h"


using NMatrixLib::TVector;
using NMatrixLib::TMatrix;


static constexpr size_t ITERATIONS = 100000;


template<size_t size>
using mat_mat_mul = void (*)(const NMatrixLib::TMatrix<size>&, const NMatrixLib::TMatrix<size>&, NMatrixLib::TMatrix<size>&);

template<size_t size>
using mat_vec_mul = void (*)(const NMatrixLib::TMatrix<size>&, const NMatrixLib::TVector<size>&, NMatrixLib::TVector<size>&);


template<size_t size>
size_t MarkTimeMatXMat(mat_mat_mul<size> func, const NMatrixLib::TMatrix<size>& A, const NMatrixLib::TMatrix<size>& B, NMatrixLib::TMatrix<size>& C) {
    NMatrixUtil::TTimer timer;
    for (size_t i = 0; i < ITERATIONS; ++i) {
        func(A, B, C);
    }
    timer.Stop();
    return timer.Duration();
}


template<size_t size>
size_t MarkTimeMatXVec(mat_vec_mul<size> func, const NMatrixLib::TMatrix<size>& A, const NMatrixLib::TVector<size>& B, NMatrixLib::TVector<size>& C) {
    NMatrixUtil::TTimer timer;
    for (size_t i = 0; i < ITERATIONS; ++i) {
        func(A, B, C);
    }
    timer.Stop();
    return timer.Duration();
}


void PrettyOutput(const std::string& msg, const bool is_equal, const size_t basic, const size_t sse) {
    std::cout << msg << std::endl;
    std::cout << "\tis equal: " << is_equal << std::endl;
    std::cout << "\tbasic: " << basic << "ns" << std::endl;
    std::cout << "\tsse: " << sse << "ns" << std::endl;
    std::cout << "\tprofit: " << static_cast<double>(basic) / static_cast<double>(sse) << std::endl;
}


int main() {
    const size_t m = 3;  // actual size

    TMatrix<m> mat1(1., 0., 0., 0., 0., 1., 0., 0., 0., 0., 1., 0., 0., 0., 0., 1.);
    TMatrix<m> mat2(1., 2., 3., 0., -1., 1., 0., 0., 0., 3., 1., 0., 0., 5., 0., 1.);
    TMatrix<m> mat3;
    TMatrix<m> mat4;

    TVector<m> vec1(1., 2., 3., 4.);
    TVector<m> vec3;
    TVector<m> vec4;

    auto basic = MarkTimeMatXMat(NMatrixLib::Multiply, mat1, mat2, mat3);
    auto sse = MarkTimeMatXMat(NMatrixLib::MultiplySSE, mat1, mat2, mat4);
    PrettyOutput("matrix measurement", mat3 == mat4, basic, sse);

    basic = MarkTimeMatXVec(NMatrixLib::Multiply, mat2, vec1, vec3);
    sse = MarkTimeMatXVec(NMatrixLib::MultiplySSE, mat2, vec1, vec4);
    PrettyOutput("matrix x vector measurement", vec3 == vec4, basic, sse);
}
