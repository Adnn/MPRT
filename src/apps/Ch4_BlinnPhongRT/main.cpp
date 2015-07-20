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

#define WIDTH 500
#define HEIGHT 500


int main()
{

    Material sphereCloseMat(Rgb::GREEN, Rgb::GREEN, Rgb::WHITE);
    sphereCloseMat.specularExponent = 100;
    Material sphereFarMat(Rgb::BLUE, Rgb::BLUE, Rgb::WHITE);
    sphereFarMat.specularExponent = 100;
    Material triangleMat(Rgb::RED, Rgb::RED, Rgb::WHITE);
    triangleMat.specularExponent = 100;
    
    SurfacePtr sphereClose = std::make_shared<Sphere>(Vec3(200., 200., -500.), 75., sphereCloseMat);
    SurfacePtr sphereFar = std::make_shared<Sphere>(Vec3(250., 250., -1000.), 150., sphereFarMat);
    SurfacePtr triangle = std::make_shared<Triangle>(
        Vec3(300., 600., -800.),
        Vec3(0., 100., -1000.),
        Vec3(450., 20., -1000.),
        triangleMat );


    std::shared_ptr<Group> group = std::make_shared<Group>();
    group->addChild(sphereClose);
    group->addChild(sphereFar);
    group->addChild(triangle);
   
    //CameraIntrinsics intrinsics = {0., 2000., WIDTH/2, HEIGHT/2, ORTHGRAPHIC};
    FLOAT_TYPE dFoc = 20.;
    CameraIntrinsics intrinsics = {dFoc, 2000., WIDTH/2*dFoc/1000., HEIGHT/2*dFoc/1000., PERSPECTIVE};
    Camera camera(
        intrinsics,
        Vec3(250., 250., 0.),
        Vec3(0., 0., -1.));

    Rgb backgroundColor = Rgb(0.02, 0.02, 0.2);
    Scene scene;
    scene.mBackgroundColor = backgroundColor;
    scene.mSurfaces = group;
    Material lightMaterial(Rgb(.1, .1, .1), Rgb(.5, .5, .5), Rgb(.3, .3, .3));
    scene.mLights.push_back(std::shared_ptr<PointLight>(new PointLight(Vec3(0., 1000., 0.), lightMaterial)));
    Image image = camera.render(WIDTH, HEIGHT, scene, backgroundColor, 1); 
    
    std::ofstream outFile("D:/RayTraced/camera.ppm", std::ios_base::binary);
	image.writePPM(outFile);

    return 0;
}