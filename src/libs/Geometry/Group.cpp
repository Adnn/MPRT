#include "Group.h"

using namespace MPRT;

bool Group::hit(const HitParameters &aParams, HitRecord &aRecord) const
{
    bool hit(false);
    HitParameters shorteningParams(aParams);

    for (auto surface = begin(mChildren);
        surface != end(mChildren);
        ++surface)
    {
        if ((*surface)->hit(shorteningParams, aRecord))
        {
            shorteningParams.tMax = aRecord.t;
            hit=true;
        }
    }

    return hit;
}

void Group::addChild(SurfacePtr aChild)
{
    mChildren.push_back(aChild);
}
