#ifndef Camera_h__
#define Camera_h__

#include <Tools/Frame.h>
#include <Tools/Rgb.h>
#include <Geometry/Surface.h>

#include "TracingTools_Export.h"

namespace MPRT
{

class Image;
class Scene;

enum ProjectionType
{
    ORTHGRAPHIC,
    PERSPECTIVE
};

struct TracingTools_Export CameraIntrinsics
{
    FLOAT_TYPE focalDistance;
    FLOAT_TYPE farPlane;
    
    FLOAT_TYPE right, top;
    ProjectionType projection;
};
class TracingTools_Export Camera
{
public:
    Camera(CameraIntrinsics aIntrinsics, const Vec3 aEyePosition, const Vec3 &aViewDirection, const Vec3 &aUpDirection=Vec3(0., 1., 0.));
    

    Image render(const unsigned int width, const unsigned int height, const Scene &aSceneToRender, const Rgb &aBackground, const unsigned int aSampleCount);

protected:
    const HitParameters generateHitParameters(FLOAT_TYPE pixelU, FLOAT_TYPE pixelV) const;
    const Rgb getRayColor(const HitParameters &hitParam, HitRecord &hitRecord, HitRecord &dummyRecord, const Scene &aSceneToRender, unsigned int aRecursionDepth = 0);

private:
    CameraIntrinsics mIntrinsics;
    Frame mFrame;
    static const unsigned int DEPTH_LIMIT;
};

} //namespace
#endif // Camera_h__
