#pragma once

#include "vec3.hpp"

// Image dimensions in pixels
const int imageHeight = 256;
const float aspectRatio = 16.0f / 9.0f;
const int imageWidth = static_cast<int>(aspectRatio * float(imageHeight));

// Camera
float viewportHeight = 2.0f;
float viewportWidth = aspectRatio * viewportHeight;

float focalLength = 1.0f;
vec3 worldOrigin = vec3(0.0f, 0.0f, 0.0f);
vec3 camPos = worldOrigin - vec3(0.0f, 0.0f, focalLength);
