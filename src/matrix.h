/*
gph-math - math library for graphics programs
Copyright (C) 2016-2018 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef GMATH_MATRIX_H_
#define GMATH_MATRIX_H_

#include "config.h"

#include <stdio.h>
#include <string.h>
#include "vector.h"

/* NOTE:
 * matrices are treated by all operations as column-major, to match OpenGL
 * conventions, so everything is pretty much transposed. Hopefully I managed
 * to maintain consistency.
 */

namespace gph {

/* argument to Mat4::get_frustum_plane */
enum {
	FRUSTUM_LEFT, FRUSTUM_RIGHT, FRUSTUM_BOTTOM, FRUSTUM_TOP, FRUSTUM_NEAR, FRUSTUM_FAR
};

class GPH_MATH_API Mat2 {
public:
	float m[2][2];

	static Mat2 identity;

	inline Mat2();
	inline Mat2(float m00, float m01, float m10, float m11);

	inline float *operator [](int idx);
	inline const float *operator [](int idx) const;

	inline float determinant() const;
};

class GPH_MATH_API Mat3 {
public:
	float m[3][3];

	static Mat3 identity;

	inline Mat3();
	inline Mat3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22);

	inline float *operator [](int idx);
	inline const float *operator [](int idx) const;

	inline Mat2 submatrix(int row, int col) const;
	inline float subdet(int row, int col) const;
	inline float determinant() const;
};


class GPH_MATH_API Mat4 {
public:
	float m[4][4];

	static Mat4 zero;
	static Mat4 identity;

	inline Mat4();
	inline Mat4(const float *m);
	inline Mat4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
	inline Mat4(const Vec4 &v0, const Vec4 &v1, const Vec4 &v2, const Vec4 &v3);
	inline Mat4(const Vec3 &v0, const Vec3 &v1, const Vec3 &v2, const Vec3 &v3 = Vec3(0, 0, 0));

	inline Mat3 submatrix(int row, int col) const;

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

	inline float subdet(int row, int col) const;
	inline float cofactor(int row, int col) const;
	inline float determinant() const;

	inline void transpose();
	inline bool inverse();

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
	inline void rotation_axis(int idx, float angle);
	// axis-angle rotation
	inline void rotation(float angle, float x, float y, float z);
	inline void rotation(float angle, const Vec3 &axis);
	// euler angles rotation
	inline void rotation(float a, float b, float c, EulerMode mode = EULER_XYZ);
	inline void rotation(const Vec3 &euler, EulerMode mode = EULER_XYZ);
	// rotation by quaternion
	void rotation(const Quat &q);

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
	inline void rotate_axis(int idx, float angle);
	// axis-angle rotate
	inline void rotate(float angle, float x, float y, float z);
	inline void rotate(float angle, const Vec3 &axis);
	// euler angles rotate
	inline void rotate(float x, float y, float z, EulerMode mode = EULER_XYZ);
	inline void rotate(const Vec3 &euler, EulerMode mode = EULER_XYZ);
	// rotate by quaternion
	inline void rotate(const Quat &q);

	/* translate/rotate/scale functions construct a temporary
	 * transformation matrix of the appropriate type, and pre-multiply
	 * it to this matrix exactly like glTranslate/glRotate/glScale
	 */
	inline void pre_translate(float x, float y, float z);
	inline void pre_translate(const Vec3 &v);
	inline void pre_scale(float s);
	inline void pre_scale(float x, float y, float z);
	inline void pre_scale(const Vec3 &v);
	// fixed axis rotate
	inline void pre_rotate_x(float angle);
	inline void pre_rotate_y(float angle);
	inline void pre_rotate_z(float angle);
	inline void pre_rotate_axis(int idx, float angle);
	// axis-angle rotate
	inline void pre_rotate(float angle, float x, float y, float z);
	inline void pre_rotate(float angle, const Vec3 &axis);
	// euler angles rotate
	inline void pre_rotate(float x, float y, float z, EulerMode mode = EULER_XYZ);
	inline void pre_rotate(const Vec3 &euler, EulerMode mode = EULER_XYZ);
	// rotate by quaternion
	inline void pre_rotate(const Quat &q);

	inline Vec3 get_translation() const;
	Quat get_rotation() const;
	inline Vec3 get_scaling() const;

	// extract each one of the 6 frustum planes from a projection matrix
	inline Vec4 get_frustum_plane(int p) const;

	// construct a lookat transformation
	inline void lookat(const Vec3 &pos, const Vec3 &targ, const Vec3 &up = Vec3(0, 1, 0));
	// inverse lookat for camera lookat matrix (like gluLookAt)
	inline void inv_lookat(const Vec3 &pos, const Vec3 &targ, const Vec3 &up = Vec3(0, 1, 0));

	// construct an orthographic projection matrix
	inline void ortho(float left, float right, float bottom, float top, float znear, float zfar);
	// construct a perspective projection matrix
	inline void frustum(float left, float right, float bottom, float top, float znear, float zfar);
	inline void perspective(float fov, float aspect, float znear, float zfar);

	// construct a mirror matrix about an arbitrary plane
	inline void mirror(float a, float b, float c, float d);
	inline void mirror(const Vec3 &n, float d);

	inline void print(FILE *fp = 0) const;
};

inline GPH_MATH_API Mat4 operator *(const Mat4 &a, const Mat4 &b);
inline GPH_MATH_API Mat4 &operator *=(Mat4 &a, const Mat4 &b);

inline GPH_MATH_API Mat4 operator *(const Mat4 &m, float s);
inline GPH_MATH_API Mat4 operator *(float s, const Mat4 &m);

inline GPH_MATH_API float determinant(const Mat4 &m);
inline GPH_MATH_API Mat4 transpose(const Mat4 &m);
inline GPH_MATH_API Mat4 cofactor_matrix(const Mat4 &m);
inline GPH_MATH_API Mat4 inverse(const Mat4 &m);

inline GPH_MATH_API Vec4 normalize_plane(const Vec4 &p);

#include "matrix.inl"

}	// namespace gph

#endif	// GMATH_MATRIX_H_
