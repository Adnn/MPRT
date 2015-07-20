#ifndef Scene_h__
#define Scene_h__

#include <Tools/Light.h>

#include <vector>
#include <memory>

namespace MPRT
{

typedef std::vector<std::shared_ptr<Light> > LightContainer;

class TracingTools_Export Scene
{
public:
    LightContainer mLights;
    SurfacePtr mSurfaces;
    Rgb mBackgroundColor;
};

}

#endif // Scene_h__
