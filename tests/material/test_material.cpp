#include <catch2/catch_test_macros.hpp>

#include "colour/colour.h"
#include "material/material.h"
#include "math/vector.h"
#include "test_helpers.h"

// An orange surface facing the eye: its normal is (0, 0, -1).
TEST_CASE("a surface facing the light sends back its whole colour", "[material]") {
    Material orange(Colour(1, 0.5, 0));

    requireColoursEqual(orange.shade(Vector(0, 0, -1), Vector(0, 0, -1)), Colour(1, 0.5, 0));
}

TEST_CASE("a surface at an angle to the light is scaled by the cosine", "[material]") {
    Material orange(Colour(1, 0.5, 0));

    requireColoursEqual(orange.shade(Vector(0, 0, -1), Vector(0.6, 0, -0.8)), Colour(0.8, 0.4, 0));
}

TEST_CASE("a surface edge on to the light is black", "[material]") {
    Material orange(Colour(1, 0.5, 0));

    requireColoursEqual(orange.shade(Vector(0, 0, -1), Vector(1, 0, 0)), Colour(0, 0, 0));
}

TEST_CASE("a surface facing away from the light is black, not negative", "[material]") {
    Material orange(Colour(1, 0.5, 0));

    requireColoursEqual(orange.shade(Vector(0, 0, -1), Vector(0, 0, 1)), Colour(0, 0, 0));
}
