#include <Geometry/Sphere.h>
#include <Geometry/Triangle.h>
#include <Geometry/Group.h>
#include <Tools/Image.h>
#include <Tools/Sampler.h>
#include <Tools/Rgb.h>
#include <Tools/Vec2.h>

#include <fstream>

using namespace MPRT;

#define WIDTH 500
#define HEIGHT 500

#define SAMPLES 256

int main()
{

    SurfacePtr sphere = std::make_shared<Sphere>(Vec3(250., 250., -1000.), 150., Rgb(0., 0., 1.));
    SurfacePtr triangle = std::make_shared<Triangle>(
        Vec3(300., 600., -800.),
        Vec3(0., 100., -1000.),
        Vec3(450., 20., -1000.),
        Rgb(1., 0., 0.) );

    std::shared_ptr<Group> group = std::make_shared<Group>();
    group->addChild(sphere);
    group->addChild(triangle);
    
    Image image(WIDTH, HEIGHT, Rgb(.3, .3, .3));

    HitParameters hitParams = { Ray(Vec3(0., 0., 0.), Vec3(0., 0., -1.)), 0., 2000.};

    HitRecord record;

	Sampler sampler;
	Sampler::Vec2Cont origins;
	origins.resize(SAMPLES);

	Rgb tmpPixel(0., 0., 0.);

    for(unsigned int y(0);
        y<HEIGHT;
        ++y)
    {
        for(unsigned int x(0);
            x<WIDTH;
            ++x)
        {
			sampler.random(origins);
			sampler.boxFilter(origins);

			for(unsigned int sampleId = 0;
				sampleId < SAMPLES;
				++sampleId)
			{
				hitParams.ray.setOrigin(
					Vec3(x+origins[sampleId].x(),
						 y+origins[sampleId].y(),
						 0));
				if (group->hit(hitParams, record))
				{
					tmpPixel += record.hitSurface->getColor();
				}
			}

			tmpPixel.AbstractVec3::operator/=(FLOAT_TYPE(SAMPLES));
			// Transformation from right handed coordinates to image coordinates
			image.setPixel(x, (HEIGHT-1-y), tmpPixel);
        }
    }

    std::ofstream outFile("D:/RayTraced/256Samples.ppm", std::ios_base::binary);
	image.writePPM(outFile);

    return 0;
}