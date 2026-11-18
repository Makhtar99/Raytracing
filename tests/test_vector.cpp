#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "vector.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("a + b adds each component", "[vector]") {
    Vector sum = Vector(3, 4, 0) + Vector(4, -3, 0);

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 0);
}

TEST_CASE("a + b adds the z component", "[vector]") {
    Vector sum = Vector(3, 4, 1) + Vector(4, -3, 2);

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 3);
}

TEST_CASE("a - b subtracts each component", "[vector]") {
    Vector difference = Vector(4, 5, 0) - Vector(1, 1, 0);
    REQUIRE(difference.x() == 3);
    REQUIRE(difference.y() == 4);
    REQUIRE(difference.z() == 0);

    Vector differenceWithZ = Vector(4, 5, 6) - Vector(1, 1, 2);
    REQUIRE(differenceWithZ.x() == 3);
    REQUIRE(differenceWithZ.y() == 4);
    REQUIRE(differenceWithZ.z() == 4);
}

TEST_CASE("t * v scales each component", "[vector]") {
    Vector scaled = 2.0 * Vector(3, -4, 1);

    REQUIRE(scaled.x() == 6);
    REQUIRE(scaled.y() == -8);
    REQUIRE(scaled.z() == 2);
}

TEST_CASE("O + t * D gives the point on the ray at t", "[vector]") {
    Vector O(0, 8, 0);
    Vector D(3, -4, 0);
    double t = 2;

    Vector point = O + t * D;

    REQUIRE(point.x() == 6);
    REQUIRE(point.y() == 0);
    REQUIRE(point.z() == 0);
}

TEST_CASE("dot multiplies in pairs, then adds", "[vector]") {
    REQUIRE(Vector(3, 4, 0).dot(Vector(4, 3, 0)) == 24);
    REQUIRE(Vector(3, 4, 0).dot(Vector(4, -3, 0)) == 0);
    REQUIRE(Vector(3, 4, 12).dot(Vector(4, 3, 1)) == 36);
}

TEST_CASE("length follows Pythagoras", "[vector]") {
    REQUIRE(Vector(3, -4, 0).length() == 5);
    REQUIRE(Vector(3, 4, 12).length() == 13);
}

TEST_CASE("normalised gives a vector of length 1", "[vector]") {
    Vector unit = Vector(3, -4, 0).normalised();

    REQUIRE_THAT(unit.x(), WithinAbs(0.6, 1e-9));
    REQUIRE_THAT(unit.y(), WithinAbs(-0.8, 1e-9));
    REQUIRE_THAT(unit.z(), WithinAbs(0, 1e-9));
}

TEST_CASE("normalised of (3, 4, 12) has length 1", "[vector]") {
    REQUIRE_THAT(Vector(3, 4, 12).normalised().length(), WithinAbs(1, 1e-9));
}
