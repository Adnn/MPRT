#ifndef MPRT_G
#define MPRT_G

#include "Tools_Export.h"

#include <cstdlib>

namespace MPRT
{

typedef double FLOAT_TYPE;

// TODO : rewrite with the greatness of C++11
inline FLOAT_TYPE Tools_Export normalRand()
{
    return FLOAT_TYPE(rand() / FLOAT_TYPE(RAND_MAX));
}

} // namespace

#endif