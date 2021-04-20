#include "vec3.hpp"
#include "color.hpp"
#include "settings.hpp"
#include "ray.hpp"
#include "utils.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "hittableList.hpp"
#include "camera.hpp"
#include "render.hpp"
#include "lambertian.hpp"
#include "metal.hpp"
#include "dielectric.hpp"

/*
    image is written line by line from top left to bottom right using ppm format
*/

int main() 
{

    // Scene
    hittableList scene;
    
    // Materials
    // auto matMetalSphere = make_shared<metal>(vec3(0.8));
    auto matGlass = make_shared<dielectric>(1.5f);
    auto matGround = std::make_shared<lambertian>(vec3(0.8f, 0.8f, 0.0f));
    auto matDiffuseSphere = std::make_shared<lambertian>(vec3(0.7f, 0.3f, 0.3f));
    auto fuzzyMetalMat = make_shared<metal>(vec3(0.8f, 0.6f, 0.2f), 0.8f);

    // scene.add(make_shared<sphere>(theSpherePos, theSphereRadius));
    // scene.add(make_shared<sphere>(theGiantSpherePos, theGiantSphereRadius));
    // Spheres
    scene.add(make_shared<sphere>(vec3(theSpherePos.x() - 2.0f * theSphereRadius, theSpherePos.y(),theSpherePos.z()), -theSphereRadius, matGlass));
    scene.add(make_shared<sphere>(vec3(theSpherePos.x() + 2.0f * theSphereRadius, theSpherePos.y(),theSpherePos.z()), theSphereRadius, fuzzyMetalMat));
    scene.add(make_shared<sphere>(theSpherePos, theSphereRadius, matDiffuseSphere));
    scene.add(make_shared<sphere>(theGiantSpherePos, theGiantSphereRadius, matGround));

    // Camera
    //camera cam = camera(camPos);
    float ar_ratio = (16.0f / 9.0f);
    camera cam = camera(vec3(-3.0f, 3.0f, -3.0f), theSpherePos, ar_ratio, 3.0f, 90.0f / 3.0f);

    // ---- Main Render Loop ----
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n"; // init PPM format

    // ---- Non AA render ----
    if(AA == false)
    {
        for (int j = imageHeight; j > 0; j--) 
        {
            // ---- Progress Indicator ----
            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            for (int i = 0; i < imageWidth; i++) 
            {
                // ---- Make a virtual screen ----
                // ---- normalized st value |-> [-1, 1] ----
                // this will be a scalar value for the unit vectors uv
                float u = (2.0f * float(i) / float(imageWidth) - 1.0f) * aspectRatio; // aspect in settings
                float v = 2.0f * float(j) / float(imageHeight) - 1.0f;
                ray aRay = cam.getRay(u, v);
                vec3 col = rayCol(aRay, scene, recursionMaxDepth); // in utils
                writeColor(std::cout, col);
            }
        }
        std::cerr << "\nDone.\n";
    }
    // ---- AA render ----
    else
    {
        for (int j = imageHeight; j > 0; j--) 
        {
            // ---- Progress Indicator ----
            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            
            for (int i = 0; i < imageWidth; i++) 
            {
                vec3 col = vec3(0.0f);
                for(int s = 0; s < samplesPerPixel; s++)
                {
                    
                    // this is just a bunch of floats that run from -1 to 1
                    // this scales the u and v vectors to make a screen
                    float u = float(i + randomFloat()) / float(imageWidth); // aspect in settings
                    float v = float(j + randomFloat()) / float(imageHeight);
                    ray aRay = cam.getRay(u, v);
                    col += rayCol(aRay, scene, recursionMaxDepth); // in utils
                }
                writeColorAA(std::cout, col, samplesPerPixel);
            }
        }
        std::cerr << "\nDone.\n";
    }
}