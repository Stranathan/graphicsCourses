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

/*
    image is written line by line from top left to bottom right using ppm format
*/

int main() 
{

    // Scene
    hittableList scene;
    
    // Materials
    auto matMetalSphere = make_shared<metal>(vec3(0.8));
    auto matGround = std::make_shared<lambertian>(vec3(0.8f, 0.8f, 0.0f));
    auto matDiffuseSphere = std::make_shared<lambertian>(vec3(0.7f, 0.3f, 0.3f));
    auto fuzzyMetalMat = make_shared<metal>(vec3(0.8, 0.6, 0.2), 1.0);

    // scene.add(make_shared<sphere>(theSpherePos, theSphereRadius));
    // scene.add(make_shared<sphere>(theGiantSpherePos, theGiantSphereRadius));
    // Spheres
    scene.add(make_shared<sphere>(vec3(theSpherePos.x() - 2.0f * theSphereRadius, theSpherePos.y(),theSpherePos.z()), theSphereRadius, matMetalSphere));
    scene.add(make_shared<sphere>(vec3(theSpherePos.x() + 2.0f * theSphereRadius, theSpherePos.y(),theSpherePos.z()), theSphereRadius, fuzzyMetalMat));
    scene.add(make_shared<sphere>(theSpherePos, theSphereRadius, matDiffuseSphere));
    scene.add(make_shared<sphere>(theGiantSpherePos, theGiantSphereRadius, matGround));

    // Camera
    camera cam = camera(camPos);

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
                // ---- normalized uv value |-> [-1, 1] ----
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
                    // ---- Make a virtual screen ----
                    // ---- normalized uv value |-> [-1, 1] ----
                    float u = (2.0f * float(i + randomFloat()) / float(imageWidth) - 1.0f) * aspectRatio; // aspect in settings
                    float v = 2.0f * float(j + randomFloat()) / float(imageHeight) - 1.0f;
                    ray aRay = cam.getRay(u, v);
                    col += rayCol(aRay, scene, recursionMaxDepth); // in utils
                }
                writeColorAA(std::cout, col, samplesPerPixel);
            }
        }
        std::cerr << "\nDone.\n";
    }
}