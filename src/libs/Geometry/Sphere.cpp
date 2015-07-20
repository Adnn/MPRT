#include "Sphere.h"

using namespace MPRT;

const Material Surface::DEFAULT_MATERIAL(Rgb(0.1, 0.1, 0.1), Rgb(0.5, 0.5, 0.5), Rgb(0., 0., 0.));

Sphere::Sphere(const Vec3 &aCenter, const FLOAT_TYPE aRadius, const Material aMaterial) :
    Surface(aMaterial),
	mCenter(aCenter),
	mRadius(aRadius)
{
}

bool Sphere::hit(const HitParameters &aParams, HitRecord &aRecord) const
{
	Vec3 temp = aParams.ray.origin() - mCenter;

	FLOAT_TYPE a = aParams.ray.direction().dotP(aParams.ray.direction());
	FLOAT_TYPE b = 2 * aParams.ray.direction().dotP(temp);
	FLOAT_TYPE c = temp.dotP(temp) - mRadius*mRadius;

	FLOAT_TYPE discriminant = b*b - 4*a*c;

	// is there an intersection ?
	if (discriminant > 0.)
	{
		discriminant = ::sqrt(discriminant);

		// closest hit
		double t = (-b - discriminant) / (2*a);

		if(t < aParams.tMin) // push it to the second hit if first is too close
		{
			t = (-b + discriminant) / (2*a);
		}

		if(t < aParams.tMin || t > aParams.tMax)
		{
			return false;
		}

		aRecord.t = t;
        aRecord.hitSurface = this;
		return true;
	}

	return false;
}

Vec3 Sphere::getNormalAt(const Vec3 &aSurfacePoint) const
{
    return (aSurfacePoint-mCenter)/mRadius;
}