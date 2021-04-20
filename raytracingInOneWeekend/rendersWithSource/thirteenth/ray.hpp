#pragma once

#include "vec3.hpp"

class ray
{
public:
    //
    vec3 ro;
    vec3 rd;
    //
    ray();
    ray(const vec3& origin, const vec3& direction);
    //
    vec3 origin() const;
    vec3 direction() const;
    vec3 position(float t) const;
};