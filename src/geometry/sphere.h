#pragma once

#include <optional>

#include "colour/colour.h"
#include "math/vector.h"
#include "geometry/hit.h"
#include "geometry/ray.h"
#include "material/material.h"

class Sphere {
  public:
    Sphere(const Vector& centre, double radius, const Material& material);

    Colour colour() const;
    bool isHitBy(const Ray& ray) const;
    std::optional<Hit> hit(const Ray& ray) const;

  private:
    Vector _centre;
    double _radius;
    Material _material;
};
