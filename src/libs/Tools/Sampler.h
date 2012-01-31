#ifndef MPRT_SAMPLER_
#define MPRT_SAMPLER_

#include "Tools_Export.h"

#include <vector>

namespace MPRT
{

class Vec2;

class Tools_Export Sampler
{
public:
   typedef std::vector<Vec2> Vec2Cont;
 //2D sampling
    void random (Vec2Cont &aSamples, Vec2Cont::size_type aNumSamples);
};

} //namespace

#endif //MPRT_SAMPLER_