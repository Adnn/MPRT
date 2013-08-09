#ifndef MPRT_VEC3
#define MPRT_VEC3

#include "Tools_Export.h"

#include "AbstractVec3.h"

#include <cmath>
namespace MPRT
{

class Vec3 : public AbstractVec3<Vec3>
{
public:
	Vec3() :
		AbstractVec3()
	{
	}

	Vec3(FLOAT_TYPE aX, FLOAT_TYPE aY, FLOAT_TYPE aZ) :
		AbstractVec3(aX, aY, aZ)
	{
	}

	inline FLOAT_TYPE length()
	{
		return sqrt(length2());
	}

	inline FLOAT_TYPE length2()
	{
		return 
			mElements[0]*mElements[0] +
			mElements[1]*mElements[1] +
			mElements[2]*mElements[2];
	}

	inline Vec3 &normalize()
	{
		AbstractVec3::operator/=(length());
		return *this;
	}

	// Cross product
	inline const Vec3 crossP(const Vec3 &rhs) const
	{
		return Vec3(
			mElements[1]*rhs.mElements[2]-mElements[2]*rhs.mElements[1],
			mElements[2]*rhs.mElements[0]-mElements[0]*rhs.mElements[2],
			mElements[0]*rhs.mElements[1]-mElements[1]*rhs.mElements[0]);
	}

	// dot product
	inline const FLOAT_TYPE dotP(const Vec3 &rhs) const
	{
		return 
			mElements[0]*rhs.mElements[0] +
			mElements[1]*rhs.mElements[1] +
			mElements[2]*rhs.mElements[2];
	}

	inline const FLOAT_TYPE &x() const
	{
		return mElements[0];
	};

	inline const FLOAT_TYPE &y() const
	{
		return mElements[1];
	};

	inline const FLOAT_TYPE &z() const
	{
		return mElements[2];
	};
};

} // namespace

#endif