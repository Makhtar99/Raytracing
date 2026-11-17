#include <catch2/catch_test_macros.hpp>

#include "greeting.h"

TEST_CASE("greeting defaults to World", "[greeting]") {
    REQUIRE(greeting() == "Hello, World!");
}

TEST_CASE("greeting uses the given name", "[greeting]") {
    REQUIRE(greeting("Ray") == "Hello, Ray!");
}
