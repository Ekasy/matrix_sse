#include "operations.h"


namespace NMatrixLib {

void MultiplySSE(const TMatrix<3>& lhs, const TVector<3>& rhs, TVector<3>& result) {
    result._mm = _mm_hadd_ps(
        _mm_hadd_ps(
            _mm_mul_ps(lhs._mm[0], rhs._mm),
            _mm_mul_ps(lhs._mm[1], rhs._mm)
        ),
        _mm_hadd_ps(
            _mm_mul_ps(lhs._mm[2], rhs._mm),
            _mm_setzero_ps()  // OMG WTF??
        )
    );
}


void MultiplySSE(const TMatrix<4>& lhs, const TVector<4>& rhs, TVector<4>& result) {
    result._mm = _mm_hadd_ps(
        _mm_hadd_ps(
            _mm_mul_ps(lhs._mm[0], rhs._mm),
            _mm_mul_ps(lhs._mm[1], rhs._mm)
        ),
        _mm_hadd_ps(
            _mm_mul_ps(lhs._mm[2], rhs._mm),
            _mm_mul_ps(lhs._mm[3], rhs._mm)
        )
    );
}


void MultiplySSE(const TMatrix<3>& lhs, const TMatrix<3>& rhs, TMatrix<3>& result) {
    result._mm[0] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(2, 2, 2, 2)))
    );

    result._mm[1] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(2, 2, 2, 2)))
    );

    result._mm[2] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(2, 2, 2, 2)))
    );
}


void MultiplySSE(const TMatrix<4>& lhs, const TMatrix<4>& rhs, TMatrix<4>& result) {
    result._mm[0] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(2, 2, 2, 2))),
            _mm_mul_ps(lhs._mm[3], _mm_shuffle_ps(rhs._mm[0], rhs._mm[0], _MM_SHUFFLE(3, 3, 3, 3)))
        )
    );

    result._mm[1] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(2, 2, 2, 2))),
            _mm_mul_ps(lhs._mm[3], _mm_shuffle_ps(rhs._mm[1], rhs._mm[1], _MM_SHUFFLE(3, 3, 3, 3)))
        )
    );

    result._mm[2] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(2, 2, 2, 2))),
            _mm_mul_ps(lhs._mm[3], _mm_shuffle_ps(rhs._mm[2], rhs._mm[2], _MM_SHUFFLE(3, 3, 3, 3)))
        )
    );

    result._mm[3] = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[0], _mm_shuffle_ps(rhs._mm[3], rhs._mm[3], _MM_SHUFFLE(0, 0, 0, 0))),
            _mm_mul_ps(lhs._mm[1], _mm_shuffle_ps(rhs._mm[3], rhs._mm[3], _MM_SHUFFLE(1, 1, 1, 1)))
        ),
        _mm_add_ps(
            _mm_mul_ps(lhs._mm[2], _mm_shuffle_ps(rhs._mm[3], rhs._mm[3], _MM_SHUFFLE(2, 2, 2, 2))),
            _mm_mul_ps(lhs._mm[3], _mm_shuffle_ps(rhs._mm[3], rhs._mm[3], _MM_SHUFFLE(3, 3, 3, 3)))
        )
    );
}

}
