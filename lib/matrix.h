#pragma once

#include "vector.h"


namespace NMatrixLib {

struct alignas(sizeof(__m512)) TMatrix4 {
    union {
        struct { float
            _m11, _m12, _m13, _m14,
            _m21, _m22, _m23, _m24,
            _m31, _m32, _m33, _m34,
            _m41, _m42, _m43, _m44;
        };
        __m128 _mm[SIZE];
        TVector4 _vecs[SIZE];
    };

    TMatrix4() {}
    explicit TMatrix4(float m11, float m12, float m13, float m14,
                      float m21, float m22, float m23, float m24,
                      float m31, float m32, float m33, float m34,
                      float m41, float m42, float m43, float m44)
        : _m11(m11), _m12(m12), _m13(m13), _m14(m14)
        , _m21(m21), _m22(m22), _m23(m23), _m24(m24)
        , _m31(m31), _m32(m32), _m33(m33), _m34(m34)
        , _m41(m41), _m42(m42), _m43(m43), _m44(m44)
    {}

    operator __m128 const* () const { return _mm; }
	operator __m128* () { return _mm; }

    bool operator == (const TMatrix4& other) const {
        return  _vecs[0] == other._vecs[0] &&
                _vecs[1] == other._vecs[1] &&
                _vecs[2] == other._vecs[2] &&
                _vecs[3] == other._vecs[3];
    }

    friend std::ostream& operator << (std::ostream& os, const TMatrix4& mat4);

};


// aligned matrix struct with size of 4x4 float elements
// template with actual size 3x3 and 4x4
template<size_t size>
struct alignas(sizeof(__m512)) TMatrix {
    union {
        struct { float
            _m11, _m12, _m13, _m14,
            _m21, _m22, _m23, _m24,
            _m31, _m32, _m33, _m34,
            _m41, _m42, _m43, _m44;
        };
        __m128 _mm[SIZE];
        TVector<size> _vecs[SIZE];
    };

    TMatrix() {}
    explicit TMatrix(float m11, float m12, float m13,
                     float m21, float m22, float m23,
                     float m31, float m32, float m33)
        : _m11(m11), _m12(m12), _m13(m13), _m14(0.)
        , _m21(m21), _m22(m22), _m23(m23), _m14(0.)
        , _m31(m31), _m32(m32), _m33(m33), _m14(0.)
        , _m41(0.0), _m42(0.0), _m43(0.0), _m14(0.)
    {}
    explicit TMatrix(float m11, float m12, float m13, float m14,
                     float m21, float m22, float m23, float m24,
                     float m31, float m32, float m33, float m34,
                     float m41, float m42, float m43, float m44)
        : _m11(m11), _m12(m12), _m13(m13), _m14(m14)
        , _m21(m21), _m22(m22), _m23(m23), _m24(m24)
        , _m31(m31), _m32(m32), _m33(m33), _m34(m34)
        , _m41(m41), _m42(m42), _m43(m43), _m44(m44)
    {}

    operator __m128 const* () const { return _mm; }
	operator __m128* () { return _mm; }

    bool operator == (const TMatrix& other) const {
        for (size_t i = 0; i < size; ++i) {
            if (!(_vecs[i] == other._vecs[i])) {
                return false;
            }
        }
        return true;
    }

    friend std::ostream& operator << (std::ostream& os, const TMatrix<3>& mat);
    friend std::ostream& operator << (std::ostream& os, const TMatrix<4>& mat);

};

}
