#pragma once
#include "ray.hpp"
#include "material.hpp"

class metal : public material 
{
    public:
        // member values
        vec3 albedo;
        float fuzziness;
        // albedo constructor
        metal(const vec3& a);
        // albedo & fuzziness  constructor
        metal(const vec3& a, const float f);
        
        virtual bool scatter(const ray& r_in, const hitRecord& rec, vec3& attenuation, ray& scattered) const override;
};