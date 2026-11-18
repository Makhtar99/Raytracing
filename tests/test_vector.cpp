#include <catch2/catch_test_macros.hpp>

#include "vector.h"

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
