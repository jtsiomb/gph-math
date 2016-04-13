/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "config.h"

#include "vector.h"
#include "matrix.h"

namespace gph {

class GPH_MATH_API Quat {
public:
	float x, y, z, w;	// w + xi + yj + zk

	static Quat identity;

	Quat() : x(0), y(0), z(0), w(1) {}
	Quat(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	Quat(const Vec3 &v, float s) : x(v.x), y(v.y), z(v.z), w(s) {}

	inline void normalize();
	inline void conjugate();
	inline void invert();

	inline void set_rotation(const Vec3 &axis, float angle);
	inline void rotate(const Vec3 &axis, float angle);
	// rotate by a quaternion rq by doing: rq * *this * conjugate(rq)
	inline void rotate(const Quat &rq);

	inline Mat4 calc_matrix() const;
};

inline GPH_MATH_API Quat operator -(const Quat &q);
inline GPH_MATH_API Quat operator +(const Quat &a, const Quat &b);
inline GPH_MATH_API Quat operator -(const Quat &a, const Quat &b);
inline GPH_MATH_API Quat operator *(const Quat &a, const Quat &b);

inline GPH_MATH_API Quat &operator +=(Quat &a, const Quat &b);
inline GPH_MATH_API Quat &operator -=(Quat &a, const Quat &b);
inline GPH_MATH_API Quat &operator *=(Quat &a, const Quat &b);

inline GPH_MATH_API float length(const Quat &q);
inline GPH_MATH_API float length_sq(const Quat &q);

inline GPH_MATH_API Quat normalize(const Quat &q);
inline GPH_MATH_API Quat conjugate(const Quat &q);
inline GPH_MATH_API Quat inverse(const Quat &q);

Quat GPH_MATH_API slerp(const Quat &a, const Quat &b, float t);
inline GPH_MATH_API Quat lerp(const Quat &a, const Quat &b, float t);

#include "quat.inl"

}	// namespace gph

#endif	// QUATERNION_H_
