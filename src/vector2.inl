/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline void Vector2::normalize()
{
	float len = (float)sqrt(x * x + y * y);
	if(len != 0.0f) {
		x /= len;
		y /= len;
	}
}

inline float &Vector2::operator[] (int idx)
{
	return idx == 0 ? x : y;
}

inline const float &Vector2::operator[] (int idx) const
{
	return idx == 0 ? x : y;
}

inline Vector2 operator -(const Vector2 &v)
{
	return Vector2(-v.x, -v.y);
}

inline Vector2 operator +(const Vector2 &a, const Vector2 &b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

inline Vector2 operator -(const Vector2 &a, const Vector2 &b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}

inline Vector2 operator *(const Vector2 &a, const Vector2 &b)
{
	return Vector2(a.x * b.x, a.y * b.y);
}

inline Vector2 operator /(const Vector2 &a, const Vector2 &b)
{
	return Vector2(a.x / b.x, a.y / b.y);
}

inline Vector2 operator *(const Vector2 &v, float s)
{
	return Vector2(v.x * s, v.y * s);
}

inline Vector2 operator *(float s, const Vector2 &v)
{
	return Vector2(s * v.x, s * v.y);
}

inline Vector2 operator /(const Vector2 &v, float s)
{
	return Vector2(v.x / s, v.y / s);
}

inline Vector2 operator /(float s, const Vector2 &v)
{
	return Vector2(s / v.x, s / v.y);
}

inline Vector2 &operator +=(Vector2 &a, const Vector2 &b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

inline Vector2 &operator -=(Vector2 &a, const Vector2 &b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

inline Vector2 &operator *=(Vector2 &a, const Vector2 &b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

inline Vector2 &operator /=(Vector2 &a, const Vector2 &b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

inline Vector2 &operator *=(Vector2 &v, float s)
{
	v.x *= s;
	v.y *= s;
	return v;
}

inline Vector2 &operator /=(Vector2 &v, float s)
{
	v.x /= s;
	v.y /= s;
	return v;
}


inline bool operator ==(const Vector2 &a, const Vector2 &b)
{
	return a.x == b.x && a.y == b.y;
}

inline bool operator !=(const Vector2 &a, const Vector2 &b)
{
	return !(a == b);
}


inline float dot(const Vector2 &a, const Vector2 &b)
{
	return a.x * b.x + a.y * b.y;
}

inline float length(const Vector2 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y);
}

inline float length_sq(const Vector2 &v)
{
	return v.x * v.x + v.y * v.y;
}

inline Vector2 normalize(const Vector2 &v)
{
	float len = length(v);
	if(len == 0.0f) {
		return v;
	}

	return Vector2(v.x / len, v.y / len);
}


inline Vector2 reflect(const Vector2 &v, const Vector2 &n)
{
	return v - n * dot(n, v) * 2.0;
}

inline Vector2 refract(const Vector2 &v, const Vector2 &n, float ior)
{
	float ndotv = dot(n, v);
	float k = 1.0f - ior * ior * (1.0f - ndotv * ndotv);
	if(k < 0.0f) {
		return Vector2();
	}
	return ior * v - (ior * ndotv + sqrt(k)) * n;
}

inline Vector2 refract(const Vector2 &v, const Vector2 &n, float from_ior, float to_ior)
{
	if(to_ior == 0.0f) to_ior = 1.0f;
	return refract(v, n, from_ior / to_ior);
}


inline float distance(const Vector2 &a, const Vector2 &b)
{
	return length(a - b);
}

inline float distance_sq(const Vector2 &a, const Vector2 &b)
{
	return length_sq(a - b);
}

inline Vector2 faceforward(const Vector2 &n, const Vector2 &vi, const Vector2 &ng)
{
	return dot(ng, vi) < 0.0f ? n : -n;
}

inline Vector2 faceforward(const Vector2 &n, const Vector2 &vi)
{
	return dot(n, vi) < 0.0f ? n : -n;
}

inline Vector2 major(const Vector2 &v)
{
	int m = major_idx(v);
	Vector2 res;
	res[m] = v[m];
	return res;
}

inline int major_idx(const Vector2 &v)
{
	return fabs(v.x) >= fabs(v.y) ? 0 : 1;
}

inline Vector2 proj_axis(const Vector2 &v, const Vector2 &axis)
{
	return axis * dot(v, axis);
}


inline Vector2 rotate(const Vector2 &v, float angle)
{
	float sa = sin(angle);
	float ca = cos(angle);
	float x = v.x * ca - v.y * sa;
	float y = v.x * sa + v.y * ca;
	return Vector2(x, y);
}

