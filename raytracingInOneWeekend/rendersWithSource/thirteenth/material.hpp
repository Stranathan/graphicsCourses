#pragma once

#include "ray.hpp"
#include "hittable.hpp"

//struct hitRecord;

class material 
{
    public:
        virtual bool scatter(
            const ray& r_in, const hitRecord& rec, vec3& attenuation, ray& scattered
        ) const = 0;
};