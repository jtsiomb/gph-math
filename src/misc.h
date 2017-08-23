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

#include "config.h"

#include <math.h>
#include "vector.h"

#ifndef M_PI
#define M_PI 3.141592653589793f
#endif

namespace gph {

inline GPH_MATH_API float deg_to_rad(float deg)
{
	return M_PI * deg / 180.0f;
}

inline GPH_MATH_API float rad_to_deg(float rad)
{
	return 180.0f * rad / M_PI;
}

inline GPH_MATH_API float smoothstep(float a, float b, float x)
{
	if(x < a) return 0.0f;
	if(x >= b) return 1.0f;

	x = (x - a) / (b - a);
	return x * x * (3.0f - 2.0f * x);
}

/* linear interpolation */
inline GPH_MATH_API float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

inline GPH_MATH_API float bezier(float a, float b, float c, float d, float t)
{
	float omt, omt3, t3, f;
	t3 = t * t * t;
	omt = 1.0f - t;
	omt3 = omt * omt * omt;
	f = 3 * t * omt;

	return (a * omt3) + (b * f * omt) + (c * f * t) + (d * t3);
}


/* stuff defined in misc.cc */
GPH_MATH_API Vec2 discrand(float rad);
GPH_MATH_API Vec3 sphrand(float rad);
GPH_MATH_API void enable_fpexcept();
GPH_MATH_API void disable_fpexcept();

}	// namespace gph

#endif	// GMATH_MISC_H_
