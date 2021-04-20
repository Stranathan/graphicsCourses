#include <iostream>

/*
    image will be made line by line starting from the top left
    to the bottom right using ppm format
*/

int main() {

    // Image dimensions in pixels
    const int imageWidth = 256;
    const int imageHeight = 256;

    // Everything below this is rendering

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n"; // init PPM format

    // to keep shadertoy style hello world, decrement along y
    for (int j = imageHeight; j > 0; j--) 
    {
        for (int i = 0; i < imageWidth; i++) 
        {
            // normalized uv value
            float red = float(i) / float(imageWidth);
            float green = float(j) / float(imageHeight);
            float blue = 0.0f;

            int r = static_cast<int>(255.0f * red);
            int g = static_cast<int>(255.0f * green);
            int b = static_cast<int>(255.0f * blue);

            std::cout << r << ' ' << g << ' ' << b << '\n';
        }
    }
}