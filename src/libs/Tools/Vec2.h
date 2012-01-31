#ifndef Vec2_h__
#define Vec2_h__

#include "mprt.h"

namespace MPRT
{

class Vec2
{
public:
    Vec2() :
      mElements()
    {
    }

    Vec2(FLOAT_TYPE aX, FLOAT_TYPE aY) :
        mElements()
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