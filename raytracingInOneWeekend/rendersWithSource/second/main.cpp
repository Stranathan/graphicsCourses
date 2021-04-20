#include "vec3.hpp"
#include "color.hpp"
#include <iostream>

/*
    image is made line by line starting from the top left
    to the bottom right using ppm format
*/

int main() {

    // Image dimensions in pixels
    const int imageWidth = 256;
    const int imageHeight = 256;

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n"; // init PPM format

    // ---- Main Render Loop ----
    for (int j = imageHeight; j > 0; j--) 
    {
        // Progress Indicator
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; i++) 
        {
            // normalized uv value
            float red = float(i) / float(imageWidth);
            float green = float(j) / float(imageHeight);
            float blue = 0.0f;

            vec3 col(red, green, blue);

            // int r = static_cast<int>(255.0f * red);
            // int g = static_cast<int>(255.0f * green);
            // int b = static_cast<int>(255.0f * blue);

            // std::cout << r << ' ' << g << ' ' << b << '\n';
            writeColor(std::cout, col);
        }
    }
    std::cerr << "\nDone.\n";
}