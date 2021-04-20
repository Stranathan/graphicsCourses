#pragma once
#include "vec3.hpp"
#include "ray.hpp"

class camera 
{
    private:
        float focalLength;

    public:
        vec3 pos;
        //
        camera(vec3 position);
        //
        ray getRay(float u, float v);
};