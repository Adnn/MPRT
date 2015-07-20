#ifndef Frame_h__
#define Frame_h__

#include "Vec3.h"
#include "OrthonormalBasis.h"

#include "Tools_Export.h"

namespace MPRT
{
    
class Tools_Export Frame
{
public:
    Frame(Vec3 aOrigin, OrthonormalBasis aBasis);
    
    inline const Vec3 &getOrigin() const
    {
        return mOrigin;
    }

    inline const OrthonormalBasis &getBasis() const
    {
        return mBasis;
    }

private:
    Vec3 mOrigin;
    OrthonormalBasis mBasis;
};

} //namespace
    
#endif // Frame_h__
