# 7. Colour is a class of its own, not a Vector

## Context

A colour is three numbers (r, g, b), like a Vector. We could reuse Vector for colours, or write a separate class.

They hold the same shape of data but different knowledge. Colours get mixed, kept between 0 and 1, and turned into 0 to 255 for an image file. Directions need none of that, and a colour has no use for `dot` or `normalised`.

## Decision

`Colour` is its own class, in `src/colour/`, with three private doubles `_r`, `_g` and `_b`, readable through `r()`, `g()` and `b()`. It has its own folder so that `geometry/` (Sphere holds a Colour) and `render/` can both depend on it without a loop between folders.

## Status

Accepted

## Consequences

- The compiler stops anyone from adding a colour to a position, or taking the dot product of two colours.
- Each class only offers the operations that make sense for it.
- Some operations will look alike, such as adding two colours and adding two vectors. That is similar code, not duplicated knowledge.
- Tests need their own helper to compare colours, `requireColoursEqual`.

## Option not taken

Using `Vector` for colours: less code today, but a colour would inherit `dot`, `length` and `normalised`, and nothing would stop mixing colours with positions.
