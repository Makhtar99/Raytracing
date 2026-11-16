# Discovery report

## Problem statement

An animation studio that renders HD films on a 100-CPU farm needs a renderer it can understand, fix and extend for years, because it must render a whole film in about two months with around ten previews per frame, but its previous tool broke in ways nobody on staff could explain.

## Client interview summary

### Current situation

**Need:** Replace the tool the studio used before.

> **Q (me):** "What do you render with today, and what made you decide you need a new one?"
>
> **A:** "Solution before: Maya."

**My conclusion:** The studio comes from a commercial tool. I still need to know which renderer it used inside Maya and what went wrong with it.

### Delivery

**Need:** A working solution delivered by early January.

> **Q (a classmate):** "When should the project be finalized?"
>
> **A:** "Deadline: 5 of January, roughly 2 months."

**My conclusion:** About 7 weeks of work.

### Infrastructure and volume

**Need:** Rendering runs on CPUs, spread across a render farm, and covers previews as well as the final render.

> **Q (a classmate):** "Where do renders run: on artists' machines, on a render farm, or both?"
>
> **A:** "Render CPU (100 CPU farm)."

> **Q (a classmate):** "For your last film, how long did one frame take to render, at what resolution, and on how many machines?"
>
> **A:** "2 months final rendering." / "10 pre-renders per image."

**My conclusion:** No GPU, so the renderer must scale across many CPU machines. Each image is rendered about 11 times (10 previews and the final render).

### Performance

**Need:** A frame should render in well under 10 minutes, and faster is always better.

> **Q (me):** "At what point does a frame take too long and become a problem for the team?"
>
> **A:** "1 minute is long for a frame rendering and 10 min is too much." / "In terms of rendering, the faster the better."

**My conclusion:** Assuming a 90-minute film at 24 fps (129,600 frames), 11 renders per frame, 100 machines and 2 months (about 86,400 minutes), each render has a budget of about 6 minutes. This is consistent with "10 min is too much". These assumptions still have to be confirmed (see open questions).

### Image quality

**Need:** HD images for a fully animated film, with reliable results.

> **Q (a classmate):** "Can you show us or describe a frame that represents the quality you expect?"
>
> **A:** "HD." / "Reliable image."

> **Q (me):** "What kind of content do you render: live-action effects, full animation, something else?"
>
> **A:** "Full animation."

**My conclusion:** Stylised animation rather than live-action effects. "Reliable" probably means the same scene always gives the same image, which still needs confirming.

### Scene input

**Need:** Load scenes designed elsewhere from a file.

> **Q (a classmate):** "Where do your scenes come from, and in what format? What do you do with the images afterwards?"
>
> **A:** "File design to insert."

**My conclusion:** The renderer needs a scene file format. Which one is still open.

### Trust

**Need:** When a bug happens, the team must understand why and be able to fix it.

> **Q (me):** "When you say you want a tool you can trust, what would have to happen for you to stop trusting it?"
>
> **A:** "To trust the solution we want to know why a bug happened and be able to resolve it."

> **Q (a classmate):** "What was the problem with the last software?"
>
> **A:** "Figure anomaly ." (my notes; I understood: being able to detect and handle anomalies)

**My conclusion:** Trust comes from diagnosability: the renderer must detect anomalies, report them clearly, and let the team trace them back to their cause (readable code, tests, clear errors and logs).

### Maintainability and extensibility

**Need:** The studio and its partners must be able to maintain the renderer and add their own features for years.

> **Q (a classmate):** "What would you like to do that you couldn't with your last solution?"
>
> **A:** "Add our own features."

> **Q (me):** "Who will maintain this in five years? What skills will they have?"
>
> **A:** "In-house, long-term, partner skillset."

**My conclusion:** The code will be maintained in-house and extended by partners with varying skill levels, so the architecture must be easy to extend without rewriting the core.

### Open questions

- How long is the film, and at how many frames per second? The performance budget depends on it.
- Does "100 CPU farm" mean 100 machines or 100 cores? The budget changes by about 10×.
- Does "HD" mean 720p or 1080p?
- Does "2 months final rendering" include the 10 pre-renders per image?
- Which renderer did the studio use in Maya, and what went wrong with it?
- Which scene file format, exported from which tool?
- Does "reliable image" mean the same scene must give exactly the same image every time?
- Does "anomaly figure" mean detecting and handling anomalies during a render? What counts as an anomaly: a crash, a wrong pixel, a render that takes too long?

## State of the art

| Solution | Maker | Licence | Pricing (date checked) | Capabilities | Sources |
|---|---|---|---|---|---|
| Arnold | Autodesk | Proprietary, subscription | Not visible on the vendor page; resellers list about $430–476 per seat per year (2026-11-16) | CPU and GPU path tracer, tightly integrated with Maya, widely used in film and VFX | [Autodesk](https://www.autodesk.com/products/arnold/buy), [CDW](https://www.cdw.com/product/arnold-2026-new-subscription-annual-1-seat/8331003) |
| RenderMan | Pixar | Proprietary; free non-commercial licence | $595 per licence + $250 per year maintenance (2026-11-16) | Production path tracer (RIS, XPU for CPU+GPU), used on Pixar films; includes Tractor for render farms | [RenderMan store](https://renderman.pixar.com/store/) |
| V-Ray | Chaos | Proprietary, subscription | Solo about $540 per year, Premium about $719–779 per year; sources disagree (2026-11-16) | CPU and GPU renderer, plug-ins for Maya, 3ds Max, Houdini and others; VFX and architecture | [CG Channel](https://www.cgchannel.com/2025/05/chaos-updates-v-ray-corona-and-enscape-subscription-plans/), [renderahouse](https://www.renderahouse.com/blog/vray-pricing) |
| Redshift | Maxon | Proprietary, subscription | $289 per year in June 2025; no official 2026 price found (2026-11-16) | GPU-first renderer (also runs on CPU), built for speed | [CG Channel](https://www.cgchannel.com/2025/06/maxon-releases-redshift-2025-5/) |
| Cycles | Blender Foundation | Open source (Apache 2.0) | Free | Path tracer built into Blender, CPU and GPU | [blender.org](https://www.blender.org/) |
| pbrt-v4 | Pharr, Jakob, Humphreys | Open source (Apache 2.0) | Free | Research and teaching renderer, documented line by line in the book *Physically Based Rendering* | [pbrt.org](https://pbrt.org/), [GitHub](https://github.com/mmp/pbrt-v4) |
| Mitsuba 3 | EPFL | Open source (BSD 3-Clause) | Free | Research renderer, differentiable rendering | [mitsuba-renderer.org](https://www.mitsuba-renderer.org/) |

Every commercial solution is powerful and proven in film production, but its code is closed: when something breaks, the studio cannot find out why, and it cannot add its own features. These are exactly the two problems the client described ("we want to know why a bug happened", "add our own features"). Licences also add up: on a 100-machine farm, a per-seat price is paid a hundred times. The open-source solutions solve the transparency problem, but they are built for research and teaching (pbrt, Mitsuba) or for one application (Cycles in Blender), not for this studio's pipeline. This explains why the client wants its own renderer: one it owns, can read, and can extend with its partners.

## What is ray tracing?

Ray tracing is a way to create an image by simulating how light travels in a 3D scene. The input is a scene: a camera, objects with their shapes and materials, and lights. For each pixel of the image, the renderer sends a ray from the camera into the scene and looks for the first object it hits. At that point, it works out the colour by checking which lights reach it (if another object is in the way, the point is in shadow) and how the material reacts to light. Then the ray can bounce: off a mirror, through glass, or in a random direction for a matte surface, and the same work starts again from the new point. Since one ray per pixel gives a noisy image, many rays are sent per pixel and averaged. The output is an image file. The cost grows with the resolution, the number of rays per pixel and the number of bounces, which is why rendering a whole film needs a fast renderer and many machines.

**Sources:** I started from [*Ray Tracing in One Weekend*](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley. The reference I would come back to is [*Physically Based Rendering: From Theory to Implementation*](https://pbr-book.org/) by Pharr, Jakob and Humphreys.

## What is C++?

### Programming paradigms

C++ is a multi-paradigm language. It supports procedural programming, object-oriented programming, generic programming (templates) and some functional programming. Compared with languages like JavaScript or Python, C++ is compiled to machine code and statically typed, so many errors are caught at compile time and the program runs much faster. Unlike Java, objects can live directly on the stack instead of always being references on the heap.

### What to watch out for

C++ leaves memory management to the programmer: there is no garbage collector. The classic traps are memory leaks, dangling pointers, reading outside an array, and using uninitialised variables. Many of these are "undefined behaviour": the program may work on one machine and crash on another, which is exactly the kind of bug the client cannot explain today. Copies can also be expensive if objects are passed by value without thinking. The modern answer is RAII: resources are tied to an object's lifetime, and smart pointers and containers free memory automatically. Compiler warnings and tools like sanitizers help find these bugs early.

### Shaping the domain model

The domain model should use the vocabulary of ray tracing, so that the client's team can read the code: classes such as `Vector3`, `Ray`, `Camera`, `Sphere`, `Plane`, `Material`, `Light`, `Scene` and `Image`. Small mathematical types like `Vector3` and `Ray` should be simple value types, copied cheaply and kept on the stack. Shapes share a common interface, so that a partner studio can add a new shape without changing the rest of the renderer, which follows the open/closed principle. Objects should be built by composition: a shape has a material, and a scene has shapes and lights. Ownership should be explicit, for example the scene owns its objects through `std::unique_ptr`, so memory is always freed correctly.

**Sources:** I started from [learncpp.com](https://www.learncpp.com/). The references I would come back to are [cppreference.com](https://en.cppreference.com/) and the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) by Bjarne Stroustrup and Herb Sutter.
