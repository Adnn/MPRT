#ifndef MPRT_GROUP_
#define MPRT_GROUP_

#include "Surface.h"

#include <vector>

namespace MPRT
{

class Geometry_Export Group : public Surface
{
public:

    bool hit(const HitParameters &aParams, HitRecord &aRecord) const override;
    /// \todo Returns a dummy null vector atm
    Vec3 getNormalAt(const Vec3 &aSurfacePoint) const override;
    
    void addChild(SurfacePtr aChild);

private:
    std::vector<SurfacePtr> mChildren;
};

} // namespace

#endif //MPRT_GROUP_
