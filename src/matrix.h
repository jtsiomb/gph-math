/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef GMATH_MATRIX_H_
#define GMATH_MATRIX_H_

#include <stdio.h>
#include "vector.h"

namespace gph {

class Mat4 {
private:
	float m[4][4];

public:
	static Mat4 identity;

	inline Mat4();
	inline Mat4(const float *m);
	inline Mat4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
	inline Mat4(const Vec4 &v0, const Vec4 &v1, const Vec4 &v2, const Vec4 &v3);
	inline Mat4(const Vec3 &v0, const Vec3 &v1, const Vec3 &v2, const Vec3 &v3 = Vec3(0, 0, 0));

	inline float *operator [](int idx);
	inline const float *operator [](int idx) const;

	inline void set_row(int idx, const Vec3 &v);
	inline void set_row(int idx, const Vec4 &v);
	inline void set_column(int idx, const Vec3 &v);
	inline void set_column(int idx, const Vec4 &v);
	inline Vec4 get_row(int idx) const;
	inline Vec3 get_row3(int idx) const;
	inline Vec4 get_column(int idx) const;
	inline Vec3 get_column3(int idx) const;

	inline Mat4 upper3x3() const;

	inline void transpose();
	inline void inverse();

	/* translation/rotation/scaling functions construct a transformation
	 * matrix of the appropriate type, discarding any previous contents
	 */
	inline void translation(float x, float y, float z);
	inline void translation(const Vec3 &v);
	inline void scaling(float s);
	inline void scaling(float x, float y, float z);
	inline void scaling(const Vec3 &v);
	// fixed axis rotation
	inline void rotation_x(float angle);
	inline void rotation_y(float angle);
	inline void rotation_z(float angle);
	// axis-angle rotation
	inline void rotation(float angle, float x, float y, float z);
	inline void rotation(float angle, const Vec3 &axis);
	// euler angles rotation
	inline void rotation(float x, float y, float z);
	inline void rotation(const Vec3 &euler);
	// rotation by quaternion
	inline void rotation(const Quat &q);

	/* translate/rotate/scale functions construct a temporary
	 * transformation matrix of the appropriate type, and multiply
	 * it to this matrix
	 */
	inline void translate(float x, float y, float z);
	inline void translate(const Vec3 &v);
	inline void scale(float s);
	inline void scale(float x, float y, float z);
	inline void scale(const Vec3 &v);
	// fixed axis rotate
	inline void rotate_x(float angle);
	inline void rotate_y(float angle);
	inline void rotate_z(float angle);
	// axis-angle rotate
	inline void rotate(float angle, float x, float y, float z);
	inline void rotate(float angle, const Vec3 &axis);
	// euler angles rotate
	inline void rotate(float x, float y, float z);
	inline void rotate(const Vec3 &euler);
	// rotate by quaternion
	inline void rotate(const Quat &q);

	// construct a lookat transformation
	inline void lookat(const Vec3 &pos, const Vec3 &targ, const Vec3 &up = Vec3(0, 1, 0));
	// inverse lookat for camera lookat matrix (like gluLookAt)
	inline void inv_lookat(const Vec3 &pos, const Vec3 &targ, const Vec3 &up = Vec3(0, 1, 0));

	// construct an orthographic projection matrix
	inline void ortho(float left, float right, float bottom, float top, float znear, float zfar);
	// construct a perspective projection matrix
	inline void frustum(float left, float right, float bottom, float top, float znear, float zfar);
	inline void perspective(float fov, float aspect, float znear, float zfar);

	inline void print(FILE *fp = stdout);
};

inline Mat4 operator *(const Mat4 &a, const Mat4 &b);
inline Mat4 &operator *=(Mat4 &a, const Mat4 &b);

inline float determinant(const Mat4 &m);
inline Mat4 transpose(const Mat4 &m);
inline Mat4 cofactor_matrix(const Mat4 &m);
inline Mat4 inverse(const Mat4 &m);

#include "matrix.inl"

}	// namespace gph

#endif	// GMATH_MATRIX_H_
