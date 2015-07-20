#ifndef MPRT_SURFACE
#define MPRT_SURFACE

#include "Ray.h"

#include <Tools/Material.h>
#include <Tools/Rgb.h>
#include <Tools/Vec3.h>

#include <memory>

namespace MPRT
{

class Surface;

struct HitParameters
{
    HitParameters(const Ray aRay, const FLOAT_TYPE atMin, const FLOAT_TYPE atMax) :
        ray(aRay),
        tMin(atMin),
        tMax(atMax)
    {
    }

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
    Surface(Material aMaterial = DEFAULT_MATERIAL) :
        mMaterial(aMaterial)
    {}

	virtual ~Surface()
    {}

    inline const Material &getMaterial() const
    {
        return mMaterial;
    }

    inline void setMaterial(Material aMaterial)
    {
        mMaterial = aMaterial;
    }

	virtual bool hit(const HitParameters &aParams, HitRecord &aRecord) const=0;
	// Can be used for shadow hits (when we do not record what was hit)
//	virtual bool Hit(const HitParameters &aParams) const=0;

    /// \brief Returns the normal to the surface at the given point.
    /// The method does not make any verification that the given point is actually on the surface.
    virtual Vec3 getNormalAt(const Vec3 &aSurfacePoint) const=0;

private:
    Material mMaterial;

public:
    static const Material DEFAULT_MATERIAL;
};

} // namespace

#endif
