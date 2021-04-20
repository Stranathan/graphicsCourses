#pragma once
#include "vec3.hpp"
#include "ray.hpp"

#include <math.h>

class camera 
{
    public:

        //
        float focalLength;
        float ar;
        //
        vec3 pos;
        // vec3 w, u, v;
        vec3 u, v, lower_left_corner;
        //
        camera(vec3 position);
        camera(vec3 position, vec3 target, float anAspectRatio, float focalLen, float vfov);
        //
        ray getRay(float u, float v);
};