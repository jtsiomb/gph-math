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

#include "vector.h"
#include "matrix.h"

namespace gph {

class Ray {
public:
	Vector3 origin, dir;

	Ray() : dir(0, 0, 1) {}
	Ray(const Vector3 &o, const Vector3 &d) : origin(o), dir(d) {}
};

inline Ray operator *(const Ray &r, const Matrix4x4 &m)
{
	Matrix4x4 up = m;
	up[0][3] = up[1][3] = up[2][3] = up[3][0] = up[3][1] = up[3][2] = 0.0;
	up[3][3] = 1.0;

	return Ray(r.origin * m, r.dir * up);
}

inline Ray operator *(const Matrix4x4 &m, const Ray &r)
{
	Matrix4x4 up = m;
	up[0][3] = up[1][3] = up[2][3] = up[3][0] = up[3][1] = up[3][2] = 0.0;
	up[3][3] = 1.0;

	return Ray(m * r.origin, m * r.dir);
}


inline Ray reflect(const Ray &ray, const Vector3 &n)
{
	return Ray(ray.origin, reflect(ray.dir, n));
}

inline Ray refract(const Ray &ray, const Vector3 &n, float ior)
{
	return Ray(ray.origin, refract(ray.dir, n, ior));
}

inline Ray refract(const Ray &ray, const Vector3 &n, float from_ior, float to_ior)
{
	return Ray(ray.origin, refract(ray.dir, n, from_ior, to_ior));
}


}	// namespace gph

#endif	// GMATH_RAY_H_
