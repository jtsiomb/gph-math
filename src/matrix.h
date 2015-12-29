#ifndef GMATH_MATRIX_H_
#define GMATH_MATRIX_H_

#include <string.h>
#include "vector.h"

namespace gph {

class Matrix4x4 {
private:
	float m[4][4];

public:
	static Matrix4x4 identity;

	Matrix4x4()
	{
		memcpy((float*)m, (const float*)identity.m, 16 * sizeof(float));
	}

	Matrix4x4(const float *m)
	{
		memcpy((float*)this->m, (const float*)m, 16 * sizeof(float));
	}

	Matrix4x4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}

	Matrix4x4(const Vector4 &v0, const Vector4 &v1, const Vector4 &v2, const Vector4 &v3)
	{
		m[0][0] = v0.x; m[0][1] = v0.y; m[0][2] = v0.z; m[0][3] = v0.w;
		m[1][0] = v1.x; m[1][1] = v1.y; m[1][2] = v1.z; m[1][3] = v1.w;
		m[2][0] = v2.x; m[2][1] = v2.y; m[2][2] = v2.z; m[2][3] = v2.w;
		m[3][0] = v3.x; m[3][1] = v3.y; m[3][2] = v3.z; m[3][3] = v3.w;
	}

	float *operator [](int idx)
	{
		return m[idx];
	}

	const float *operator [](int idx) const
	{
		return m[idx];
	}
};

}	// namespace gph

#endif	// GMATH_MATRIX_H_
