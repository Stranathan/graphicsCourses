#pragma once
//
#include <iostream>
//
#include "vec3.hpp"
#include "utils.hpp"

void writeColor(std::ostream& out, vec3 col) 
{
    
    out << static_cast<int>(255.0f * col.r()) << ' '
        << static_cast<int>(255.0f * col.g()) << ' '
        << static_cast<int>(255.0f * col.b()) << '\n';
}

void writeColorAA(std::ostream &out, vec3 col, int samplesNum) 
{
    float r = col.x();
    float g = col.y();
    float b = col.z();

    // Divide the color by the number of samples.
    float scale = 1.0f / float(samplesNum);
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.0f * clamp(r, 0.0f, 1.0f)) << ' '
        << static_cast<int>(255.0f * clamp(g, 0.0f, 1.0f)) << ' '
        << static_cast<int>(255.0f * clamp(b, 0.0f, 1.0f)) << '\n';
}