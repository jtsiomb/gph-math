/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline void Vector4::normalize()
{
	float len = (float)sqrt(x * x + y * y + z * z + w * w);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}
}

inline float &Vector4::operator[] (int idx)
{
	return idx == 0 ? x : (idx == 1 ? y : (idx == 2 ? z : w));
}

inline const float &Vector4::operator[] (int idx) const
{
	return idx == 0 ? x : (idx == 1 ? y : (idx == 2 ? z : w));
}

inline Vector4 operator -(const Vector4 &v)
{
	return Vector4(-v.x, -v.y, -v.z, -v.w);
}

inline Vector4 operator +(const Vector4 &a, const Vector4 &b)
{
	return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vector4 operator -(const Vector4 &a, const Vector4 &b)
{
	return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Vector4 operator *(const Vector4 &a, const Vector4 &b)
{
	return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

inline Vector4 operator /(const Vector4 &a, const Vector4 &b)
{
	return Vector4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

inline Vector4 operator *(const Vector4 &v, float s)
{
	return Vector4(v.x * s, v.y * s, v.z * s, v.w * s);
}

inline Vector4 operator *(float s, const Vector4 &v)
{
	return Vector4(s * v.x, s * v.y, s * v.z, s * v.w);
}

inline Vector4 operator /(const Vector4 &v, float s)
{
	return Vector4(v.x / s, v.y / s, v.z / s, v.w / s);
}

inline Vector4 operator /(float s, const Vector4 &v)
{
	return Vector4(s / v.x, s / v.y, s / v.z, s / v.w);
}

inline Vector4 &operator +=(Vector4 &a, const Vector4 &b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}

inline Vector4 &operator -=(Vector4 &a, const Vector4 &b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}

inline Vector4 &operator *=(Vector4 &a, const Vector4 &b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}

inline Vector4 &operator /=(Vector4 &a, const Vector4 &b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}

inline Vector4 &operator *=(Vector4 &v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	v.w *= s;
	return v;
}

inline Vector4 &operator /=(Vector4 &v, float s)
{
	v.x /= s;
	v.y /= s;
	v.z /= s;
	v.w /= s;
	return v;
}

inline bool operator ==(const Vector4 &a, const Vector4 &b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

inline bool operator !=(const Vector4 &a, const Vector4 &b)
{
	return !(a == b);
}

inline float dot(const Vector4 &a, const Vector4 &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline Vector4 cross(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3)
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

    return Vector4(x, y, z, w);
}

inline float length(const Vector4 &v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

inline float length_sq(const Vector4 &v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

inline Vector4 normalize(const Vector4 &v)
{
	float len = length(v);
	if(len == 0.0f) {
		return v;
	}

	return Vector4(v.x / len, v.y / len, v.z / len, v.w / len);
}

inline Vector4 reflect(const Vector4 &v, const Vector4 &n)
{
	return v - n * dot(n, v) * 2.0;
}

inline Vector4 refract(const Vector4 &v, const Vector4 &n, float ior)
{
	float ndotv = dot(n, v);
	float k = 1.0f - ior * ior * (1.0f - ndotv * ndotv);
	if(k < 0.0f) {
		return Vector4();
	}
	return ior * v - (ior * ndotv + sqrt(k)) * n;
}

inline Vector4 refract(const Vector4 &v, const Vector4 &n, float from_ior, float to_ior)
{
	if(to_ior == 0.0f) to_ior = 1.0f;
	return refract(v, n, from_ior / to_ior);
}

inline float distance(const Vector4 &a, const Vector4 &b)
{
	return length(a - b);
}

inline float distance_sq(const Vector4 &a, const Vector4 &b)
{
	return length_sq(a - b);
}

inline Vector4 faceforward(const Vector4 &n, const Vector4 &vi, const Vector4 &ng)
{
	return dot(ng, vi) < 0.0f ? n : -n;
}

inline Vector4 faceforward(const Vector4 &n, const Vector4 &vi)
{
	return dot(n, vi) < 0.0f ? n : -n;
}

inline Vector4 major(const Vector4 &v)
{
	int m = major_idx(v);
	Vector4 res;
	res[m] = v[m];
	return res;
}

inline int major_idx(const Vector4 &v)
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

inline Vector4 proj_axis(const Vector4 &v, const Vector4 &axis)
{
	return axis * dot(v, axis);
}


inline Vector4 rotate(const Vector4 &v, const Quaternion &q)
{
	return v;	// TODO
}

inline Vector4 rotate(const Vector4 &v, const Vector4 &axis, float angle)
{
	return v;	// TODO
}

inline Vector4 rotate(const Vector4 &v, const Vector4 &euler)
{
	return v;	// TODO
}
