#include "sphere.hpp"

sphere::sphere(){}

sphere::sphere(vec3 position, float r)
{
    pos = position;
    radius = r;
}
// ---- why does dot product fail near rim if I normalize rd --> A = 1 
bool sphere::hit(const ray& r, float tMin, float tMax, hitRecord& rec) const
{
    vec3 sphere2Cam = r.origin() - pos;
    float A = r.direction().lengthSquared();
    float B = dot(r.direction(), sphere2Cam);
    float C = dot(sphere2Cam, sphere2Cam) - radius * radius;

    float discriminant = B * B - C * A;
    if (discriminant < 0.0f)
    {
        return false;
    }

    float sqrtOfDiscrimant = std::sqrt(discriminant); // so you only need to a sqrt once
    float root = (-B - sqrtOfDiscrimant) / A;

    if (root < tMin || tMax < root) 
    {
        root = (-B + sqrtOfDiscrimant) / A;
        if (root < tMin || tMax < root)
        {
            return false;
        }
    }
    rec.t = root;
    rec.p = r.position(rec.t);
    vec3 outward_normal = (rec.p - pos) / radius;
    rec.set_face_normal(r, outward_normal);
    return true;
}