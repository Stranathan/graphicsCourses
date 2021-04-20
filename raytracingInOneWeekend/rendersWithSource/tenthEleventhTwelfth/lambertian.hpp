#pragma once
#include "material.hpp"

class lambertian : public material 
{
    public:
        lambertian(const vec3& a);

        virtual bool scatter(const ray& r_in, const hitRecord& rec, vec3& attenuation, ray& scattered) const override;

    public:
        vec3 albedo;
};