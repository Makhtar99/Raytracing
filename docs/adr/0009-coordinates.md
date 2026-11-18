# 9. Coordinates: x right, y up, z forward, pixels from the top left

## Context

The camera turns a pixel's column and row into a point on its screen. That needs two coordinate systems to be fixed: the world's, and the image's.

Image files count pixels from the top left, row by row, like text on a page. In the world, we want "up" to mean up.

The option we didn't take: looking along −z, as *Ray Tracing in One Weekend* does (a right-handed system).

## Decision

- The world uses x to the right, y up and z forward, away from the eye. The camera looks along +z. This is a left-handed system.
- Images count columns from the left and rows from the top, starting at 0.
- The camera turns rows round: the centre of pixel (column, row) is at
  `x = (column + 0.5 − width / 2) × s` and `y = (height / 2 − row − 0.5) × s`,
  where `s = screen width / width`.

## Status

Accepted

## Consequences

- Positive z is in front of the camera, so the numbers in our tests read naturally: a sphere at z = 9 is 9 ahead.
- A sphere moved up (larger y) appears higher in the image.
- Code or formulas taken from *Ray Tracing in One Weekend* must have z flipped.
- The screen stays parallel to x and y, so the camera can only look along z. Turning it needs more maths, later.
