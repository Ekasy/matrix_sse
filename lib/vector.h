#pragma once

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

#include <immintrin.h>


namespace {

static constexpr size_t SIZE = 4;

}


namespace NMatrixLib {

// aligned vector struct with size of 4 float elements
struct alignas(sizeof(__m128)) TVector4 {
    union {
        struct { float _v1, _v2, _v3, _v4; };
        __m128 _mm;
        float _vec4[SIZE];
    };

    TVector4() = default;
    explicit TVector4(float v1, float v2, float v3, float v4 = 0.)
        : _v1(v1)
        , _v2(v2)
        , _v3(v3)
        , _v4(v4)
    {}

    bool operator == (const TVector4& other) const {
        return  equal(_v1, other._v1) &&
                equal(_v2, other._v2) &&
                equal(_v3, other._v3) &&
                equal(_v4, other._v4);
    }

    friend std::ostream& operator << (std::ostream& os, const TVector4& vec4);

private:
    static bool equal(const float lhs, const float rhs, const float precision = .00001) {
        return std::fabs(lhs - rhs) < precision;
    }

};


// aligned vector struct with size of 4 float elements
// template with actual size 3 and 4
template<size_t size>
struct alignas(sizeof(__m128)) TVector {
    union {
        struct { float _v1, _v2, _v3, _v4; };
        __m128 _mm;
        float _vec4[SIZE];
    };

    TVector() = default;
    explicit TVector(float v1, float v2, float v3, float v4 = 0.)
        : _v1(v1)
        , _v2(v2)
        , _v3(v3)
        , _v4(v4)
    {}

    bool operator == (const TVector<size>& other) const {
        for (size_t i = 0; i < size; ++i) {
            if (!equal(_vec4[i], other._vec4[i])) {
                return false;
            }
        }
        return true;
    }

    friend std::ostream& operator << (std::ostream& os, const TVector<3>& vec);
    friend std::ostream& operator << (std::ostream& os, const TVector<4>& vec);

private:
    static bool equal(const float lhs, const float rhs, const float precision = .00001) {
        return std::fabs(lhs - rhs) < precision;
    }

};

}
