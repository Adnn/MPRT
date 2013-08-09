#ifndef MPRT_AV3
#define MPRT_AV3

#include "Tools_Export.h"

#include "mprt.h"

namespace MPRT
{

template <class T>
inline const T operator*(const FLOAT_TYPE aScalar, const T &rhs)
{
	return T(aScalar*rhs.mElements[0], aScalar*rhs.mElements[1], aScalar*rhs.mElements[2]);
}

// Default initialization (i.e. zeroing) of elements in mElements is what we want, no need to tell us this is the invoked behavior
#pragma warning(disable : 4351)

template <class T_Derived>
class AbstractVec3
{
	friend const T_Derived operator* <> (const FLOAT_TYPE aScalar, const T_Derived &rhs);

public:

	AbstractVec3() :
	  mElements()
	{
	}

#pragma warning(default : 4351)

	AbstractVec3(FLOAT_TYPE aX, FLOAT_TYPE aY, FLOAT_TYPE aZ)/* :
		mElements() //Do not default initialize the elements just to overwrite the zeros with the arguments*/
	{
		mElements[0]=aX;
		mElements[1]=aY;
		mElements[2]=aZ;
	}

	inline const T_Derived operator+() const
	{
		return *static_cast<const T_Derived*>(this);
	}

	inline const T_Derived operator-() const
	{
		return T_Derived(-mElements[0], -mElements[1], -mElements[2]);
	}

	inline const T_Derived operator*(const FLOAT_TYPE aScalar) const
	{
		return T_Derived(aScalar*mElements[0], aScalar*mElements[1], aScalar*mElements[2]);
	}
	
	inline T_Derived &operator*=(const FLOAT_TYPE aScalar)
	{
		mElements[0]*=aScalar;
		mElements[1]*=aScalar;
		mElements[2]*=aScalar;
		return *static_cast<T_Derived*>(this);
	}

	inline const T_Derived operator/(const FLOAT_TYPE aScalar) const
	{
		return T_Derived(mElements[0]/aScalar, mElements[1]/aScalar, mElements[2]/aScalar);
	}

	inline T_Derived &operator/=(const FLOAT_TYPE aScalar)
	{
		mElements[0]/=aScalar;
		mElements[1]/=aScalar;
		mElements[2]/=aScalar;
		return *static_cast<T_Derived*>(this);
	}

	inline const T_Derived operator+(const T_Derived &rhs) const
	{
		return T_Derived(
			mElements[0]+rhs.mElements[0],
			mElements[1]+rhs.mElements[1],
			mElements[2]+rhs.mElements[2]);
	}

	inline T_Derived &operator+=(const T_Derived &rhs)
	{
		mElements[0]+=rhs.mElements[0];
		mElements[1]+=rhs.mElements[1];
		mElements[2]+=rhs.mElements[2];
		return *static_cast<T_Derived*>(this);
	}

	inline const T_Derived operator-(const T_Derived &rhs) const
	{
		return T_Derived(
			mElements[0]-rhs.mElements[0],
			mElements[1]-rhs.mElements[1],
			mElements[2]-rhs.mElements[2]);
	}

	inline T_Derived &operator-=(const T_Derived &rhs)
	{
		mElements[0]-=rhs.mElements[0];
		mElements[1]-=rhs.mElements[1];
		mElements[2]-=rhs.mElements[2];
		return *static_cast<T_Derived*>(this);
	}

protected:

	// componentwise mult
	inline const T_Derived operator*(const T_Derived &rhs) const
	{
		return T_Derived(
			mElements[0]*rhs.mElements[0],
			mElements[1]*rhs.mElements[1],
			mElements[2]*rhs.mElements[2]);
	}
	
	inline T_Derived &operator*=(const T_Derived &rhs)
	{
		mElements[0]*=rhs.mElements[0];
		mElements[1]*=rhs.mElements[1];
		mElements[2]*=rhs.mElements[2];

		return *static_cast<T_Derived*>(this);
	}

	// division
	inline const T_Derived operator/(const T_Derived &rhs) const
	{
		return T_Derived(
			mElements[0]/rhs.mElements[0],
			mElements[1]/rhs.mElements[1],
			mElements[2]/rhs.mElements[2]);
	}

	inline T_Derived &operator/=(const T_Derived &rhs)
	{
		mElements[0]/=rhs.mElements[0];
		mElements[1]/=rhs.mElements[1];
		mElements[2]/=rhs.mElements[2];

        return *static_cast<T_Derived*>(this);
	}

	FLOAT_TYPE mElements[3];
};

} // namespace

#endif