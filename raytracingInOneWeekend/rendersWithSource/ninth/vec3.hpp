#pragma once
//
#include <cmath>
#include <iostream>
//
#include "properUtils.hpp"

class vec3
{
public:

    // data
    float components[3];

    // constructors
    vec3();
    vec3(float num);
    vec3(float x, float y, float z);
    // destructors

    // ---- member functions ----
    // only member functions can be const-qualified
    // const function will not be allowed to alter the state of the object it is invoked on
    float x() const;
    float y() const;
    float z() const;
    float r() const;
    float g() const;
    float b() const;

    // ---- operator overloads ----
    vec3 operator-() const;
    float operator[](int i) const;
    float& operator[](int i);
    vec3& operator+=(const vec3 &v);
    vec3& operator*=(const float t);
    vec3& operator/=(const float t);

    float length() const;
    float lengthSquared() const;

    // static member functions are not attached to a particular object,
    // they can be called directly by using the class name and the scope resolution operator
    inline static vec3 random()
    {
        return vec3(randomFloat(), randomFloat(), randomFloat());
    }
    inline static vec3 random(double min, double max)
    {
        return vec3(randomFloat(min,max), randomFloat(min,max), randomFloat(min,max));
    }
};

// inline utitly functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v) 
{
    return out << v.components[0] << ' ' << v.components[1] << ' ' << v.components[2];
}
inline vec3 operator+(const vec3& u, const vec3& v) 
{
    return vec3(u.components[0] + v.components[0], u.components[1] + v.components[1], u.components[2] + v.components[2]);
}
inline vec3 operator-(const vec3& u, const vec3& v)
{
    return vec3(u.components[0] - v.components[0],
                u.components[1] - v.components[1],
                u.components[2] - v.components[2]);
}
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.components[0] * v.components[0],
                u.components[1] * v.components[1],
                u.components[2] * v.components[2]);
}
inline vec3 operator*(float t, const vec3& vec)
{
    return vec3(t * vec.components[0], t * vec.components[1], t * vec.components[2]);
}
inline vec3 operator*(const vec3& v, float t)
{
    return t * v;
}
inline vec3 operator+(float t, const vec3& vec)
{
    return vec3(t + vec.components[0], t + vec.components[1], t + vec.components[2]);
}
inline vec3 operator+(const vec3& v, float t)
{
    return t + v;
}
inline vec3 operator-(float t, const vec3& vec)
{
    return vec3(t - vec.components[0], t - vec.components[1], t - vec.components[2]);
}
inline vec3 operator-(const vec3& v, float t)
{
    return vec3(v.components[0] - t, v.components[1] - t, v.components[2] - t);
}
inline vec3 operator/(vec3 v, float t)
{
    return (1/t) * v;
}
inline float dot(const vec3& u, const vec3& v)
{
    return u.components[0] * v.components[0]
         + u.components[1] * v.components[1]
         + u.components[2] * v.components[2];
}
inline vec3 cross(const vec3 &u, const vec3 &v) 
{
    return vec3(u.components[1] * v.components[2] - u.components[2] * v.components[1],
                u.components[2] * v.components[0] - u.components[0] * v.components[2],
                u.components[0] * v.components[1] - u.components[1] * v.components[0]);
}
inline vec3 unitVector(vec3 v) 
{
    return v / v.length();
}

inline vec3 random_in_unit_sphere()
{
    // rejection method
    while (true) 
    {
        vec3 p = vec3::random(-1,1);
        if (p.lengthSquared() >= 1) continue;
        return p;
    }
}