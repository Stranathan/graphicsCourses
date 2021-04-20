#pragma once

#include "utils.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class material;

struct hitRecord
{
    vec3 p;
    vec3 normal;
    std::shared_ptr<material> materialPtr;
    float t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};

class hittable
{
    public:
        virtual bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) const = 0;
};
