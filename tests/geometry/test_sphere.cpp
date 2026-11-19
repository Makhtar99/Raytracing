#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <optional>

#include "colour/colour.h"
#include "geometry/hit.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "math/vector.h"
#include "test_helpers.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("hit through the centre gives t, the point, the normal and the material", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    std::optional<Hit> hit = sphere.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(5, tolerance));
    requireVectorsEqual(hit->point, Vector(0, 0, 4));
    requireVectorsEqual(hit->normal, Vector(0, 0, -1));
    requireColoursEqual(hit->material.colour(), Colour(1, 0, 0));
}

TEST_CASE("hit through the side gives the normal of the 3-4-5 triangle", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    std::optional<Hit> hit = sphere.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(6, tolerance));
    requireVectorsEqual(hit->point, Vector(0, 0, 5));
    requireVectorsEqual(hit->normal, Vector(-0.6, 0, -0.8));
}

TEST_CASE("hit gives nothing when the ray passes beside the sphere", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.hit(ray).has_value());
}

TEST_CASE("hit gives nothing when the sphere is behind the ray's origin", "[sphere]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, -11), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.hit(ray).has_value());
}
