#pragma once

#include <optional>

#include "colour/colour.h"
#include "math/vector.h"
#include "geometry/hit.h"
#include "geometry/ray.h"
#include "geometry/shape.h"
#include "material/material.h"

class Sphere : public Shape {
  public:
    Sphere(const Vector& centre, double radius, const Material& material);

    std::optional<Hit> hit(const Ray& ray) const override;

  private:
    Vector _centre;
    double _radius;
    Material _material;
};
