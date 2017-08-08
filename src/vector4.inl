/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline void Vec4::normalize()
{
	float len = (float)sqrt(x * x + y * y + z * z + w * w);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}
}

inline float &Vec4::operator[] (int idx)
{
	return idx == 0 ? x : (idx == 1 ? y : (idx == 2 ? z : w));
}

inline const float &Vec4::operator[] (int idx) const
{
	return idx == 0 ? x : (idx == 1 ? y : (idx == 2 ? z : w));
}

inline Vec4 operator -(const Vec4 &v)
{
	return Vec4(-v.x, -v.y, -v.z, -v.w);
}

inline Vec4 operator +(const Vec4 &a, const Vec4 &b)
{
	return Vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vec4 operator -(const Vec4 &a, const Vec4 &b)
{
	return Vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Vec4 operator *(const Vec4 &a, const Vec4 &b)
{
	return Vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

inline Vec4 operator /(const Vec4 &a, const Vec4 &b)
{
	return Vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

inline Vec4 operator *(const Vec4 &v, float s)
{
	return Vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}

inline Vec4 operator *(float s, const Vec4 &v)
{
	return Vec4(s * v.x, s * v.y, s * v.z, s * v.w);
}

inline Vec4 operator /(const Vec4 &v, float s)
{
	return Vec4(v.x / s, v.y / s, v.z / s, v.w / s);
}

inline Vec4 operator /(float s, const Vec4 &v)
{
	return Vec4(s / v.x, s / v.y, s / v.z, s / v.w);
}

inline Vec4 &operator +=(Vec4 &a, const Vec4 &b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}

inline Vec4 &operator -=(Vec4 &a, const Vec4 &b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}

inline Vec4 &operator *=(Vec4 &a, const Vec4 &b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}

inline Vec4 &operator /=(Vec4 &a, const Vec4 &b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline Vec4 &operator *=(Vec4 &v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	v.w *= s;
	return v;
}

inline Vec4 &operator /=(Vec4 &v, float s)
{
	v.x /= s;
	v.y /= s;
	v.z /= s;
	v.w /= s;
	return v;
}

inline bool operator ==(const Vec4 &a, const Vec4 &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

inline bool operator !=(const Vec4 &a, const Vec4 &b)
{
	return !(a == b);
}

inline float dot(const Vec4 &a, const Vec4 &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline Vec4 cross(const Vec4 &v1, const Vec4 &v2, const Vec4 &v3)
{
    /* Calculate intermediate values. */
    float a = (v2.x * v3.y) - (v2.y * v3.x);
    float b = (v2.x * v3.z) - (v2.z * v3.x);
    float c = (v2.x * v3.w) - (v2.w * v3.x);
    float d = (v2.y * v3.z) - (v2.z * v3.y);
    float e = (v2.y * v3.w) - (v2.w * v3.y);
    float f = (v2.z * v3.w) - (v2.w * v3.z);

    /* Calculate the result-vector components. */
    float x =   (v1.y * f) - (v1.z * e) + (v1.w * d);
    float y = - (v1.x * f) + (v1.z * c) - (v1.w * b);
    float z =   (v1.x * e) - (v1.y * c) + (v1.w * a);
    float w = - (v1.x * d) + (v1.y * b) - (v1.z * a);

    return Vec4(x, y, z, w);
}

inline float length(const Vec4 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

inline float length_sq(const Vec4 &v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

inline Vec4 normalize(const Vec4 &v)
{
	float len = length(v);
	if(len == 0.0f) {
		return v;
	}

	return Vec4(v.x / len, v.y / len, v.z / len, v.w / len);
}

inline Vec4 reflect(const Vec4 &v, const Vec4 &n)
{
	return v - n * dot(n, v) * 2.0;
}

inline Vec4 refract(const Vec4 &v, const Vec4 &n, float ior)
{
	float ndotv = dot(n, v);
	float k = 1.0f - ior * ior * (1.0f - ndotv * ndotv);
	if(k < 0.0f) {
		return Vec4();
	}
	return ior * v - (ior * ndotv + sqrt(k)) * n;
}

inline Vec4 refract(const Vec4 &v, const Vec4 &n, float from_ior, float to_ior)
{
	if(to_ior == 0.0f) to_ior = 1.0f;
	return refract(v, n, from_ior / to_ior);
}

inline float distance(const Vec4 &a, const Vec4 &b)
{
	return length(a - b);
}

inline float distance_sq(const Vec4 &a, const Vec4 &b)
{
	return length_sq(a - b);
}

inline Vec4 faceforward(const Vec4 &n, const Vec4 &vi, const Vec4 &ng)
{
	return dot(ng, vi) < 0.0f ? n : -n;
}

inline Vec4 faceforward(const Vec4 &n, const Vec4 &vi)
{
	return dot(n, vi) < 0.0f ? n : -n;
}

inline Vec4 major(const Vec4 &v)
{
	int m = major_idx(v);
	Vec4 res;
	res[m] = v[m];
	return res;
}

inline int major_idx(const Vec4 &v)
{
	if(fabs(v.x) >= fabs(v.y) && fabs(v.x) >= fabs(v.z) && fabs(v.x) >= fabs(v.w)) {
		return 0;
	}
	if(fabs(v.y) >= fabs(v.z) && fabs(v.y) >= fabs(v.w)) {
		return 1;
	}
	if(fabs(v.z) >= fabs(v.w)) {
		return 2;
	}
	return 3;
}

inline Vec4 proj_axis(const Vec4 &v, const Vec4 &axis)
{
	return axis * dot(v, axis);
}

inline Vec4 lerp(const Vec4 &a, const Vec4 &b, float t)
{
	return a + (b - a) * t;
}
