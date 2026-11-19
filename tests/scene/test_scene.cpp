#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <memory>
#include <optional>

#include "colour/colour.h"
#include "geometry/hit.h"
#include "geometry/plane.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "math/vector.h"
#include "scene/scene.h"
#include "test_helpers.h"

using Catch::Matchers::WithinAbs;

// The ray hits the red sphere at t = 5.
TEST_CASE("the nearest hit is a plane added after the sphere", "[scene]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(Vector(0, 0, 2), Vector(0, 0, -1), Material(Colour(0, 0, 1))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(3, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(0, 0, 1));
}

TEST_CASE("the nearest hit is a sphere added before the plane", "[scene]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(Vector(0, 0, 20), Vector(0, 0, -1), Material(Colour(0, 0, 1))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(5, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(1, 0, 0));
}

TEST_CASE("a scene gives nothing when the ray misses every shape", "[scene]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    REQUIRE_FALSE(scene.nearestHit(ray).has_value());
}
