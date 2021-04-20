#include "vec3.hpp"

vec3::vec3()
{
    components[0] = 0.0f;
    components[1] = 0.0f;
    components[2] = 0.0f;
}
vec3::vec3(float x, float y, float z)
{
    components[0] = x;
    components[1] = y;
    components[2] = z;
}
float vec3::x() const
{
    return components[0];
}
float vec3::y() const
{
    return components[1];
}
float vec3::z() const
{
    return components[2];
}
float vec3::r() const
{
    return components[0];
}
float vec3::g() const
{
    return components[1];
}
float vec3::b() const
{
    return components[2];
}

vec3 vec3::operator-() const
{
    return vec3(-components[0], -components[1], -components[2]);
}

float vec3::operator[](int i) const
{
    return components[i];
}

float& vec3::operator[](int i)
{
    return components[i];
}

vec3& vec3::operator+=(const vec3 &v)
{
    components[0] += v[0];
    components[1] += v[1];
    components[2] += v[2];
    return *this; 
}

vec3& vec3::operator*=(const float t)
{
    components[0] *= t;
    components[1] *= t;
    components[2] *= t;
    return *this; 
}

vec3& vec3::operator/=(const float t)
{
    components[0] /= t;
    components[1] /= t;
    components[2] /= t;
    return *this;
}

float vec3::lengthSquared() const 
{
    return (components[0] * components[0] + components[1] * components[1] + components[2] * components[2]);
}
float vec3::length() const
{
    return std::sqrt(lengthSquared());
}


