#ifndef MPRT_TRIANGLE
#define MPRT_TRIANGLE

#include "Surface.h"

namespace MPRT
{

class Geometry_Export Triangle : public Surface
{
public:
	Triangle(const Vec3 &aVertexA, const Vec3 &aVertexB, const Vec3 &aVertexC, const Rgb &aColor);

	virtual bool hit(const HitParameters &aParams, HitRecord &aRecord) const;

private:
	// The 3 triangle vertices
	Vec3 mA, mB, mC;
};

} // namespace

#endif