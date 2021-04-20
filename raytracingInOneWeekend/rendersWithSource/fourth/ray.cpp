#include "ray.hpp"

ray::ray()
{
    
}
ray::ray(const vec3& origin, const vec3& direction)
{
    ro = origin;
    //rd = unitVector(direction);
    rd = direction;
}

vec3 ray::origin() const
{
    return ro;
}
vec3 ray::direction() const
{
    return rd;
}
vec3 ray::position(float t)
{
    return ro + (t * rd);
}