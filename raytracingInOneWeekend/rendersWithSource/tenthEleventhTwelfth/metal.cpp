#include "metal.hpp"

metal::metal(const vec3& a)
{
    albedo = a;
    fuzziness = 0.0f;
}
metal::metal(const vec3& a, const float f)
{
    albedo = a;
    if(f < 1.0f)
    {
        fuzziness = f;
    }
    else
    {
        fuzziness = 1.0f;
    }
}
bool metal::scatter(const ray& rayIn, const hitRecord& rec, vec3& attenuation, ray& scattered) const
{
    vec3 reflected = reflect(unitVector(rayIn.direction()), rec.normal);
    scattered = ray(rec.p, reflected + fuzziness * randomUnitVector());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}
