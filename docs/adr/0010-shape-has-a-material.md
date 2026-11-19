# 10. A shape has a material

## Context

Surfaces now take the light: a material knows how (Lambert's law, `max(0, N·L) × colour`), and a shape knows where a ray hits it and which way it faces. We have two shapes, a sphere and a plane, and more materials will come, such as mirrors and glass.

The option we didn't take: inheritance, with a subclass per shape and material (`MatteSphere`, `MirrorSphere`, `MattePlane`, `MirrorPlane`, ...). The number of classes is shapes × materials, and an object can't change its material while the program runs.

## Decision

A shape has a `Material`, held as a field and returned in its `Hit`. `trace` asks the scene for the nearest hit, then asks the hit's material to shade it: the shape and the renderer delegate the light to the material.

Shapes share one interface, `Shape`, with one method, `hit(ray)`. The `Scene` owns its shapes through `std::unique_ptr<Shape>`.

## Status

Accepted

## Consequences

- A new shape or a new material is one new class: shapes + materials, not shapes × materials.
- `trace` and `Camera` know a `Scene` and "a shape", never `Sphere` or `Plane`. Only `main` names the concrete classes.
- A material can be changed without touching the shape's geometry, as artists do in film studios.
- Each `Hit` copies its material. That is cheap while a material is one colour, but will cost more as materials grow.
- `Material` is a concrete class for now. Mirrors or glass will need an interface for materials, as `Shape` is for shapes.
