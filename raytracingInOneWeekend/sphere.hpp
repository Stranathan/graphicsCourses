#pragma once

#include "hittable.hpp"
#include "vec3.hpp"

class sphere : public hittable 
{
    public:
        //
        vec3 pos;
        float radius;
        std::shared_ptr<material> materialPtr;
        // constructors
        sphere();
        sphere(vec3 position, float r);
        sphere(vec3 position, float r, std::shared_ptr<material> mat);
        // member functions
        virtual bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) const override;        
};