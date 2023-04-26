#include "vector.h"


namespace NMatrixLib {

std::ostream& operator << (std::ostream& os, const TVector4& vec4) {
    return os << std::setprecision(3) << '(' << vec4._v1 << ", " << vec4._v2 << ", " << vec4._v3 << ", " << vec4._v4 << ')';
}


std::ostream& operator << (std::ostream& os, const TVector<4>& vec) {
    return os << std::setprecision(3) << '(' << vec._v1 << ", " << vec._v2 << ", " << vec._v3 << ", " << vec._v4 << ')';
}


std::ostream& operator << (std::ostream& os, const TVector<3>& vec) {
    return os << std::setprecision(3) << '(' << vec._v1 << ", " << vec._v2 << ", " << vec._v3 << ')';
}

}
