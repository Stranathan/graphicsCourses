// std
#include <iostream>

// mine
#include "vec3.hpp"
#include "color.hpp"
#include "settings.hpp"
#include "ray.hpp"
#include "utils.hpp"

/*
    image is written line by line from the top left
    to the bottom right using ppm format
*/

int main() 
{
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n"; // init PPM format

    // ---- Main Render Loop ----
    for (int j = imageHeight; j > 0; j--) 
    {
        // Progress Indicator
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++) 
        {
            // normalized uv value |-> [-1, 1]
            float x = 2.0f * float(i) / float(imageWidth) - 1.0f;
            float y = 2.0f * float(j) / float(imageHeight) - 1.0f;

            vec3 uv = vec3(x, y, 0.0f);
            vec3 rd = uv - camPos;
            ray aRay = ray(camPos, rd);

            vec3 col = rayColTest(aRay);
            writeColor(std::cout, col);
        }
    }
    std::cerr << "\nDone.\n";
}