#include <catch2/catch_test_macros.hpp>

#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "math/vector.h"

TEST_CASE("a ray through the centre of a sphere hits it", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("a ray through the side of a sphere hits it", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(3, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("a ray that passes beside a sphere misses it", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(6, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("a sphere gives back its colour", "[sphere]") {
    Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0.5, 0));

    Colour colour = sphere.colour();

    REQUIRE(colour.r() == 1);
    REQUIRE(colour.g() == 0.5);
    REQUIRE(colour.b() == 0);
}
