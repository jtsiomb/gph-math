#ifndef GMATH_RAY_H_
#define GMATH_RAY_H_

#include "vector.h"
#include "matrix.h"

namespace gph {

class Ray {
public:
	Vector3 origin, dir;

	Ray() : dir(0, 0, 1) {}
	Ray(const Vector3 &o, const Vector3 &d) : o(origin), d(dir) {}
};

inline Ray operator *(const Ray &r, const Matrix4x4 &m)
{
	Matrix4x4 up = m;
	up[0][3] = up[1][3] = up[2][3] = up[3][0] = up[3][1] = up[3][2] = 0.0;
	up[3][3] = 1.0;

	return Ray(origin * m, dir * up);
}

inline Ray operator *(const Matrix4x4 &m, const Ray &r)
{
	Matrix4x4 up = m;
	up[0][3] = up[1][3] = up[2][3] = up[3][0] = up[3][1] = up[3][2] = 0.0;
	up[3][3] = 1.0;

	return Ray(m * origin, m * dir);
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


}

#endif	// GMATH_RAY_H_
