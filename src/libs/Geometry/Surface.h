#ifndef MPRT_SURFACE
#define MPRT_SURFACE

#include "Ray.h"

#include <Tools/Vec3.h>
#include <Tools/Rgb.h>

#include <memory>

namespace MPRT
{

class Surface;

struct HitParameters
{
	Ray ray;
	FLOAT_TYPE tMin, tMax;
};

struct HitRecord
{
	FLOAT_TYPE t;
    const Surface *hitSurface;
};

typedef std::shared_ptr<Surface> SurfacePtr;

class Geometry_Export Surface
{
public:
    Surface(Rgb aColor = Rgb(.5, .5, .5)) :
      mColor(aColor)
    {}

	virtual ~Surface()
    {}

    inline const Rgb &getColor() const
    {
        return mColor;
    }

    inline void setColor(const Rgb &aColor)
    {
        mColor = aColor;
    }

	virtual bool hit(const HitParameters &aParams, HitRecord &aRecord) const=0;
	// Can be used for shadow hits (when we do not record what was hit)
//	virtual bool Hit(const HitParameters &aParams) const=0;

private:
    Rgb mColor;
};

} // namespace

#endif
