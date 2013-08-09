#ifndef MPRT_G
#define MPRT_G

#include "Tools_Export.h"

#include <cstdlib>
#include <cmath>

namespace MPRT
{

typedef double FLOAT_TYPE;

// TODO : rewrite with the greatness of C++11
inline FLOAT_TYPE Tools_Export normalRand()
{
    return FLOAT_TYPE(rand() / FLOAT_TYPE(RAND_MAX));
}

inline FLOAT_TYPE sqrtInt(unsigned int aValue)
{
    return ::sqrt(FLOAT_TYPE(aValue));
}

} // namespace

#endif