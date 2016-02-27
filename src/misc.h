/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef GMATH_MISC_H_
#define GMATH_MISC_H_

#include <math.h>
#include "vector.h"

#ifndef M_PI
#define M_PI 3.141592653589793f
#endif

namespace gph {

inline float deg_to_rad(float deg)
{
	return M_PI * deg / 180.0f;
}

inline float rad_to_deg(float rad)
{
	return 180.0f * rad / M_PI;
}

inline float smoothstep(float a, float b, float x)
{
	if(x < a) return 0.0f;
	if(x >= b) return 1.0f;

	x = (x - a) / (b - a);
	return x * x * (3.0f - 2.0f * x);
}

/* linear interpolation */
inline float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}


/* stuff defined in misc.cc */
Vec3 sphrand(float rad);
void enable_fpexcept();
void disable_fpexcept();

}	// namespace gph

#endif	// GMATH_MISC_H_
