/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#include <string.h>

inline Matrix4x4::Matrix4x4()
{
	memcpy((float*)m, (const float*)identity.m, 16 * sizeof(float));
}

inline Matrix4x4::Matrix4x4(const float *m)
{
	memcpy((float*)this->m, (const float*)m, 16 * sizeof(float));
}

inline Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}

inline Matrix4x4::Matrix4x4(const Vector4 &v0, const Vector4 &v1, const Vector4 &v2, const Vector4 &v3)
{
	m[0][0] = v0.x; m[0][1] = v0.y; m[0][2] = v0.z; m[0][3] = v0.w;
	m[1][0] = v1.x; m[1][1] = v1.y; m[1][2] = v1.z; m[1][3] = v1.w;
	m[2][0] = v2.x; m[2][1] = v2.y; m[2][2] = v2.z; m[2][3] = v2.w;
	m[3][0] = v3.x; m[3][1] = v3.y; m[3][2] = v3.z; m[3][3] = v3.w;
}

inline Matrix4x4::Matrix4x4(const Vector3 &v0, const Vector3 &v1, const Vector3 &v2, const Vector3 &v3)
{
	m[0][0] = v0.x; m[0][1] = v0.y; m[0][2] = v0.z; m[0][3] = 0.0f;
	m[1][0] = v1.x; m[1][1] = v1.y; m[1][2] = v1.z; m[1][3] = 0.0f;
	m[2][0] = v2.x; m[2][1] = v2.y; m[2][2] = v2.z; m[2][3] = 0.0f;
	m[3][0] = v3.x; m[3][1] = v3.y; m[3][2] = v3.z; m[3][3] = 1.0f;
}

inline float *Matrix4x4::operator [](int idx)
{
	return m[idx];
}

inline const float *Matrix4x4::operator [](int idx) const
{
	return m[idx];
}

inline void Matrix4x4::set_row(int idx, const Vector3 &v)
{
	m[idx][0] = v.x;
	m[idx][1] = v.y;
	m[idx][2] = v.z;
	m[idx][3] = 0.0f;
}

inline void Matrix4x4::set_row(int idx, const Vector4 &v)
{
	m[idx][0] = v.x;
	m[idx][1] = v.y;
	m[idx][2] = v.z;
	m[idx][3] = v.w;
}

inline void Matrix4x4::set_column(int idx, const Vector3 &v)
{
	m[0][idx] = v.x;
	m[1][idx] = v.y;
	m[2][idx] = v.z;
	m[3][idx] = 0.0f;
}

inline void Matrix4x4::set_column(int idx, const Vector4 &v)
{
	m[0][idx] = v.x;
	m[1][idx] = v.y;
	m[2][idx] = v.z;
	m[3][idx] = v.w;
}

inline Vector4 Matrix4x4::get_row(int idx) const
{
	return Vector4(m[idx][0], m[idx][1], m[idx][2], m[idx][3]);
}

inline Vector3 Matrix4x4::get_row3(int idx) const
{
	return Vector3(m[idx][0], m[idx][1], m[idx][2]);
}

inline Vector4 Matrix4x4::get_column(int idx) const
{
	return Vector4(m[0][idx], m[1][idx], m[2][idx], m[3][idx]);
}

inline Vector3 Matrix4x4::get_column3(int idx) const
{
	return Vector3(m[0][idx], m[1][idx], m[2][idx]);
}

inline Matrix4x4 Matrix4x4::upper3x3() const
{
	return Matrix4x4(get_row3(0), get_row3(1), get_row3(2));
}

inline void Matrix4x4::transpose()
{
	for(int i=0; i<4; i++) {
		for(int j=0; j<i; j++) {
			float tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
	}
}

inline void Matrix4x4::print(FILE *fp)
{
	for(int i=0; i<4; i++) {
		fprintf(fp, "[ %4.4g %4.4g %4.4g %4.4g ]\n", m[i][0], m[i][1], m[i][2], m[i][3]);
	}
	fputc('\n', fp);
}
