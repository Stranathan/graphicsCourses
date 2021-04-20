#pragma once

#include "vec3.hpp"
#include "ray.hpp"
#include "hittableList.hpp"
#include "settings.hpp"

/*
    Recursive ray color function
    0.5 in ray collection seems arbitrary, shouldn't this attenuate non-linearly?
*/
vec3 rayCol(const ray& r, const hittable& scene, int recurseDepth)
{
    hitRecord rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (recurseDepth <= 0)
    {
        return vec3(0.0f);
    }

    if (scene.hit(r, 0.01f, infinity, rec)) {
        ray scattered;
        vec3 attenuation;
        if (rec.materialPtr->scatter(r, rec, attenuation, scattered))
            return attenuation * rayCol(scattered, scene, recurseDepth - 1);
        return vec3(0.0f, 0.0f, 0.0f);
    }
    float t = 0.5f * (r.rd.y() + 1.0f); // [-1, 1]  |--> [0, 1]; for lerp parameter
    // lerp between white and blue
    return (1.0f - t) * vec3(1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}