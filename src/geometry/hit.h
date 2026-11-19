#pragma once

#include "material/material.h"
#include "math/vector.h"

// Where a ray hits a surface, which way the surface faces there, and what it is made of.
struct Hit {
    double t;
    Vector point;
    Vector normal;
    Material material;
};
