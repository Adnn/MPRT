#ifndef MPRT_AV3
#define MPRT_AV3

#include "Tools_Export.h"

#include "mprt.h"

namespace MPRT
{

class Tools_Export AbstractVec3
{
public:
	AbstractVec3() :
	  mElements()
	{
	}

	AbstractVec3(FLOAT_TYPE aX, FLOAT_TYPE aY, FLOAT_TYPE aZ) :
		mElements()
	{
		mElements[0]=aX;
		mElements[1]=aY;
		mElements[2]=aZ;
	}

	inline const AbstractVec3 operator+() const
	{
		return AbstractVec3(mElements[0], mElements[1], mElements[2]);
	}

	inline const AbstractVec3 operator-() const
	{
		return AbstractVec3(-mElements[0], -mElements[1], -mElements[2]);
	}

    template <class T>
	inline const T operator*(const FLOAT_TYPE aScalar) const
	{
		return T(aScalar*mElements[0], aScalar*mElements[1], aScalar*mElements[2]);
	}
	
	inline AbstractVec3 &operator*=(const FLOAT_TYPE aScalar)
	{
		mElements[0]*=aScalar;
		mElements[1]*=aScalar;
		mElements[2]*=aScalar;
		return *this;
	}

	inline const AbstractVec3 operator/(const FLOAT_TYPE aScalar) const
	{
		return AbstractVec3(mElements[0]/aScalar, mElements[1]/aScalar, mElements[2]/aScalar);
	}

	inline AbstractVec3 &operator/=(const FLOAT_TYPE aScalar)
	{
		mElements[0]/=aScalar;
		mElements[1]/=aScalar;
		mElements[2]/=aScalar;
		return *this;
	}

	template <class T>
    friend inline const T operator*(const FLOAT_TYPE aScalar, const T &rhs);

    template <class T>
	inline const T operator+(const T &rhs) const
	{
		return T(
			mElements[0]+rhs.mElements[0],
			mElements[1]+rhs.mElements[1],
			mElements[2]+rhs.mElements[2]);
	}

	inline AbstractVec3 &operator+=(const AbstractVec3 &rhs)
	{
		mElements[0]+=rhs.mElements[0];
		mElements[1]+=rhs.mElements[1];
		mElements[2]+=rhs.mElements[2];
		return *this;
	}

    template <class T>
	inline const T operator-(const T &rhs) const
	{
		return T(
			mElements[0]-rhs.mElements[0],
			mElements[1]-rhs.mElements[1],
			mElements[2]-rhs.mElements[2]);
	}

	inline AbstractVec3 &operator-=(const AbstractVec3 &rhs)
	{
		mElements[0]-=rhs.mElements[0];
		mElements[1]-=rhs.mElements[1];
		mElements[2]-=rhs.mElements[2];
		return *this;
	}

protected:

	// componentwise mult
	inline const AbstractVec3 operator*(const AbstractVec3 &rhs) const
	{
		return AbstractVec3(
			mElements[0]*rhs.mElements[0],
			mElements[1]*rhs.mElements[1],
			mElements[2]*rhs.mElements[2]);
	}
	
	inline AbstractVec3 &operator*=(const AbstractVec3 &rhs)
	{
		mElements[0]*=rhs.mElements[0];
		mElements[1]*=rhs.mElements[1];
		mElements[2]*=rhs.mElements[2];

		return *this;
	}

	// division
	inline const AbstractVec3 operator/(const AbstractVec3 &rhs) const
	{
		return AbstractVec3(
			mElements[0]/rhs.mElements[0],
			mElements[1]/rhs.mElements[1],
			mElements[2]/rhs.mElements[2]);
	}

	inline AbstractVec3 &operator/=(const AbstractVec3 &rhs)
	{
		mElements[0]/=rhs.mElements[0];
		mElements[1]/=rhs.mElements[1];
		mElements[2]/=rhs.mElements[2];

        return *this;
	}

	FLOAT_TYPE mElements[3];
};

template <class T>
inline const T operator*(const FLOAT_TYPE aScalar, const T &rhs)
{
	return T(aScalar*rhs.mElements[0], aScalar*rhs.mElements[1], aScalar*rhs.mElements[2]);
}

} // namespace

#endif