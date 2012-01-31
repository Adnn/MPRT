#include "Sampler.h"

#include "Vec2.h"

using namespace MPRT;

void Sampler::random(Vec2Cont &aSamples, Vec2Cont::size_type aNumSamples)
{
    for(Vec2Cont::size_type currentSample = 0;
        currentSample < aNumSamples;
        ++currentSample)
    {
        aSamples.push_back(Vec2(normalRand(), normalRand()));
    }
}