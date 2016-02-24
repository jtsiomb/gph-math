/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef GMATH_VEC_H_
#define GMATH_VEC_H_

#include <math.h>
#include "swizzle.h"

namespace gph {

// define the swizzle macros to emit function prototypes
#define GPH_SWIZZLE2(T, a, b)		inline Vec2 a##b() const;
#define GPH_SWIZZLE3(T, a, b, c)	inline Vec3 a##b##c() const;
#define GPH_SWIZZLE4(T, a, b, c, d)	inline Vec4 a##b##c##d() const;

class Vec3;
class Vec4;
class Mat4;
class Quat;

class Vec2 {
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

class Vec3 {
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


class Vec4 {
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
inline Vec2 operator -(const Vec2 &v);
inline Vec2 operator +(const Vec2 &a, const Vec2 &b);
inline Vec2 operator -(const Vec2 &a, const Vec2 &b);
inline Vec2 operator *(const Vec2 &a, const Vec2 &b);
inline Vec2 operator /(const Vec2 &a, const Vec2 &b);
inline Vec2 operator *(const Vec2 &v, float s);
inline Vec2 operator *(float s, const Vec2 &v);
inline Vec2 operator /(const Vec2 &v, float s);
inline Vec2 operator /(float s, const Vec2 &v);
inline Vec2 &operator +=(Vec2 &a, const Vec2 &b);
inline Vec2 &operator -=(Vec2 &a, const Vec2 &b);
inline Vec2 &operator *=(Vec2 &a, const Vec2 &b);
inline Vec2 &operator /=(Vec2 &a, const Vec2 &b);
inline Vec2 &operator *=(Vec2 &v, float s);
inline Vec2 &operator /=(Vec2 &v, float s);

Vec2 operator *(const Vec2 &v, const Mat4 &m);
Vec2 operator *(const Mat4 &m, const Vec2 &v);

inline bool operator ==(const Vec2 &a, const Vec2 &b);
inline bool operator !=(const Vec2 &a, const Vec2 &b);

inline float dot(const Vec2 &a, const Vec2 &b);
inline float length(const Vec2 &v);
inline float length_sq(const Vec2 &v);
inline Vec2 normalize(const Vec2 &v);

inline Vec2 reflect(const Vec2 &v, const Vec2 &n);
inline Vec2 refract(const Vec2 &v, const Vec2 &n, float ior);
inline Vec2 refract(const Vec2 &v, const Vec2 &n, float from_ior, float to_ior);

inline float distance(const Vec2 &a, const Vec2 &b);
inline float distance_sq(const Vec2 &a, const Vec2 &b);
inline Vec2 faceforward(const Vec2 &n, const Vec2 &vi, const Vec2 &ng);

inline Vec2 major(const Vec2 &v);
inline int major_idx(const Vec2 &v);
inline Vec2 proj_axis(const Vec2 &v, const Vec2 &axis);

inline Vec2 rotate(const Vec2 &v, float angle);

// ---- Vec3 functions ----
inline Vec3 operator -(const Vec3 &v);
inline Vec3 operator +(const Vec3 &a, const Vec3 &b);
inline Vec3 operator -(const Vec3 &a, const Vec3 &b);
inline Vec3 operator *(const Vec3 &a, const Vec3 &b);
inline Vec3 operator /(const Vec3 &a, const Vec3 &b);
inline Vec3 operator *(const Vec3 &v, float s);
inline Vec3 operator *(float s, const Vec3 &v);
inline Vec3 operator /(const Vec3 &v, float s);
inline Vec3 operator /(float s, const Vec3 &v);
inline Vec3 &operator +=(Vec3 &a, const Vec3 &b);
inline Vec3 &operator -=(Vec3 &a, const Vec3 &b);
inline Vec3 &operator *=(Vec3 &a, const Vec3 &b);
inline Vec3 &operator /=(Vec3 &a, const Vec3 &b);
inline Vec3 &operator *=(Vec3 &v, float s);
inline Vec3 &operator /=(Vec3 &v, float s);

Vec3 operator *(const Vec3 &v, const Mat4 &m);
Vec3 operator *(const Mat4 &m, const Vec3 &v);

inline bool operator ==(const Vec3 &a, const Vec3 &b);
inline bool operator !=(const Vec3 &a, const Vec3 &b);

inline float dot(const Vec3 &a, const Vec3 &b);
inline Vec3 cross(const Vec3 &a, const Vec3 &b);
inline float length(const Vec3 &v);
inline float length_sq(const Vec3 &v);
inline Vec3 normalize(const Vec3 &v);

inline Vec3 reflect(const Vec3 &v, const Vec3 &n);
inline Vec3 refract(const Vec3 &v, const Vec3 &n, float ior);
inline Vec3 refract(const Vec3 &v, const Vec3 &n, float from_ior, float to_ior);

inline float distance(const Vec3 &a, const Vec3 &b);
inline float distance_sq(const Vec3 &a, const Vec3 &b);
inline Vec3 faceforward(const Vec3 &n, const Vec3 &vi, const Vec3 &ng);

inline Vec3 major(const Vec3 &v);
inline int major_idx(const Vec3 &v);
inline Vec3 proj_axis(const Vec3 &v, const Vec3 &axis);

inline Vec3 rotate(const Vec3 &v, const Quat &q);
inline Vec3 rotate(const Vec3 &v, const Vec3 &axis, float angle);
inline Vec3 rotate(const Vec3 &v, const Vec3 &euler);


// ---- Vec4 functions ----
inline Vec4 operator -(const Vec4 &v);
inline Vec4 operator +(const Vec4 &a, const Vec4 &b);
inline Vec4 operator -(const Vec4 &a, const Vec4 &b);
inline Vec4 operator *(const Vec4 &a, const Vec4 &b);
inline Vec4 operator /(const Vec4 &a, const Vec4 &b);
inline Vec4 operator *(const Vec4 &v, float s);
inline Vec4 operator *(float s, const Vec4 &v);
inline Vec4 operator /(const Vec4 &v, float s);
inline Vec4 operator /(float s, const Vec4 &v);
inline Vec4 &operator +=(Vec4 &a, const Vec4 &b);
inline Vec4 &operator -=(Vec4 &a, const Vec4 &b);
inline Vec4 &operator *=(Vec4 &a, const Vec4 &b);
inline Vec4 &operator /=(Vec4 &a, const Vec4 &b);
inline Vec4 &operator *=(Vec4 &v, float s);
inline Vec4 &operator /=(Vec4 &v, float s);

Vec4 operator *(const Vec4 &v, const Mat4 &m);
Vec4 operator *(const Mat4 &m, const Vec4 &v);

inline bool operator ==(const Vec4 &a, const Vec4 &b);
inline bool operator !=(const Vec4 &a, const Vec4 &b);

inline float dot(const Vec4 &a, const Vec4 &b);
inline Vec4 cross(const Vec4 &a, const Vec4 &b, const Vec4 &c);
inline float length(const Vec4 &v);
inline float length_sq(const Vec4 &v);
inline Vec4 normalize(const Vec4 &v);

inline Vec4 reflect(const Vec4 &v, const Vec4 &n);
inline Vec4 refract(const Vec4 &v, const Vec4 &n, float ior);
inline Vec4 refract(const Vec4 &v, const Vec4 &n, float from_ior, float to_ior);

inline float distance(const Vec4 &a, const Vec4 &b);
inline float distance_sq(const Vec4 &a, const Vec4 &b);
inline Vec4 faceforward(const Vec4 &n, const Vec4 &vi, const Vec4 &ng);

inline Vec4 major(const Vec4 &v);
inline int major_idx(const Vec4 &v);
inline Vec4 proj_axis(const Vec4 &v, const Vec4 &axis);

inline Vec4 rotate(const Vec4 &v, const Quat &q);
inline Vec4 rotate(const Vec4 &v, const Vec4 &axis, float angle);
inline Vec4 rotate(const Vec4 &v, const Vec4 &euler);

// include definitions of all the inline functions above
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
