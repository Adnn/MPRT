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
    void random(Vec2Cont &aSamples);
    void nRooks(Vec2Cont &aSamples);
    void jitter(Vec2Cont &aSamples);
    void multiJitter(Vec2Cont &aSamples);
    void shuffle(Vec2Cont &aSamples);

	//filtering
	void boxFilter(Vec2Cont &aSamples);

private:
    inline Vec2Cont::size_type getSamplesCount(Vec2Cont &aSamples)
    {
        return aSamples.size();
    }

};

} //namespace

#endif //MPRT_SAMPLER_