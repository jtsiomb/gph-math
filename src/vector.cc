/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#include "vector.h"
#include "matrix.h"
#include "quat.h"
#include "misc.h"

namespace gph {

// ---- Vec2 ----

Vec2::Vec2(const Vec3 &v)
	: x(v.x), y(v.y)
{
}


Vec2 operator *(const Vec2 &v, const Mat4 &m)
{
	// essentially Vec4(v.x, v.y, 0, 1) * m
	float x = v.x * m[0][0] + v.y * m[0][1] + m[0][3];
	float y = v.x * m[1][0] + v.y * m[1][1] + m[1][3];
	return Vec2(x, y);
}

Vec2 operator *(const Mat4 &m, const Vec2 &v)
{
	// essentially m * Vec4(v.x, v.y, 0, 1)
	float x = m[0][0] * v.x + m[1][0] * v.y + m[3][0];
	float y = m[0][1] * v.x + m[1][1] * v.y + m[3][1];
	return Vec2(x, y);
}



// ---- Vec3 ----

Vec3::Vec3(const Vec4 &v)
	: x(v.x), y(v.y), z(v.z)
{
}

Vec3 operator *(const Vec3 &v, const Mat4 &m)
{
	float x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
	float y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
	float z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
	return Vec3(x, y, z);
}

Vec3 operator *(const Mat4 &m, const Vec3 &v)
{
	float x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0];
	float y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1];
	float z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2];
	return Vec3(x, y, z);
}

Vec3 rotate(const Vec3 &v, const Vec3 &axis, float angle)
{
	Mat4 rmat;
	rmat.rotation(angle, axis);
	return rmat * v;
}

Vec3 rotate(const Vec3 &v, const Quat &q)
{
	Quat vq = Quat(v.x, v.y, v.z, 0.0f);
	vq = q * vq * inverse(q);
	return Vec3(vq.x, vq.y, vq.z);
}

Vec3 rotate(const Vec3 &v, const Vec3 &euler, EulerMode order)
{
	Mat4 rmat;
	rmat.rotation(euler, order);
	return rmat * v;
}


Vec3 bezier(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d, float t)
{
	float x = bezier(a.x, b.x, c.x, d.x, t);
	float y = bezier(a.y, b.y, c.y, d.y, t);
	float z = bezier(a.z, b.z, c.z, d.z, t);
	return Vec3(x, y, z);
}

Vec3 bspline(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d, float t)
{
	float x = bspline(a.x, b.x, c.x, d.x, t);
	float y = bspline(a.y, b.y, c.y, d.y, t);
	float z = bspline(a.z, b.z, c.z, d.z, t);
	return Vec3(x, y, z);
}

Vec3 spline(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d, float t)
{
	float x = spline(a.x, b.x, c.x, d.x, t);
	float y = spline(a.y, b.y, c.y, d.y, t);
	float z = spline(a.z, b.z, c.z, d.z, t);
	return Vec3(x, y, z);
}

// ---- Vec4 ----

Vec4::Vec4(const Vec3 &v)
	: x(v.x), y(v.y), z(v.z), w(1.0f)
{
}

Vec4 operator *(const Vec4 &v, const Mat4 &m)
{
	float x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3];
	float y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3];
	float z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + v.w * m[2][3];
	float w = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + v.w * m[3][3];
	return Vec4(x, y, z, w);
}

Vec4 operator *(const Mat4 &m, const Vec4 &v)
{
	float x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w;
	float y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w;
	float z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2] * v.w;
	float w = m[0][3] * v.x + m[1][3] * v.y + m[2][3] * v.z + m[3][3] * v.w;
	return Vec4(x, y, z, w);
}


Vec4 rotate(const Vec4 &v, const Vec3 &axis, float angle)
{
	Mat4 rmat;
	rmat.rotation(angle, axis);
	return rmat * v;
}

Vec4 rotate(const Vec4 &v, const Quat &q)
{
	Vec3 rv = rotate(v.xyz(), q);
	return Vec4(rv.x, rv.y, rv.z, v.w);
}

Vec4 rotate(const Vec4 &v, const Vec3 &euler, EulerMode order)
{
	Mat4 rmat;
	rmat.rotation(euler, order);
	return rmat * v;
}

}	// namespace gph
