#ifndef Light_h__
#define Light_h__

#include "Material.h"
#include "Vec3.h"

#include "Tools_Export.h"

namespace MPRT
{

class Tools_Export Light
{
public:
    Light(const Material aMaterial) :
        mMaterial(aMaterial)
    {
        
    }

    virtual const Vec3 getDirection(const Vec3 &aShadedPoint) const=0;
    virtual const FLOAT_TYPE getDistance(const Vec3 &aShadedPoint) const=0;

    inline const Material &getMaterial() const
    {
        return mMaterial;
    }

private:
    Material mMaterial;
};

class Tools_Export PointLight : public Light
{
public:
    PointLight(const Vec3 aPosition, const Material aMaterial) :
        Light(aMaterial),
        mPosition(aPosition)
    {

    }

    inline const Vec3 getDirection(const Vec3 &aShadedPoint) const
    {
        Vec3 direction(mPosition-aShadedPoint);
        return direction.normalize();
    }

    const FLOAT_TYPE getDistance(const Vec3 &aShadedPoint) const
    {
        return (mPosition-aShadedPoint).length();
    }

private:
    Vec3 mPosition;
};
}

#endif // Light_h__
