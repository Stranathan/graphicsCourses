#pragma once

#include "vec3.hpp"
#include <iostream>

void writeColor(std::ostream& out, vec3 col) 
{
    
    out << static_cast<int>(255.0f * col.r()) << ' '
        << static_cast<int>(255.0f * col.g()) << ' '
        << static_cast<int>(255.0f * col.b()) << '\n';
}