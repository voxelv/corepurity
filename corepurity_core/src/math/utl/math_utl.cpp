#include "math_utl.h"

namespace corepurity_core { namespace math {

    float to_radians(float degrees)
    {
        return degrees * ((float)M_PI / 180.0f);
    }

} }