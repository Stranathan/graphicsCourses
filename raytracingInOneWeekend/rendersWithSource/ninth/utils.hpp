#pragma once
//
#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>
//
#include "vec3.hpp"
#include "ray.hpp"
#include "hittableList.hpp"

//
bool sphereRayIntersection(const vec3& spherePos, float radius, const ray& r)
{
    vec3 rd = unitVector(r.direction());

    float B = dot(rd, r.origin() - spherePos);
    float C = dot((r.origin() - spherePos), (r.origin() - spherePos)) - (radius * radius);

    float discriminant = B * B - C;
    return (discriminant > 0.0f);
}

float sphereRayIntersectionWithNormal(const vec3& spherePos, float radius, const ray& r)
{
    vec3 rd = unitVector(r.direction());

    float B = dot(rd, r.origin() - spherePos);
    float C = dot((r.origin() - spherePos), (r.origin() - spherePos)) - (radius * radius);

    float discriminant = (B * B - C);

    if(discriminant < 0.0f)
    {
        return -1.0f;
    }
    else
    {
        return (-B - std::sqrt(discriminant)); // always taking the closer of the two t values
    }
}

vec3 rayColTestLerp(const ray& r) 
{
    float t = 0.5f * (r.rd.y() + 1.0f); // [-1, 1]  |--> [0, 1]; for lerp parameter
    // lerp between white and blue
    return (1.0f - t) * vec3(1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

vec3 rayColTestWithSphereIntersection(const vec3& spherePos, float radius, const ray& r) 
{
    if(sphereRayIntersection(spherePos, radius, r))
    {
        return vec3(1.0f, 0.0f, 0.0f);
    }
    float t = 0.5f * (r.rd.y() + 1.0f); // [-1, 1]  |--> [0, 1]; for lerp parameter
    // lerp between white and blue
    return (1.0f - t) * vec3(1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

vec3 rayColTestWithSphereIntersectionWithNormal(const vec3& spherePos, float radius, const ray& r) 
{
    float t = sphereRayIntersectionWithNormal(spherePos, radius, r);
    if(t > 0.0f)
    {
        vec3 N = (unitVector(r.position(t) - spherePos));
        return 0.5f *  (N + 1.0f);
    }
    
    t = 0.5f * (r.rd.y() + 1.0f); // [-1, 1]  |--> [0, 1]; for lerp parameter
    // lerp between white and blue
    return (1.0f - t) * vec3(1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

vec3 rayColorTestWithHittableList(const ray& r, const hittable& scene, int recurseDepth)
{
    hitRecord rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (recurseDepth <= 0)
    {
        return vec3(0.0f);
    }

    if (scene.hit(r, 0.001f, infinity, rec))
    {
        // target within unit sphere of intersection point:
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        //return 0.5f * (rec.normal + 1.0f); // [-1, 1] |---> [0, 1];
        return 0.5 * rayColorTestWithHittableList(ray(rec.p, target - rec.p), scene, recurseDepth - 1);
    }
    float t = 0.5f * (r.rd.y() + 1.0f); // [-1, 1]  |--> [0, 1]; for lerp parameter
    // lerp between white and blue
    return (1.0f - t) * vec3(1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}