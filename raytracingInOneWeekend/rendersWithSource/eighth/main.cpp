// std
#include <iostream>
#include <cmath>
#include <limits>
#include <memory>

// mine
#include "vec3.hpp"
#include "color.hpp"
#include "settings.hpp"
#include "ray.hpp"
#include "utils.hpp"
#include "sphere.hpp"
#include "hittableList.hpp"
#include "camera.hpp"

/*
    image is written line by line from top left to bottom right using ppm format
*/

int main() 
{

    // Scene
    hittableList scene;
    //world.add(make_shared<sphere>(vec3(0.0f, 0.0f, -1.0f), 0.5f));
    //world.add(make_shared<sphere>(vec3(0.0f, -100.5f, -1.0f), 100.0f));
    scene.add(make_shared<sphere>(theSpherePos, theSphereRadius));
    scene.add(make_shared<sphere>(theGiantSpherePos, theGiantSphereRadius));

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
                vec3 col = rayColorTestWithHittableList(aRay, scene); // in utils
                writeColor(std::cout, col);
            }
        }
        std::cerr << "\nDone.\n";
    }
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
                    col += rayColorTestWithHittableList(aRay, scene); // in utils
                }
                writeColorAA(std::cout, col, samplesPerPixel);
            }
        }
        std::cerr << "\nDone.\n";
    }
}