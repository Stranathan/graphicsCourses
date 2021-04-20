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

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n"; // init PPM format

    // ---- Main Render Loop ----
    for (int j = imageHeight; j > 0; j--) 
    {
        // ---- Progress Indicator ----
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++) 
        {
            // ---- Make a virtual screen ----
            // ---- normalized uv value |-> [-1, 1] ----
            float x = (2.0f * float(i) / float(imageWidth) - 1.0f) * aspectRatio;
            float y = 2.0f * float(j) / float(imageHeight) - 1.0f;
            
            vec3 uv = vec3(x, y, 0.0f);
            vec3 rd = uv - camPos;
            ray aRay = ray(camPos, rd);

            //vec3 col = rayColTestWithSphereIntersectionWithNormal(theSpherePos, theSphereRadius, aRay);
            vec3 col = rayColorTestWithHittableList(aRay, scene);
            writeColor(std::cout, col);
        }
    }
    std::cerr << "\nDone.\n";
}