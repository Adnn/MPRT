#ifndef MPRT_IMAGE
#define MPRT_IMAGE

#include "Tools_Export.h"

#include "Rgb.h"

#include <vector>
#include <iostream>

namespace MPRT
{

class Tools_Export Image
{
public:
	Image(unsigned int aXRes, unsigned int aYRes);
	Image(unsigned int aXRes, unsigned int aYRes, const Rgb &aBackgroundColor);

	inline void setPixel(unsigned int aX, unsigned int aY, const Rgb &aPixelColor)
	{
		mImageBuffer[aX][aY] = aPixelColor;
	}

	void writePPM(std::ostream &aDumpStream);

protected:

	template<class T_PixelFunctor>
	void forEachPixel(T_PixelFunctor &aPitor)
	{
		for(unsigned int yId=0;
			yId<mYRes;
			++yId)
		{
			for(unsigned int xId=0;
				xId<mXRes;
				++xId)
			{

				aPitor(mImageBuffer[xId][yId]);
			}
		}
	}

	class PixelWriterPPM
	{
	public :
		PixelWriterPPM(std::ostream &aDumpStream) :
			mDumpStream(aDumpStream)
		{
		}

		void operator()(const Rgb &aPixel);

	private:
		std::ostream &mDumpStream;
	};

private:
	unsigned int mXRes;
	unsigned int mYRes;
	std::vector< std::vector<Rgb> > mImageBuffer;

public:
	static const double GAMMA;
};

}

#endif