#include <catch2/catch_test_macros.hpp>

#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "math/vector.h"
#include "render/trace.h"
#include "test_helpers.h"

TEST_CASE("trace gives the whole colour when the sun is behind the eye", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(trace(ray, sphere, Vector(0, 0, -1)), Colour(1, 0, 0));
}

TEST_CASE("trace dims the colour with the light at an angle", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(trace(ray, sphere, Vector(0.6, 0, -0.8)), Colour(0.8, 0, 0));
}

TEST_CASE("trace dims the colour where the surface turns away", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(trace(ray, sphere, Vector(0, 0, -1)), Colour(0.8, 0, 0));
}

TEST_CASE("trace gives black when the ray misses the sphere", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(trace(ray, sphere, Vector(0, 0, -1)), Colour(0, 0, 0));
}
