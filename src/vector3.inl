/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline void Vec3::normalize()
{
	float len = (float)sqrt(x * x + y * y + z * z);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
	}
}

inline float &Vec3::operator[] (int idx)
{
	return idx == 0 ? x : (idx == 1 ? y : z);
}

inline const float &Vec3::operator[] (int idx) const
{
	return idx == 0 ? x : (idx == 1 ? y : z);
}

inline Vec3 operator -(const Vec3 &v)
{
	return Vec3(-v.x, -v.y, -v.z);
}

inline Vec3 operator +(const Vec3 &a, const Vec3 &b)
{
	return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vec3 operator -(const Vec3 &a, const Vec3 &b)
{
	return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vec3 operator *(const Vec3 &a, const Vec3 &b)
{
	return Vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

inline Vec3 operator /(const Vec3 &a, const Vec3 &b)
{
	return Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

inline Vec3 operator *(const Vec3 &v, float s)
{
	return Vec3(v.x * s, v.y * s, v.z * s);
}

inline Vec3 operator *(float s, const Vec3 &v)
{
	return Vec3(s * v.x, s * v.y, s * v.z);
}

inline Vec3 operator /(const Vec3 &v, float s)
{
	return Vec3(v.x / s, v.y / s, v.z / s);
}

inline Vec3 operator /(float s, const Vec3 &v)
{
	return Vec3(s / v.x, s / v.y, s / v.z);
}

inline Vec3 &operator +=(Vec3 &a, const Vec3 &b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

inline Vec3 &operator -=(Vec3 &a, const Vec3 &b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

inline Vec3 &operator *=(Vec3 &a, const Vec3 &b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}

inline Vec3 &operator /=(Vec3 &a, const Vec3 &b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}

inline Vec3 &operator *=(Vec3 &v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	return v;
}

inline Vec3 &operator /=(Vec3 &v, float s)
{
	v.x /= s;
	v.y /= s;
	v.z /= s;
	return v;
}

inline bool operator ==(const Vec3 &a, const Vec3 &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline bool operator !=(const Vec3 &a, const Vec3 &b)
{
	return !(a == b);
}

inline float dot(const Vec3 &a, const Vec3 &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Vec3 cross(const Vec3 &a, const Vec3 &b)
{
	return Vec3(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
}

inline float length(const Vec3 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline float length_sq(const Vec3 &v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline Vec3 normalize(const Vec3 &v)
{
	float len = length(v);
	if(len == 0.0f) {
		return v;
	}

	return Vec3(v.x / len, v.y / len, v.z / len);
}

inline Vec3 reflect(const Vec3 &v, const Vec3 &n)
{
	return v - n * dot(n, v) * 2.0;
}

inline Vec3 refract(const Vec3 &v, const Vec3 &n, float ior)
{
	float ndotv = dot(n, v);
	float k = 1.0f - ior * ior * (1.0f - ndotv * ndotv);
	if(k < 0.0f) {
		return Vec3();
	}
	return ior * v - (ior * ndotv + sqrt(k)) * n;
}

inline Vec3 refract(const Vec3 &v, const Vec3 &n, float from_ior, float to_ior)
{
	if(to_ior == 0.0f) to_ior = 1.0f;
	return refract(v, n, from_ior / to_ior);
}

inline float distance(const Vec3 &a, const Vec3 &b)
{
	return length(a - b);
}

inline float distance_sq(const Vec3 &a, const Vec3 &b)
{
	return length_sq(a - b);
}

inline Vec3 faceforward(const Vec3 &n, const Vec3 &vi, const Vec3 &ng)
{
	return dot(ng, vi) < 0.0f ? n : -n;
}

inline Vec3 faceforward(const Vec3 &n, const Vec3 &vi)
{
	return dot(n, vi) < 0.0f ? n : -n;
}

inline Vec3 major(const Vec3 &v)
{
	int m = major_idx(v);
	Vec3 res;
	res[m] = v[m];
	return res;
}

inline int major_idx(const Vec3 &v)
{
	return fabs(v.x) >= fabs(v.y) && fabs(v.x) > fabs(v.z) ? 0 :
		(fabs(v.y) >= fabs(v.z) ? 1 : 2);
}

inline Vec3 proj_axis(const Vec3 &v, const Vec3 &axis)
{
	return axis * dot(v, axis);
}

inline Vec3 lerp(const Vec3 &a, const Vec3 &b, float t)
{
	return a + (b - a) * t;
}
