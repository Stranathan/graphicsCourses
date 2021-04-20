#include "camera.hpp"

camera::camera(vec3 position)
{
    pos = position;
    focalLength = 1.0f;
    // float viewportHeight = 2.0f;
    // float viewportWidth = aspectRatio * viewportHeight;
}

ray camera::getRay(float u, float v)
{
    vec3 rd = vec3(u, v, 0.0f) - pos;
    ray aRay = ray(pos, rd);
    return aRay;
}