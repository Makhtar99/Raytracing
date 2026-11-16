# Discovery report

## Problem statement

[One sentence.]

## Client interview summary

### Current situation

**Need:** Replace the tool the studio used before.

> **Q (me):** "What do you render with today, and what made you decide you need a new one?"
>
> **A:** "Solution before: Maya."

**My conclusion:** The studio comes from a commercial tool. I still need to know which renderer it used inside Maya and what went wrong with it.

### Delivery

**Need:** A working solution delivered by early January.

> **Q (a classmate):** "When should the projet be finalized"
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

> **Q (a classmate):** "Waht was the problem on the last software ?"
>
> **A:** "Figure anomaly ." (my notes; I understood: being able to detect and handle anomalies)

**My conclusion:** Trust comes from diagnosability: the renderer must detect anomalies, report them clearly, and let the team trace them back to their cause (readable code, tests, clear errors and logs).

### Maintainability and extensibility

**Need:** The studio and its partners must be able to maintain the renderer and add their own features for years.

> **Q (a classmate):** "What would you like to do that you couldn't on your last solution ?"
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
|   |   |   |   |   |   |

[A few lines: what do you conclude from this table?]

## What is ray tracing?

[One paragraph, in your own words.]

**Sources:** [What you started from and the reference you would come back to, with links.]

## What is C++?

### Programming paradigms

[Your first understanding.]

### What to watch out for

[Your first understanding.]

### Shaping the domain model

[Your first understanding.]

**Sources:** [What you started from and the reference you would come back to, with links.]
