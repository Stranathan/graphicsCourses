#pragma once

#include "utils.hpp"
#include "vec3.hpp"
#include "hittableList.hpp"
#include "sphere.hpp"

// Image dimensions in pixels
const int imageHeight = 256;
const float aspectRatio = 16.0f / 9.0f;
const int imageWidth = static_cast<int>(aspectRatio * float(imageHeight));

// World
vec3 worldOrigin = vec3(0.0f, 0.0f, 0.0f);

// Camera
float focalLength = 1.0f;
vec3 camPos = worldOrigin - vec3(0.0f, 0.0f, focalLength);
// float viewportHeight = 2.0f; *???*
// float viewportWidth = aspectRatio * viewportHeight;

// Geometry
vec3 theSpherePos = vec3(0.0f, 0.0f, 1.0f);
float theSphereRadius = 1.f;
float theGiantSphereRadius = 100.0f;
vec3 theGiantSpherePos = vec3(0.0f, -theGiantSphereRadius - theSphereRadius, theSpherePos.z());

// Rendering
float hitThresholdDist = 0.001f;
bool AA = true;
int samplesPerPixel = 25;
int recursionMaxDepth = 10;