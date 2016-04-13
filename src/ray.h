/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef GMATH_RAY_H_
#define GMATH_RAY_H_

#include "config.h"

#include "vector.h"
#include "matrix.h"

namespace gph {

class GPH_MATH_API Ray {
public:
	Vec3 origin, dir;

	Ray() : dir(0, 0, 1) {}
	Ray(const Vec3 &o, const Vec3 &d) : origin(o), dir(d) {}
};

inline GPH_MATH_API Ray operator *(const Ray &r, const Mat4 &m)
{
	Mat4 up = m.upper3x3();
	return Ray(r.origin * m, r.dir * up);
}

inline GPH_MATH_API Ray operator *(const Mat4 &m, const Ray &r)
{
	Mat4 up = m.upper3x3();
	return Ray(m * r.origin, up * r.dir);
}


inline GPH_MATH_API Ray reflect(const Ray &ray, const Vec3 &n)
{
	return Ray(ray.origin, reflect(ray.dir, n));
}

inline GPH_MATH_API Ray refract(const Ray &ray, const Vec3 &n, float ior)
{
	return Ray(ray.origin, refract(ray.dir, n, ior));
}

inline GPH_MATH_API Ray refract(const Ray &ray, const Vec3 &n, float from_ior, float to_ior)
{
	return Ray(ray.origin, refract(ray.dir, n, from_ior, to_ior));
}


}	// namespace gph

#endif	// GMATH_RAY_H_
