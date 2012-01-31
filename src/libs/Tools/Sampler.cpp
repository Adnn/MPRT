#include "Sampler.h"

#include "Vec2.h"

using namespace MPRT;

void Sampler::random(Vec2Cont &aSamples)
{
    for(Vec2Cont::size_type currentSample = 0;
		currentSample < aSamples.capacity();
        ++currentSample)
    {
		aSamples[currentSample].x() = normalRand();
		aSamples[currentSample].y() = normalRand();
    }
}

void Sampler::boxFilter(Vec2Cont &aSamples)
{
	for(Vec2Cont::size_type currentSample = 0;
		currentSample < aSamples.capacity();
        ++currentSample)
    {
		aSamples[currentSample].x() -= .5;
		aSamples[currentSample].y() -= .5;
    }
}
