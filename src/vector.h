#ifndef GMATH_VEC_H_
#define GMATH_VEC_H_

#include <math.h>
#include "swizzle.h"

namespace gph {

// define the swizzle macros to emit function prototypes
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
	explicit Vector2(const Vector3 &v);

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
	explicit Vector3(const Vector4 &v);

	inline void normalize();
	inline float &operator[] (int idx);
	inline const float &operator[] (int idx) const;

	GPH_VEC3_SWIZZLE
};


class Vector4 {
public:
	float x, y, z, w;

	Vector4() : x(0), y(0), z(0), w(0) {}
	Vector4(float x_, float y_, float z_, float w_ = 1.0f) : x(x_), y(y_), z(z_), w(w_) {}
	explicit Vector4(const Vector3 &v);

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


// ---- Vector4 functions ----
inline Vector4 operator -(const Vector4 &v);
inline Vector4 operator +(const Vector4 &a, const Vector4 &b);
inline Vector4 operator -(const Vector4 &a, const Vector4 &b);
inline Vector4 operator *(const Vector4 &a, const Vector4 &b);
inline Vector4 operator /(const Vector4 &a, const Vector4 &b);
inline Vector4 operator *(const Vector4 &v, float s);
inline Vector4 operator *(float s, const Vector4 &v);
inline Vector4 operator /(const Vector4 &v, float s);
inline Vector4 operator /(float s, const Vector4 &v);
inline Vector4 &operator +=(Vector4 &a, const Vector4 &b);
inline Vector4 &operator -=(Vector4 &a, const Vector4 &b);
inline Vector4 &operator *=(Vector4 &a, const Vector4 &b);
inline Vector4 &operator /=(Vector4 &a, const Vector4 &b);
inline Vector4 &operator *=(Vector4 &v, float s);
inline Vector4 &operator /=(Vector4 &v, float s);

Vector4 operator *(const Vector4 &v, const Matrix4x4 &m);
Vector4 operator *(const Matrix4x4 &m, const Vector4 &v);

inline bool operator ==(const Vector4 &a, const Vector4 &b);
inline bool operator !=(const Vector4 &a, const Vector4 &b);

inline float dot(const Vector4 &a, const Vector4 &b);
inline Vector4 cross(const Vector4 &a, const Vector4 &b, const Vector4 &c);
inline float length(const Vector4 &v);
inline float length_sq(const Vector4 &v);
inline Vector4 normalize(const Vector4 &v);

inline Vector4 reflect(const Vector4 &v, const Vector4 &n);
inline Vector4 refract(const Vector4 &v, const Vector4 &n, float ior);
inline Vector4 refract(const Vector4 &v, const Vector4 &n, float from_ior, float to_ior);

inline float distance(const Vector4 &a, const Vector4 &b);
inline float distance_sq(const Vector4 &a, const Vector4 &b);
inline Vector4 faceforward(const Vector4 &n, const Vector4 &vi, const Vector4 &ng);

inline Vector4 major(const Vector4 &v);
inline int major_idx(const Vector4 &v);
inline Vector4 proj_axis(const Vector4 &v, const Vector4 &axis);

inline Vector4 rotate(const Vector4 &v, const Quaternion &q);
inline Vector4 rotate(const Vector4 &v, const Vector4 &axis, float angle);
inline Vector4 rotate(const Vector4 &v, const Vector4 &euler);

// include definitions of all the inline functions above
#include "vector2.inl"
#include "vector3.inl"
#include "vector4.inl"

// change the swizzle macros to spit out the function definitions and invoke them
#undef GPH_SWIZZLE2
#undef GPH_SWIZZLE3
#undef GPH_SWIZZLE4
#define GPH_SWIZZLE2(T, a, b)		inline Vector2 T::a##b() const { return Vector2(a, b); }
#define GPH_SWIZZLE3(T, a, b, c)	inline Vector3 T::a##b##c() const { return Vector3(a, b, c); }
#define GPH_SWIZZLE4(T, a, b, c, d)	inline Vector4 T::a##b##c##d() const { return Vector4(a, b, c, d); }
GPH_VEC2_SWIZZLE
GPH_VEC3_SWIZZLE
GPH_VEC4_SWIZZLE

}

#endif	/* GMATH_VEC_H_ */
