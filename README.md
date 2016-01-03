gph-math: graphene math library
===============================

About
-----
Gph-math is a C++ math library for graphics programs. It's been written as part
of the [graphene 3d engine](http://github.com/MutantStargoat/graphene) project,
but it's really a standalone reusable math library with no further ties to
graphene other than the namespace "gph".

I intend to use this library for all my C++ graphics projects from now on,
superseding [libvmath](http://github.com/jtsiomb/libvmath), which I've been
using and evolving since the start of the century.

Inspired by other modern math libraries like glm, gph-math follows the GLSL
conventions wherever it makes sense, and doesn't clash with my code style,
including the very elegant swizzle mechanism for conversions between vector
types.

License
-------
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute it
under the terms of the MIT/X11 license. See LICENSE for details.
