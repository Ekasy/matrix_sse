#include "matrix.h"


namespace NMatrixLib {

std::ostream& operator << (std::ostream& os, const TMatrix4& mat4) {
    return os << std::setiosflags(std::ios_base::showpoint|std::ios_base::fixed) << std::setprecision(3) <<
        "| " << mat4._m11 << " , " << mat4._m12 << " , " << mat4._m13 << " , " << mat4._m14 << " |" << std::endl <<
        "| " << mat4._m21 << " , " << mat4._m22 << " , " << mat4._m23 << " , " << mat4._m24 << " |" << std::endl <<
        "| " << mat4._m31 << " , " << mat4._m32 << " , " << mat4._m33 << " , " << mat4._m34 << " |" << std::endl <<
        "| " << mat4._m41 << " , " << mat4._m42 << " , " << mat4._m43 << " , " << mat4._m44 << " |";
}


std::ostream& operator << (std::ostream& os, const TMatrix<3>& mat) {
    return os << std::setiosflags(std::ios_base::showpoint|std::ios_base::fixed) << std::setprecision(3) <<
        "| " << mat._m11 << " , " << mat._m12 << " , " << mat._m13 << " |" << std::endl <<
        "| " << mat._m21 << " , " << mat._m22 << " , " << mat._m23 << " |" << std::endl <<
        "| " << mat._m31 << " , " << mat._m32 << " , " << mat._m33 << " |";
}


std::ostream& operator << (std::ostream& os, const TMatrix<4>& mat) {
    return os << std::setiosflags(std::ios_base::showpoint|std::ios_base::fixed) << std::setprecision(3) <<
        "| " << mat._m11 << " , " << mat._m12 << " , " << mat._m13 << " , " << mat._m14 << " |" << std::endl <<
        "| " << mat._m21 << " , " << mat._m22 << " , " << mat._m23 << " , " << mat._m24 << " |" << std::endl <<
        "| " << mat._m31 << " , " << mat._m32 << " , " << mat._m33 << " , " << mat._m34 << " |" << std::endl <<
        "| " << mat._m41 << " , " << mat._m42 << " , " << mat._m43 << " , " << mat._m44 << " |";
}

}
