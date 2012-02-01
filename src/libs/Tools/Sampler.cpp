#include "Sampler.h"

#include "Vec2.h"

#include <cmath>

using namespace MPRT;

void Sampler::random(Vec2Cont &aSamples)
{
    for(Vec2Cont::size_type currentSample = 0;
		currentSample < getSamplesCount(aSamples);
        ++currentSample)
    {
		aSamples[currentSample].x() = normalRand();
		aSamples[currentSample].y() = normalRand();
    }
}

void Sampler::nRooks(Vec2Cont &aSamples)
{
    Vec2Cont::size_type totalSamples(getSamplesCount(aSamples));

    for(Vec2Cont::size_type currentSample = 0;
        currentSample < totalSamples;
        ++currentSample)
    {
        aSamples[currentSample].x() = (currentSample + normalRand()) / totalSamples;
        aSamples[currentSample].y() = (currentSample + normalRand()) / totalSamples;
    }

    //shuffle X coords.
    // TODO : I feel there is a correlation between target and currentSample...
    for(Vec2Cont::size_type currentSample = totalSamples-2;
        currentSample >= 0;
        --currentSample)
    {
        Vec2Cont::size_type target(normalRand() * currentSample);

        FLOAT_TYPE tmpX = aSamples[currentSample+1].x();
        aSamples[currentSample+1].x() = aSamples[target].x();
        aSamples[target].x() = tmpX;
    }
}

void Sampler::jitter(Vec2Cont &aSamples)
{
    Vec2Cont::size_type sqrtSamples = sqrt(getSamplesCount(aSamples));
    Vec2Cont::size_type currentSample = 0;

    for(Vec2Cont::size_type xArea=0;
        xArea < sqrtSamples;
        ++xArea)
    {
        for(Vec2Cont::size_type yArea=0;
            yArea < sqrtSamples;
            ++yArea)
        {
            currentSample = xArea*sqrtSamples + yArea;
            //knowing that normal rand returns a floating value, and that all other types are integral
            // no casting is actually required.
            aSamples[currentSample].x() = (xArea+normalRand()) / FLOAT_TYPE(sqrtSamples);
            aSamples[currentSample].y() = (yArea+normalRand()) / FLOAT_TYPE(sqrtSamples);
        }
    }
}

void Sampler::multiJitter(Vec2Cont &aSamples)
{
    Vec2Cont::size_type totalSamples(getSamplesCount(aSamples));
    Vec2Cont::size_type sqrtSamples = sqrt(totalSamples);
    FLOAT_TYPE subcellWidth = static_cast<FLOAT_TYPE>(1) / totalSamples;
    Vec2Cont::size_type currentSample = 0;

    for(Vec2Cont::size_type xArea=0;
        xArea < sqrtSamples;
        ++xArea)
    {
        for(Vec2Cont::size_type yArea=0;
            yArea < sqrtSamples;
            ++yArea)
        {
            currentSample = xArea*sqrtSamples + yArea;

            aSamples[currentSample].x() =
                xArea/FLOAT_TYPE(sqrtSamples)
                + (yArea+normalRand()) * subcellWidth;
            aSamples[currentSample].y() =
                yArea/FLOAT_TYPE(sqrtSamples)
                + (xArea+normalRand()) * subcellWidth;
        }
    }

    // Shuffle x coords within each column (a xArea width) and y within each row.
    for(Vec2Cont::size_type xArea=0;
        xArea < sqrtSamples;
        ++xArea)
    {
        for(Vec2Cont::size_type yArea=0;
            yArea < sqrtSamples;
            ++yArea)
        {
            Vec2Cont::size_type target = yArea + Vec2Cont::size_type(normalRand() * (sqrtSamples-yArea-1));
            FLOAT_TYPE tmpVal = aSamples[xArea*sqrtSamples + yArea].x();
            aSamples[xArea*sqrtSamples + yArea].x() = aSamples[xArea*sqrtSamples + target].x();
            aSamples[xArea*sqrtSamples + target].x() = tmpVal;

            target = yArea + Vec2Cont::size_type(normalRand() * (sqrtSamples-yArea-1));
            tmpVal = aSamples[yArea*sqrtSamples + xArea].y();
            aSamples[yArea*sqrtSamples + xArea].y() = aSamples[target*sqrtSamples + xArea].y();
            aSamples[target*sqrtSamples + xArea].y() = tmpVal;
        }
    }

}

void Sampler::shuffle(Vec2Cont &aSamples)
{
    for(Vec2Cont::size_type currentSample = getSamplesCount(aSamples)-2;
        currentSample >= 0;
        --currentSample)
    {
        Vec2Cont::size_type target(normalRand() * currentSample);

        Vec2 tmpVec2 = aSamples[currentSample+1];
        aSamples[currentSample+1] = aSamples[target];
        aSamples[target] = tmpVec2;
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
