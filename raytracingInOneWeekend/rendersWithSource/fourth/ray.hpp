#pragma once

#include "vec3.hpp"

class ray
{
public:
    // data
    vec3 ro;
    vec3 rd;

    // constructors 
    ray();
    ray(const vec3& origin, const vec3& direction);

    // member functions
    vec3 origin() const;
    vec3 direction() const;

    vec3 position(float t);
};