#include "Image.h"

using namespace MPRT;

const double Image::GAMMA(2.2);

Image::Image(unsigned int aXRes, unsigned int aYRes) :
	mXRes(aXRes),
	mYRes(aYRes),
    mImageBuffer(aXRes, std::vector<Rgb>(aYRes))
{
}

Image::Image(unsigned int aXRes, unsigned int aYRes, const Rgb &aBackgroundColor) :
	mXRes(aXRes),
	mYRes(aYRes),
	mImageBuffer(aXRes, std::vector<Rgb>(aYRes, aBackgroundColor))
{
}


void Image::writePPM(std::ostream &aDumpStream)
{
	aDumpStream << "P6\n" << mXRes << ' ' << mYRes << '\n' << "255\n";

	forEachPixel(Image::PixelWriterPPM(aDumpStream));
}

void Image::PixelWriterPPM::operator()(const Rgb &aPixel)
{
	static unsigned int iR, iG, iB;

	Rgb writtenPix(aPixel.correctGama(GAMMA));

	//const Rgb &writtenPix(aPixel);

	/// \todo : resolve warnings
	iR = writtenPix.r()*256;
	iR = iR>255 ? 255 : iR;

	iG = writtenPix.g()*256;
	iG = iG>255 ? 255 : iG;

	iB = writtenPix.b()*256;
	iB = iB>255 ? 255 : iB;

	mDumpStream << (unsigned char)iR << (unsigned char)iG << (unsigned char)iB;
}