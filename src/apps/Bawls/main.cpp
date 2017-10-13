#include <TracingTools/Camera.h>
#include <TracingTools/Scene.h>
#include <Geometry/Sphere.h>
#include <Geometry/Triangle.h>
#include <Geometry/Group.h>
#include <Tools/Image.h>
#include <Tools/Sampler.h>
#include <Tools/Rgb.h>
#include <Tools/Vec2.h>

#include <fstream>

using namespace MPRT;

#define WIDTH 1500
#define HEIGHT 1500


int main()
{

    Material sphereLeftMat(Rgb::GREEN, Rgb::GREEN, Rgb::WHITE);
    sphereLeftMat.specularExponent = 100;
    Material sphereRightMat(Rgb::BLUE, Rgb::BLUE, Rgb::WHITE);
    sphereRightMat.specularExponent = 100;
    sphereRightMat.reflectiveColor = Rgb(.5, .7, .5);
    Material floorMat(Rgb(.6, .6, .6), Rgb(.6, .6, .6), Rgb::WHITE);
    floorMat.specularExponent = 100;
    floorMat.reflectiveColor = Rgb(.5, .7, .5);
    
    SurfacePtr sphereClose = std::make_shared<Sphere>(Vec3(-1., 1., -5.), 1., sphereLeftMat);
    SurfacePtr sphereFar = std::make_shared<Sphere>(Vec3(2., 1., -6.), 1., sphereRightMat);
    SurfacePtr triangleRight = std::make_shared<Triangle>(
        Vec3(-10., 0., -15.),
        Vec3(10., 0., 0.),
        Vec3(10., 0., -15.),
        floorMat );
    SurfacePtr triangleLeft = std::make_shared<Triangle>(
        Vec3(-10., 0., -15.),
        Vec3(-10., 0., 0.),
        Vec3(10., 0., 0.),
        floorMat );

    std::shared_ptr<Group> group = std::make_shared<Group>();
    group->addChild(sphereClose);
    group->addChild(sphereFar);
    group->addChild(triangleLeft);
    group->addChild(triangleRight);
   
    //CameraIntrinsics intrinsics = {0., 200., WIDTH/2, HEIGHT/2, ORTHGRAPHIC};
    FLOAT_TYPE dFoc = .2;
    CameraIntrinsics intrinsics = {dFoc, 2000., dFoc, dFoc, PERSPECTIVE};
    Camera camera(
        intrinsics,
        Vec3(0., 1., -1.5),
        Vec3(0., 0., -1.));

    Rgb backgroundColor = Rgb(0.02, 0.02, 0.2);
    Scene scene;
    scene.mBackgroundColor = backgroundColor;
    scene.mSurfaces = group;
    Material lightMaterial(Rgb(.08, .08, .08), Rgb(.5, .5, .5), Rgb(.3, .3, .3));
    scene.mLights.push_back(std::shared_ptr<PointLight>(new PointLight(Vec3(-11., 8., 1.), lightMaterial)));
    Image image = camera.render(WIDTH, HEIGHT, scene, backgroundColor, 8); 

    std::ofstream outFile("./scene.ppm", std::ios_base::binary);
	image.writePPM(outFile);

    return 0;
}