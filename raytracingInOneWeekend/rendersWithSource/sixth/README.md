my original spher intersection test was normalizing the ray direction to simplify the quadratic (A = 1)
This resulted in strange behavior when using the dot product to determine the direction of the surface normal (rim color inversion)
I have no idea why this isn't working and I definitely want to squash this bug later at some point.