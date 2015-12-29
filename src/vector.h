#ifndef GMATH_VEC_H_
#define GMATH_VEC_H_

#include <math.h>
#include "swizzle.h"

namespace gph {

#define GPH_SWIZZLE2(T, a, b)		inline Vector2 a##b() const;
#define GPH_SWIZZLE3(T, a, b, c)	inline Vector3 a##b##c() const;
#define GPH_SWIZZLE4(T, a, b, c, d)	inline Vector4 a##b##c##d() const;

class Vector3;
class Vector4;
class Matrix4x4;
class Quaternion;

class Vector2 {
public:
	float x, y;

	Vector2() : x(0), y(0) {}
	Vector2(float x_, float y_) : x(x_), y(y_) {}
	Vector2(const Vector3 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC2_SWIZZLE
};

class Vector3 {
public:
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}
	Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	Vector3(const Vector4 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC3_SWIZZLE
};


class Vector4 {
public:
	float x, y, z, w;

	Vector4() : x(0), y(0), z(0), w(0) {}
	Vector4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	Vector4(const Vector3 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC4_SWIZZLE
};

// ---- Vector3 functions ----
inline Vector3 operator -(const Vector3 &v);
inline Vector3 operator +(const Vector3 &a, const Vector3 &b);
inline Vector3 operator -(const Vector3 &a, const Vector3 &b);
inline Vector3 operator *(const Vector3 &a, const Vector3 &b);
inline Vector3 operator /(const Vector3 &a, const Vector3 &b);
inline Vector3 operator *(const Vector3 &v, float s);
inline Vector3 operator *(float s, const Vector3 &v);
inline Vector3 operator /(const Vector3 &v, float s);
inline Vector3 operator /(float s, const Vector3 &v);
inline Vector3 &operator +=(Vector3 &a, const Vector3 &b);
inline Vector3 &operator -=(Vector3 &a, const Vector3 &b);
inline Vector3 &operator *=(Vector3 &a, const Vector3 &b);
inline Vector3 &operator /=(Vector3 &a, const Vector3 &b);
inline Vector3 &operator *=(Vector3 &v, float s);
inline Vector3 &operator /=(Vector3 &v, float s);

Vector3 operator *(const Vector3 &v, const Matrix4x4 &m);
Vector3 operator *(const Matrix4x4 &m, const Vector3 &v);

inline bool operator ==(const Vector3 &a, const Vector3 &b);
inline bool operator !=(const Vector3 &a, const Vector3 &b);

inline float dot(const Vector3 &a, const Vector3 &b);
inline Vector3 cross(const Vector3 &a, const Vector3 &b);
inline float length(const Vector3 &v);
inline float length_sq(const Vector3 &v);
inline Vector3 normalize(const Vector3 &v);

inline Vector3 reflect(const Vector3 &v, const Vector3 &n);
inline Vector3 refract(const Vector3 &v, const Vector3 &n, float ior);
inline Vector3 refract(const Vector3 &v, const Vector3 &n, float from_ior, float to_ior);

inline float distance(const Vector3 &a, const Vector3 &b);
inline float distance_sq(const Vector3 &a, const Vector3 &b);
inline Vector3 faceforward(const Vector3 &n, const Vector3 &vi, const Vector3 &ng);

inline Vector3 major(const Vector3 &v);
inline int major_idx(const Vector3 &v);
inline Vector3 proj_axis(const Vector3 &v, const Vector3 &axis);

inline Vector3 rotate(const Vector3 &v, const Quaternion &q);
inline Vector3 rotate(const Vector3 &v, const Vector3 &axis, float angle);
inline Vector3 rotate(const Vector3 &v, const Vector3 &euler);

}

#include "vector.inl"

#endif	/* GMATH_VEC_H_ */
