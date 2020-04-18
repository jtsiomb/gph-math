/*
gph-math - math library for graphics programs
Copyright (C) 2016-2018 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef GMATH_VEC_H_
#define GMATH_VEC_H_

#include "config.h"

#include <math.h>
#include "swizzle.h"

#ifdef major
#undef major
#endif

namespace gph {

// define the swizzle macros to emit function prototypes
#define GPH_SWIZZLE2(T, a, b)		inline Vec2 a##b() const;
#define GPH_SWIZZLE3(T, a, b, c)	inline Vec3 a##b##c() const;
#define GPH_SWIZZLE4(T, a, b, c, d)	inline Vec4 a##b##c##d() const;

class Vec3;
class Vec4;
class Mat4;
class Quat;

enum EulerMode {
	EULER_XYZ,
	EULER_XZY,
	EULER_YXZ,
	EULER_YZX,
	EULER_ZXY,
	EULER_ZYX,
	EULER_ZXZ,
	EULER_ZYZ,
	EULER_YXY,
	EULER_YZY,
	EULER_XYX,
	EULER_XZX
};

class GPH_MATH_API Vec2 {
public:
	float x, y;

	Vec2() : x(0), y(0) {}
	Vec2(float x_, float y_) : x(x_), y(y_) {}
	explicit Vec2(const Vec3 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC2_SWIZZLE
};

class GPH_MATH_API Vec3 {
public:
	float x, y, z;

	Vec3() : x(0), y(0), z(0) {}
	Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	explicit Vec3(const Vec4 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC3_SWIZZLE
};


class GPH_MATH_API Vec4 {
public:
	float x, y, z, w;

	Vec4() : x(0), y(0), z(0), w(0) {}
	Vec4(float x_, float y_, float z_, float w_ = 1.0f) : x(x_), y(y_), z(z_), w(w_) {}
	explicit Vec4(const Vec3 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC4_SWIZZLE
};

// ---- Vec2 functions ----
inline GPH_MATH_API Vec2 operator -(const Vec2 &v);
inline GPH_MATH_API Vec2 operator +(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 operator -(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 operator *(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 operator /(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 operator *(const Vec2 &v, float s);
inline GPH_MATH_API Vec2 operator *(float s, const Vec2 &v);
inline GPH_MATH_API Vec2 operator /(const Vec2 &v, float s);
inline GPH_MATH_API Vec2 operator /(float s, const Vec2 &v);
inline GPH_MATH_API Vec2 &operator +=(Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 &operator -=(Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 &operator *=(Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 &operator /=(Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 &operator *=(Vec2 &v, float s);
inline GPH_MATH_API Vec2 &operator /=(Vec2 &v, float s);

GPH_MATH_API Vec2 operator *(const Vec2 &v, const Mat4 &m);
GPH_MATH_API Vec2 operator *(const Mat4 &m, const Vec2 &v);

inline GPH_MATH_API bool operator ==(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API bool operator !=(const Vec2 &a, const Vec2 &b);

inline GPH_MATH_API float dot(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API float length(const Vec2 &v);
inline GPH_MATH_API float length_sq(const Vec2 &v);
inline GPH_MATH_API Vec2 normalize(const Vec2 &v);

inline GPH_MATH_API Vec2 reflect(const Vec2 &v, const Vec2 &n);
inline GPH_MATH_API Vec2 refract(const Vec2 &v, const Vec2 &n, float ior);
inline GPH_MATH_API Vec2 refract(const Vec2 &v, const Vec2 &n, float from_ior, float to_ior);

inline GPH_MATH_API float distance(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API float distance_sq(const Vec2 &a, const Vec2 &b);
inline GPH_MATH_API Vec2 faceforward(const Vec2 &n, const Vec2 &vi, const Vec2 &ng);

inline GPH_MATH_API Vec2 major(const Vec2 &v);
inline GPH_MATH_API int major_idx(const Vec2 &v);
inline GPH_MATH_API Vec2 proj_axis(const Vec2 &v, const Vec2 &axis);

inline GPH_MATH_API Vec2 rotate(const Vec2 &v, float angle);

inline GPH_MATH_API Vec2 lerp(const Vec2 &a, const Vec2 &b, float t);

// ---- Vec3 functions ----
inline GPH_MATH_API Vec3 operator -(const Vec3 &v);
inline GPH_MATH_API Vec3 operator +(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 operator -(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 operator *(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 operator /(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 operator *(const Vec3 &v, float s);
inline GPH_MATH_API Vec3 operator *(float s, const Vec3 &v);
inline GPH_MATH_API Vec3 operator /(const Vec3 &v, float s);
inline GPH_MATH_API Vec3 operator /(float s, const Vec3 &v);
inline GPH_MATH_API Vec3 &operator +=(Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 &operator -=(Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 &operator *=(Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 &operator /=(Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 &operator *=(Vec3 &v, float s);
inline GPH_MATH_API Vec3 &operator /=(Vec3 &v, float s);

GPH_MATH_API Vec3 operator *(const Vec3 &v, const Mat4 &m);
GPH_MATH_API Vec3 operator *(const Mat4 &m, const Vec3 &v);

inline GPH_MATH_API bool operator ==(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API bool operator !=(const Vec3 &a, const Vec3 &b);

inline GPH_MATH_API float dot(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 cross(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API float length(const Vec3 &v);
inline GPH_MATH_API float length_sq(const Vec3 &v);
inline GPH_MATH_API Vec3 normalize(const Vec3 &v);

inline GPH_MATH_API Vec3 reflect(const Vec3 &v, const Vec3 &n);
inline GPH_MATH_API Vec3 refract(const Vec3 &v, const Vec3 &n, float ior);
inline GPH_MATH_API Vec3 refract(const Vec3 &v, const Vec3 &n, float from_ior, float to_ior);

inline GPH_MATH_API float distance(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API float distance_sq(const Vec3 &a, const Vec3 &b);
inline GPH_MATH_API Vec3 faceforward(const Vec3 &n, const Vec3 &vi, const Vec3 &ng);

inline GPH_MATH_API Vec3 major(const Vec3 &v);
inline GPH_MATH_API int major_idx(const Vec3 &v);
inline GPH_MATH_API Vec3 proj_axis(const Vec3 &v, const Vec3 &axis);

GPH_MATH_API Vec3 rotate(const Vec3 &v, const Quat &q);
GPH_MATH_API Vec3 rotate(const Vec3 &v, const Vec3 &axis, float angle);
GPH_MATH_API Vec3 rotate(const Vec3 &v, const Vec3 &euler, EulerMode mode = EULER_XYZ);

inline GPH_MATH_API Vec3 lerp(const Vec3 &a, const Vec3 &b, float t);
GPH_MATH_API Vec3 bezier(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d, float t);
GPH_MATH_API Vec3 bspline(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d, float t);
GPH_MATH_API Vec3 spline(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d, float t);

// ---- Vec4 functions ----
inline GPH_MATH_API Vec4 operator -(const Vec4 &v);
inline GPH_MATH_API Vec4 operator +(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 operator -(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 operator *(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 operator /(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 operator *(const Vec4 &v, float s);
inline GPH_MATH_API Vec4 operator *(float s, const Vec4 &v);
inline GPH_MATH_API Vec4 operator /(const Vec4 &v, float s);
inline GPH_MATH_API Vec4 operator /(float s, const Vec4 &v);
inline GPH_MATH_API Vec4 &operator +=(Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 &operator -=(Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 &operator *=(Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 &operator /=(Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 &operator *=(Vec4 &v, float s);
inline GPH_MATH_API Vec4 &operator /=(Vec4 &v, float s);

GPH_MATH_API Vec4 operator *(const Vec4 &v, const Mat4 &m);
GPH_MATH_API Vec4 operator *(const Mat4 &m, const Vec4 &v);

inline GPH_MATH_API bool operator ==(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API bool operator !=(const Vec4 &a, const Vec4 &b);

inline GPH_MATH_API float dot(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 cross(const Vec4 &a, const Vec4 &b, const Vec4 &c);
inline GPH_MATH_API float length(const Vec4 &v);
inline GPH_MATH_API float length_sq(const Vec4 &v);
inline GPH_MATH_API Vec4 normalize(const Vec4 &v);

inline GPH_MATH_API Vec4 reflect(const Vec4 &v, const Vec4 &n);
inline GPH_MATH_API Vec4 refract(const Vec4 &v, const Vec4 &n, float ior);
inline GPH_MATH_API Vec4 refract(const Vec4 &v, const Vec4 &n, float from_ior, float to_ior);

inline GPH_MATH_API float distance(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API float distance_sq(const Vec4 &a, const Vec4 &b);
inline GPH_MATH_API Vec4 faceforward(const Vec4 &n, const Vec4 &vi, const Vec4 &ng);

inline GPH_MATH_API Vec4 major(const Vec4 &v);
inline GPH_MATH_API int major_idx(const Vec4 &v);
inline GPH_MATH_API Vec4 proj_axis(const Vec4 &v, const Vec4 &axis);

GPH_MATH_API Vec4 rotate(const Vec4 &v, const Quat &q);
inline GPH_MATH_API Vec4 rotate(const Vec4 &v, const Vec3 &axis, float angle);
inline GPH_MATH_API Vec4 rotate(const Vec4 &v, const Vec3 &euler, EulerMode mode = EULER_XYZ);

inline GPH_MATH_API Vec4 lerp(const Vec4 &a, const Vec4 &b, float t);

// include definitions of all the inline GPH_MATH_API functions above
#include "vector2.inl"
#include "vector3.inl"
#include "vector4.inl"

// change the swizzle macros to spit out the function definitions and invoke them
#undef GPH_SWIZZLE2
#undef GPH_SWIZZLE3
#undef GPH_SWIZZLE4
#define GPH_SWIZZLE2(T, a, b)		inline Vec2 T::a##b() const { return Vec2(a, b); }
#define GPH_SWIZZLE3(T, a, b, c)	inline Vec3 T::a##b##c() const { return Vec3(a, b, c); }
#define GPH_SWIZZLE4(T, a, b, c, d)	inline Vec4 T::a##b##c##d() const { return Vec4(a, b, c, d); }
GPH_VEC2_SWIZZLE
GPH_VEC3_SWIZZLE
GPH_VEC4_SWIZZLE

}

#endif	/* GMATH_VEC_H_ */
