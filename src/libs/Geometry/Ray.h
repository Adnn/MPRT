#ifndef MPRT_RAY
#define MPRT_RAY

#include "Geometry_Export.h"

#include <Tools/Vec3.h>

namespace MPRT
{

class Geometry_Export Ray
{
public :
	Ray(const Vec3 &aOrigin, const Vec3 &aDirection) :
		mOrigin(aOrigin),
		mDirection(aDirection)
	{
	}

    inline void setDirection(const Vec3 &aDirection)
    {
        mDirection = aDirection;
        mDirection.normalize();
    }

    inline void setOrigin(const Vec3 &aOrigin)
    {
        mOrigin = aOrigin;
    }

	inline const Vec3 &direction() const
	{
		return mDirection;
	}

	inline const Vec3 &origin() const
	{
		return mOrigin;
	}

	const Vec3 getPointAt(FLOAT_TYPE t) const
	{
		//todo : replace by type defined casting
		return (mOrigin+(t*mDirection));
	}

private:

	Vec3 mOrigin, mDirection;
};

} // namespace

#endif
