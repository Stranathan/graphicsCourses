#include "camera.hpp"

camera::camera(vec3 position)
{
    pos = position;
    focalLength = 1.0f;
    ar = 16.0f / 9.0f;
}
// camera::camera(vec3 position, vec3 target, float anAspectRatio, float focalLen, float vfov)
// {
//     pos = position;
//     focalLength = 1.0f; // the focal length is the distance between the projection point and the image plane
//     ar = anAspectRatio;
//     float theta = degreesToRadians(vfov);
//     float viewportHeight = 2.0f * focalLength * tan(theta/2.0f); // focalLength * tan(theta/2); gives us half the viewscreen height
//     float viewportWidth = ar * viewportHeight;

//     vec3 forward = unitVector(pos - target);
//     vec3 right = unitVector(cross(vec3(0.0f, 1.0f, 0.0f), forward));
//     vec3 up = cross(forward, right);
//     u = (pos - forward * focalLength) + right * viewportWidth;
//     v = (pos - forward * focalLength) + up * viewportHeight;
// }
camera::camera(vec3 position, vec3 target, float anAspectRatio, float focalLen, float vfov)
{
    pos = position;
    focalLength = focalLen; // the focal length is the distance between the projection point and the image plane
    ar = anAspectRatio;
    float theta = degreesToRadians(vfov);
    float viewportHeight = 2.0f * tan(theta/2.0f); // focalLength * tan(theta/2); gives us half the viewscreen height
    float viewportWidth = ar * viewportHeight;

    vec3 forward = unitVector(pos - target);
    vec3 right = unitVector(cross(vec3(0.0f, 1.0f, 0.0f), forward));
    vec3 up = cross(forward, right);
    u = right * viewportWidth;
    v = up * viewportHeight;
    lower_left_corner = pos - forward - u/2 - v/2;
}
ray camera::getRay(float s, float t)
{
    // s *= ar;
    // vec3 rd = vec3(s, t, 0.) - pos;
    // vec3 rd = (s * u + t * v) - pos;
    vec3 rd = lower_left_corner + s*u + t*v - pos;
    ray aRay = ray(pos, rd);
    return aRay;
}