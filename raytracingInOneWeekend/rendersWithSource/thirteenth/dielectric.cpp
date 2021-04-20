#include "dielectric.hpp"

dielectric::dielectric(float indexOfRefraction)
{
    ir = indexOfRefraction;
}

bool dielectric::scatter(const ray& rayIn, const hitRecord& rec, vec3& attenuation, ray& scattered) const
{
    attenuation = vec3(1.0f);
    float refraction_ratio = rec.front_face ? (1.0/ir) : ir;

    vec3 unit_direction = unitVector(rayIn.direction());
    float cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
    float sin_theta = sqrt(1.0 - cos_theta*cos_theta);

    bool cannot_refract = refraction_ratio * sin_theta > 1.0;

    vec3 direction;
    if (cannot_refract || reflectance(cos_theta, refraction_ratio) > randomFloat())
        direction = reflect(unit_direction, rec.normal);
    else
        direction = refract(unit_direction, rec.normal, refraction_ratio);

    scattered = ray(rec.p, direction);
    return true;
}