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

namespace gph {

// ---- Vector2 ----

Vector2::Vector2(const Vector3 &v)
	: x(v.x), y(v.y)
{
}


Vector2 operator *(const Vector2 &v, const Matrix4x4 &m)
{
	// essentially Vector4(v.x, v.y, 0, 1) * m
	float x = v.x * m[0][0] + v.y * m[0][1] + m[0][3];
	float y = v.x * m[1][0] + v.y * m[1][1] + m[1][3];
	return Vector2(x, y);
}

Vector2 operator *(const Matrix4x4 &m, const Vector2 &v)
{
	// essentially m * Vector4(v.x, v.y, 0, 1)
	float x = m[0][0] * v.x + m[1][0] * v.y + m[3][0];
	float y = m[0][1] * v.x + m[1][1] * v.y + m[3][1];
	return Vector2(x, y);
}



// ---- Vector3 ----

Vector3::Vector3(const Vector4 &v)
	: x(v.x), y(v.y), z(v.z)
{
}

Vector3 operator *(const Vector3 &v, const Matrix4x4 &m)
{
	float x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
	float y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
	float z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
	return Vector3(x, y, z);
}

Vector3 operator *(const Matrix4x4 &m, const Vector3 &v)
{
	float x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0];
	float y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1];
	float z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2];
	return Vector3(x, y, z);
}

// ---- Vector4 ----

Vector4::Vector4(const Vector3 &v)
	: x(v.x), y(v.y), z(v.z), w(1.0f)
{
}

Vector4 operator *(const Vector4 &v, const Matrix4x4 &m)
{
	float x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3];
	float y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3];
	float z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + v.w * m[2][3];
	float w = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + v.w * m[3][3];
	return Vector4(x, y, z, w);
}

Vector4 operator *(const Matrix4x4 &m, const Vector4 &v)
{
	float x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w;
	float y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w;
	float z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2] * v.w;
	float w = m[0][3] * v.x + m[1][3] * v.y + m[2][3] * v.z + m[3][3] * v.w;
	return Vector4(x, y, z, w);
}


}	// namespace gph
