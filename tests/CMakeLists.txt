include(FetchContent)

# Catch2 is downloaded and built on the first configure.
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(Catch2)

# Add new test files to this list.
add_executable(raytracer_tests
  test_greeting.cpp
  test_vector.cpp
)
target_link_libraries(raytracer_tests PRIVATE raytracer_core raytracer_warnings Catch2::Catch2WithMain)

# Registers each TEST_CASE with CTest.
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(raytracer_tests)
