/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline void Vec2::normalize()
{
	float len = (float)sqrt(x * x + y * y);
	if(len != 0.0f) {
		x /= len;
		y /= len;
	}
}

inline float &Vec2::operator[] (int idx)
{
	return idx == 0 ? x : y;
}

inline const float &Vec2::operator[] (int idx) const
{
	return idx == 0 ? x : y;
}

inline Vec2 operator -(const Vec2 &v)
{
	return Vec2(-v.x, -v.y);
}

inline Vec2 operator +(const Vec2 &a, const Vec2 &b)
{
	return Vec2(a.x + b.x, a.y + b.y);
}

inline Vec2 operator -(const Vec2 &a, const Vec2 &b)
{
	return Vec2(a.x - b.x, a.y - b.y);
}

inline Vec2 operator *(const Vec2 &a, const Vec2 &b)
{
	return Vec2(a.x * b.x, a.y * b.y);
}

inline Vec2 operator /(const Vec2 &a, const Vec2 &b)
{
	return Vec2(a.x / b.x, a.y / b.y);
}

inline Vec2 operator *(const Vec2 &v, float s)
{
	return Vec2(v.x * s, v.y * s);
}

inline Vec2 operator *(float s, const Vec2 &v)
{
	return Vec2(s * v.x, s * v.y);
}

inline Vec2 operator /(const Vec2 &v, float s)
{
	return Vec2(v.x / s, v.y / s);
}

inline Vec2 operator /(float s, const Vec2 &v)
{
	return Vec2(s / v.x, s / v.y);
}

inline Vec2 &operator +=(Vec2 &a, const Vec2 &b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

inline Vec2 &operator -=(Vec2 &a, const Vec2 &b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

inline Vec2 &operator *=(Vec2 &a, const Vec2 &b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

inline Vec2 &operator /=(Vec2 &a, const Vec2 &b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline Vec2 &operator *=(Vec2 &v, float s)
{
	v.x *= s;
	v.y *= s;
	return v;
}

inline Vec2 &operator /=(Vec2 &v, float s)
{
	v.x /= s;
	v.y /= s;
	return v;
}


inline bool operator ==(const Vec2 &a, const Vec2 &b)
{
	return a.x == b.x && a.y == b.y;
}

inline bool operator !=(const Vec2 &a, const Vec2 &b)
{
	return !(a == b);
}


inline float dot(const Vec2 &a, const Vec2 &b)
{
	return a.x * b.x + a.y * b.y;
}

inline float length(const Vec2 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y);
}

inline float length_sq(const Vec2 &v)
{
	return v.x * v.x + v.y * v.y;
}

inline Vec2 normalize(const Vec2 &v)
{
	float len = length(v);
	if(len == 0.0f) {
		return v;
	}

	return Vec2(v.x / len, v.y / len);
}


inline Vec2 reflect(const Vec2 &v, const Vec2 &n)
{
	return v - n * dot(n, v) * 2.0;
}

inline Vec2 refract(const Vec2 &v, const Vec2 &n, float ior)
{
	float ndotv = dot(n, v);
	float k = 1.0f - ior * ior * (1.0f - ndotv * ndotv);
	if(k < 0.0f) {
		return Vec2();
	}
	return ior * v - (ior * ndotv + sqrt(k)) * n;
}

inline Vec2 refract(const Vec2 &v, const Vec2 &n, float from_ior, float to_ior)
{
	if(to_ior == 0.0f) to_ior = 1.0f;
	return refract(v, n, from_ior / to_ior);
}


inline float distance(const Vec2 &a, const Vec2 &b)
{
	return length(a - b);
}

inline float distance_sq(const Vec2 &a, const Vec2 &b)
{
	return length_sq(a - b);
}

inline Vec2 faceforward(const Vec2 &n, const Vec2 &vi, const Vec2 &ng)
{
	return dot(ng, vi) < 0.0f ? n : -n;
}

inline Vec2 faceforward(const Vec2 &n, const Vec2 &vi)
{
	return dot(n, vi) < 0.0f ? n : -n;
}

inline Vec2 major(const Vec2 &v)
{
	int m = major_idx(v);
	Vec2 res;
	res[m] = v[m];
	return res;
}

inline int major_idx(const Vec2 &v)
{
	return fabs(v.x) >= fabs(v.y) ? 0 : 1;
}

inline Vec2 proj_axis(const Vec2 &v, const Vec2 &axis)
{
	return axis * dot(v, axis);
}


inline Vec2 rotate(const Vec2 &v, float angle)
{
	float sa = sin(angle);
	float ca = cos(angle);
	float x = v.x * ca - v.y * sa;
	float y = v.x * sa + v.y * ca;
	return Vec2(x, y);
}

inline Vec2 lerp(const Vec2 &a, const Vec2 &b, float t)
{
	return a + (b - a) * t;
}
