/*
gph-math - math library for graphics programs
Copyright (C) 2016-2018 John Tsiombikas <nuclear@member.fsf.org>

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
#include "ray.h"

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

inline GPH_MATH_API float bspline(float a, float b, float c, float d, float t)
{
	static const Mat4 mat = Mat4(-1, 3, -3, 1, 3, -6, 0, 4, -3, 3, 3, 1, 1, 0, 0, 0);
	float tsq = t * t;
	Vec4 qfact = Vec4(tsq * t, tsq, t, 1.0f);
	Vec4 tmp = mat * Vec4(a, b, c, d) * (1.0f / 6.0f);
	return dot(tmp, qfact);
}

inline GPH_MATH_API float spline(float a, float b, float c, float d, float t)
{
	static const Mat4 mat = Mat4(-1, 2, -1, 0, 3, -5, 0, 2, -3, 4, 1, 0, 1, -1, 0, 0);
	float tsq = t * t;
	Vec4 qfact = Vec4(tsq * t, tsq, t, 1.0f);
	Vec4 tmp = mat * Vec4(a, b, c, d) * (1.0f / 6.0f);
	return dot(tmp, qfact);
}


/* stuff defined in misc.cc */
GPH_MATH_API Vec2 discrand(float rad);
GPH_MATH_API Vec3 sphrand(float rad);
GPH_MATH_API void enable_fpexcept();
GPH_MATH_API void disable_fpexcept();

GPH_MATH_API Vec3 unproject(const Vec3 &norm_scrpos, const Mat4 &inv_viewproj);
GPH_MATH_API Vec3 unproject(const Vec3 &norm_scrpos, const Mat4 &viewmat, const Mat4 &projmat);
GPH_MATH_API void unproject(float winx, float winy, float winz, const float *view, const float *proj,
		const int *vp, float *objx, float *objy, float *objz);

GPH_MATH_API Ray mouse_pick_ray(float nx, float ny, const Mat4 &viewmat, const Mat4 &projmat);

}	// namespace gph

#endif	// GMATH_MISC_H_
