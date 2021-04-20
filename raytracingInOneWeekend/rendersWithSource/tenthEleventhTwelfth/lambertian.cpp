#include "lambertian.hpp"

lambertian::lambertian(const vec3& albedoCol)
{
    albedo = albedoCol;
}

bool lambertian::scatter(const ray& r_in, const hitRecord& rec, vec3& attenuation, ray& scattered) const 
{
    vec3 scatter_direction = rec.normal + randomUnitVector();

    // Catch degenerate scatter direction
    if (scatter_direction.nearZero())
    {
        scatter_direction = rec.normal;
    }   

    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}