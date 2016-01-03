#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "vector.h"
#include "matrix.h"

namespace gph {

class Quaternion {
public:
	float x, y, z, w;	// w + xi + yj + zk

	static Quaternion identity;

	Quaternion() : x(0), y(0), z(0), w(1) {}
	Quaternion(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	Quaternion(const Vector3 &v, float s) : x(v.x), y(v.y), z(v.z), w(s) {}

	inline void normalize();
	inline void conjugate();
	inline void invert();

	inline void set_rotation(const Vector3 &axis, float angle);
	inline void rotate(const Vector3 &axis, float angle);
	// rotate by a quaternion rq by doing: rq * *this * conjugate(rq)
	inline void rotate(const Quaternion &rq);

	inline Matrix4x4 calc_matrix() const;
};

inline Quaternion operator -(const Quaternion &q);
inline Quaternion operator +(const Quaternion &a, const Quaternion &b);
inline Quaternion operator -(const Quaternion &a, const Quaternion &b);
inline Quaternion operator *(const Quaternion &a, const Quaternion &b);

inline Quaternion &operator +=(Quaternion &a, const Quaternion &b);
inline Quaternion &operator -=(Quaternion &a, const Quaternion &b);
inline Quaternion &operator *=(Quaternion &a, const Quaternion &b);

inline float length(const Quaternion &q);
inline float length_sq(const Quaternion &q);

inline Quaternion normalize(const Quaternion &q);
inline Quaternion conjugate(const Quaternion &q);
inline Quaternion inverse(const Quaternion &q);

Quaternion slerp(const Quaternion &a, const Quaternion &b, float t);
inline Quaternion lerp(const Quaternion &a, const Quaternion &b, float t);

#include "quat.inl"

}	// namespace gph

#endif	// QUATERNION_H_
