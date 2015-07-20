#include "Camera.h"

#include "Scene.h"

#include <Tools/Image.h> 
#include <Tools/Light.h>
#include <Tools/Sampler.h>
#include <Tools/Vec2.h>

#include <memory>

using namespace MPRT;

const unsigned int Camera::DEPTH_LIMIT(1);

Camera::Camera(CameraIntrinsics aIntrinsics, const Vec3 aEyePosition, const Vec3 &aViewDirection, const Vec3 &aUpDirection) :
    mIntrinsics(aIntrinsics),
    mFrame(aEyePosition, OrthonormalBasis(-aViewDirection, aUpDirection))
{
}
    
Image Camera::render(const unsigned int aHorizontalResolution, const unsigned int aVerticalResolution, const Scene &aSceneToRender, const Rgb &aBackground, const unsigned int aSampleCount)
{
    
    Image image(aHorizontalResolution, aVerticalResolution, aBackground);
    HitRecord hitRecord, dummyRecord;

    LightContainer lights = aSceneToRender.mLights;
    //if (lights.empty())
    //{
    //    lights.push_back(std::make_shared<PointLight>(Vec3(0., 0., 0.), Material(Rgb::WHITE, Rgb::BLACK, Rgb::BLACK)));
    //}

    for(unsigned int y(0);
        y<aVerticalResolution;
        ++y)
    {
        for(unsigned int x(0);
            x<aHorizontalResolution;
            ++x)
        {
        	Sampler sampler;
        	Sampler::Vec2Cont origins;
        	origins.resize(aSampleCount);
            sampler.jitter(origins);
            sampler.boxFilter(origins);

            Rgb pixelColor(Rgb::BLACK);
            for(Sampler::Vec2Cont::const_iterator originIt = origins.begin();
                originIt != origins.end();
                ++originIt)
            {
                /// \note : if it was not for sampling, the pixel V calculation should be before the x loop (since pixelV stays constant if only the middle sample is taken)
                FLOAT_TYPE pixelV = -mIntrinsics.top + 2*mIntrinsics.top*(y+originIt->y()+0.5)/aVerticalResolution;
                FLOAT_TYPE pixelU = -mIntrinsics.right + 2*mIntrinsics.right*(x+originIt->x()+.5)/aHorizontalResolution;

                HitParameters hitParam = generateHitParameters(pixelU, pixelV);

                if (aSceneToRender.mSurfaces->hit(hitParam, hitRecord))
                {
                    if(lights.empty())
                    {
                        pixelColor += hitRecord.hitSurface->getMaterial().ambientColor;
                    }
                    else
                    {
                        pixelColor += getRayColor(hitParam, hitRecord, dummyRecord, aSceneToRender);
                    }
                }
                else
                {
                    pixelColor += aSceneToRender.mBackgroundColor;
                }
            }

            image.setPixel(x, y, pixelColor/aSampleCount);
        }
    }

    return image;
}

const HitParameters Camera::generateHitParameters(FLOAT_TYPE pixelU, FLOAT_TYPE pixelV) const
{
    switch (mIntrinsics.projection)
    {
    case ORTHGRAPHIC:
        {
            return HitParameters (
                    Ray(mFrame.getOrigin()+pixelU*mFrame.getBasis().mU+pixelV*mFrame.getBasis().mV, -mFrame.getBasis().mW),
                    0.,
                    mIntrinsics.farPlane);
            break;
        }

    case PERSPECTIVE:
        {
            return HitParameters (
                    Ray(mFrame.getOrigin(), -mIntrinsics.focalDistance*mFrame.getBasis().mW+pixelU*mFrame.getBasis().mU+pixelV*mFrame.getBasis().mV),
                    0.,
                    mIntrinsics.farPlane);
            break;
        }
    }
}

const Rgb Camera::getRayColor(const HitParameters &hitParam, HitRecord &hitRecord, HitRecord &dummyRecord, const Scene &aSceneToRender, unsigned int aRecursionDepth)
{
    
    const Material &hitMaterial(hitRecord.hitSurface->getMaterial());
    const Vec3 hitPoint = hitParam.ray.getPointAt(hitRecord.t);
    const Vec3 hitNormal = hitRecord.hitSurface->getNormalAt(hitPoint);

    Rgb pixelColor(Rgb::BLACK);

    for(LightContainer::const_iterator lightIt = aSceneToRender.mLights.begin();
        lightIt != aSceneToRender.mLights.end();
        ++lightIt)
    {
        Vec3 lightDir = (*lightIt)->getDirection(hitPoint);
        Vec3 halfVector = lightDir - normalize(hitParam.ray.direction());
        halfVector.normalize();

        pixelColor += hitMaterial.ambientColor * (*lightIt)->getMaterial().ambientColor;
        // Test if the hit point is in the shadow for the current light
        if (!aSceneToRender.mSurfaces->hit(HitParameters(Ray(hitPoint, lightDir), epsilon, (*lightIt)->getDistance(hitPoint)-epsilon),dummyRecord))
        {
            pixelColor +=
                  (
                    hitMaterial.diffuseColor * (*lightIt)->getMaterial().diffuseColor
                    * std::max(0., hitNormal.dotP(lightDir))
                  )
                + (
                    hitMaterial.specularColor * (*lightIt)->getMaterial().specularColor
                    * std::pow(std::max(0., hitNormal.dotP(halfVector)), hitMaterial.specularExponent)
                  )
                ;
        }
    }
    
    if ((++aRecursionDepth < DEPTH_LIMIT) && (hitMaterial.reflectiveColor != Rgb::BLACK))
    {
        Vec3 reflectionDir = hitParam.ray.direction() - 2*(hitParam.ray.direction().dotP(hitNormal)) * hitNormal;
        /// \todo : the limit should not be far plane, because if origin is far from the camera, we could see in the reflection an object that is not seen directly
        HitParameters reflectionParams(Ray(hitPoint, reflectionDir), epsilon, mIntrinsics.farPlane);
        if(aSceneToRender.mSurfaces->hit(reflectionParams, hitRecord))
        {
            pixelColor += hitMaterial.reflectiveColor * getRayColor(reflectionParams, hitRecord, dummyRecord, aSceneToRender, aRecursionDepth);
        }
    }

    return pixelColor;
}