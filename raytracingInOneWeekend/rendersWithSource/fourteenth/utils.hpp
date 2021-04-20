#pragma once
//
#include <iostream>
#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>
#include <vector>

#define PI (3.1415926)

const float infinity = std::numeric_limits<float>::infinity();

inline float clamp(float x, float min, float max) 
{
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

inline float degreesToRadians(float degrees)
{
    return degrees * PI / 180.0f;
}

inline float randomFloat() 
{
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0f);
}

inline float randomFloat(float min, float max)
{
    // Returns a random real in [min,max).
    return min + (max-min)*randomFloat();
}