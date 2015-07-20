#ifndef MPRT_SPHERE
#define MPRT_SPHERE

#include "Surface.h"

#include <Tools/Rgb.h>

namespace MPRT
{

class Geometry_Export Sphere : public Surface
{
public:
	Sphere(const Vec3 &aCenter, const FLOAT_TYPE aRadius, const Material aMaterial);

	virtual bool hit(const HitParameters &aParams, HitRecord &aRecord) const;
    Vec3 getNormalAt(const Vec3 &aSurfacePoint) const;

private:
	Vec3 mCenter;
	FLOAT_TYPE mRadius;
	Rgb mColor;
};

} // namespace

#endif