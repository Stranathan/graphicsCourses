#pragma once

#include "hittable.hpp"
#include "vec3.hpp"

class sphere : public hittable 
{
    public:
        vec3 pos;
        float radius;
        // constructors
        sphere();
        sphere(vec3 position, float r);
        // member functions
        virtual bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) const override;        
};