#pragma once

#include <math.h>

#include "ray.hpp"
#include "material.hpp"

class dielectric : public material
{
    public:
        //
        float ir; // index of refraction
        //
        dielectric(float indexOfRefraction);
        //
        virtual bool scatter(const ray& r_in, const hitRecord& rec, vec3& attenuation, ray& scattered) const override;

    private:

        static float reflectance(float cosine, float ref_idx) 
        {
            // Use Schlick's approximation for reflectance.
            float r0 = (1 - ref_idx) / ( 1 + ref_idx);
            r0 = r0*r0;
            return r0 + (1 - r0) * pow((1 - cosine),5);
        }
};