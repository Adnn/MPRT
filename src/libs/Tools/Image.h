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

    /// \brief : Assign a pixel's color.
    /// The image frame origin is fixed in le lower left corner (to be consistent with screen space's coordinates).
    /// This is the opposite of the ppm file format (first given pixel is upper left corner).
	inline void setPixel(unsigned int aX, unsigned int aY, const Rgb &aPixelColor)
	{
		mImageBuffer[aX][mYRes-1-aY] = aPixelColor;
	}

	void writePPM(std::ostream &aDumpStream);

protected:

	template<class T_PixelFunctor>
	void forEachPixel(T_PixelFunctor aPitor)
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