#ifndef Vec2_h__
#define Vec2_h__

#include "mprt.h"

namespace MPRT
{

// Default initialization (i.e. zeroing) of elements in mElements is what we want, no need to tell us this is the invoked behavior
#pragma warning(disable : 4351)

class Vec2
{
public:
    Vec2() :
      mElements()
    {
    }

#pragma warning(default : 4351)

    Vec2(FLOAT_TYPE aX, FLOAT_TYPE aY)
    {
        mElements[0]=aX;
        mElements[1]=aY;
    }

    inline const Vec2 operator+() const
    {
        return Vec2(mElements[0], mElements[1]);
    }

    inline const Vec2 operator-() const
    {
        return Vec2(-mElements[0], -mElements[1]);
    }

    inline const Vec2 operator*(const FLOAT_TYPE aScalar) const
    {
        return Vec2(aScalar*mElements[0], aScalar*mElements[1]);
    }

    inline Vec2 &operator*=(const FLOAT_TYPE aScalar)
    {
        mElements[0]*=aScalar;
        mElements[1]*=aScalar;
        return *this;
    }

    friend inline const Vec2 operator*(const FLOAT_TYPE aScalar, const Vec2 &rhs);

    inline const Vec2 operator/(const FLOAT_TYPE aScalar) const
    {
        return Vec2(mElements[0]/aScalar, mElements[1]/aScalar);
    }

    inline Vec2 &operator/=(const FLOAT_TYPE aScalar)
    {
        mElements[0]/=aScalar;
        mElements[1]/=aScalar;
        return *this;
    }

    inline const Vec2 operator+(const Vec2 &rhs) const
    {
        return Vec2(
            mElements[0]+rhs.mElements[0],
            mElements[1]+rhs.mElements[1]);
    }

    inline Vec2 &operator+=(const Vec2 &rhs)
    {
        mElements[0]+=rhs.mElements[0];
        mElements[1]+=rhs.mElements[1];
        return *this;
    }

    inline const Vec2 operator-(const Vec2 &rhs) const
    {
        return Vec2(
            mElements[0]-rhs.mElements[0],
            mElements[1]-rhs.mElements[1]);
    }

    inline Vec2 &operator-=(const Vec2 &rhs)
    {
        mElements[0]-=rhs.mElements[0];
        mElements[1]-=rhs.mElements[1];
        return *this;
    }

	inline const FLOAT_TYPE &x() const
	{
		return mElements[0];
	}

	inline const FLOAT_TYPE &y() const
	{
		return mElements[1];
	}

	inline FLOAT_TYPE &x()
	{
		return mElements[0];
	}

	inline FLOAT_TYPE &y()
	{
		return mElements[1];
	}



protected:
    // componentwise mult
//     inline const Vec2 operator*(const Vec2 &rhs) const
//     {
//         return Vec2(
//             mElements[0]*rhs.mElements[0],
//             mElements[1]*rhs.mElements[1]);
//     }
// 
//     inline Vec2 &operator*=(const Vec2 &rhs)
//     {
//         mElements[0]*=rhs.mElements[0];
//         mElements[1]*=rhs.mElements[1];
// 
//         return *this;
//     }

    // division
//     inline const Vec2 operator/(const Vec2 &rhs) const
//     {
//         return Vec2(
//             mElements[0]/rhs.mElements[0],
//             mElements[1]/rhs.mElements[1]);
//     }
// 
//     inline Vec2 &operator/=(const Vec2 &rhs)
//     {
//         mElements[0]/=rhs.mElements[0];
//         mElements[1]/=rhs.mElements[1];
// 
//         return *this;
//     }

    FLOAT_TYPE mElements[2];
};

inline const Vec2 operator*(const FLOAT_TYPE aScalar, const Vec2 &rhs)
{
    return Vec2(aScalar*rhs.mElements[0], aScalar*rhs.mElements[1]);
}

} //namespace
#endif // Vec2_h__