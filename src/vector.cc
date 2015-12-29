#include "vector.h"
#include "matrix.h"

namespace gph {

Vector2::Vector2(const Vector3 &v)
	: x(v.x), y(v.y)
{
}

// ---- Vector3 ----

Vector3::Vector3(const Vector4 &v)
	: x(v.x), y(v.y), z(v.z)
{
}

Vector3 operator *(const Vector3 &v, const Matrix4x4 &m)
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];
	return Vector3(x, y, z);
}

Vector3 operator *(const Matrix4x4 &m, const Vector3 &v)
{
	float x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
	float y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
	float z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];
	return Vector3(x, y, z);
}

// ---- Vector4 ----

Vector4::Vector4(const Vector3 &v)
	: x(v.x), y(v.y), z(v.z), w(1.0f)
{
}

Vector4 operator *(const Vector4 &v, const Matrix4x4 &m)
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + v.w * m[3][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + v.w * m[3][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + v.w * m[3][2];
	float w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + v.w * m[3][3];
	return Vector4(x, y, z, w);
}

Vector4 operator *(const Matrix4x4 &m, const Vector4 &v)
{
	float x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
	float y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
	float z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
	float w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;
	return Vector4(x, y, z, w);
}


}	// namespace gph
