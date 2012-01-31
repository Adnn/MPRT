#include <Tools/Image.h>

#include <fstream>

using namespace MPRT;

int main(int argc, char **argv)
{
	Image bgc(640, 480, Rgb(0., 0., 0.));
	for(unsigned int x=0;
		x<640;
		++x)
	{
		for(unsigned int y=0;
		y<480;
		++y)
		{
			Rgb pix(
				double(x)/640,
				double(y)/480,
				double(x+y)/(640)+480);

			bgc.setPixel(x, y, pix);
		}
	}
	std::ofstream outFile("d:/rt/background.ppm", std::ios_base::binary);
	bgc.writePPM(outFile);

	return 0;
}