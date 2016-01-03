/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline Quaternion operator -(const Quaternion &q)
{
	return Quaternion(-q.x, -q.y, -q.z, -q.w);
}

inline Quaternion operator +(const Quaternion &a, const Quaternion &b)
{
	return Quaternion(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Quaternion operator -(const Quaternion &a, const Quaternion &b)
{
	return Quaternion(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Quaternion operator *(const Quaternion &a, const Quaternion &b)
{
	Vector3 a_im = Vector3(a.x, a.y, a.z);
	Vector3 b_im = Vector3(b.x, b.y, b.z);

	float w = a.w * b.w - dot(a_im, b_im);
	Vector3 im = a.w * b_im + b.w * a_im + cross(a_im, b_im);
	return Quaternion(im.x, im.y, im.z, w);
}

inline Quaternion &operator +=(Quaternion &a, const Quaternion &b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}

inline Quaternion &operator -=(Quaternion &a, const Quaternion &b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}

inline Quaternion &operator *=(Quaternion &a, const Quaternion &b)
{
	Vector3 a_im = Vector3(a.x, a.y, a.z);
	Vector3 b_im = Vector3(b.x, b.y, b.z);

	float w = a.w * b.w - dot(a_im, b_im);
	Vector3 im = a.w * b_im + b.w * a_im + cross(a_im, b_im);
	a = Quaternion(im.x, im.y, im.z, w);
	return a;
}

inline float length(const Quaternion &q)
{
	return (float)sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

inline float length_sq(const Quaternion &q)
{
	return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

inline void Quaternion::normalize()
{
	float len = length(*this);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}
}

inline Quaternion normalize(const Quaternion &q)
{
	float len = length(q);
	if(len != 0.0f) {
		return Quaternion(q.x / len, q.y / len, q.z / len, q.w / len);
	}
	return q;
}

inline void Quaternion::conjugate()
{
	x = -x;
	y = -y;
	z = -z;
}

inline Quaternion conjugate(const Quaternion &q)
{
	return Quaternion(-q.x, -q.y, -q.z, q.w);
}

inline void Quaternion::invert()
{
	Quaternion conj = gph::conjugate(*this);
	float len_sq = length_sq(conj);
	if(len_sq != 0.0) {
		x = conj.x / len_sq;
		y = conj.y / len_sq;
		z = conj.z / len_sq;
		w = conj.w / len_sq;
	}
}

inline Quaternion inverse(const Quaternion &q)
{
	Quaternion conj = conjugate(q);
	float len_sq = length_sq(conj);
	if(len_sq != 0.0) {
		return Quaternion(conj.x / len_sq, conj.y / len_sq, conj.z / len_sq, conj.w / len_sq);
	}
	return q;
}

inline void Quaternion::set_rotation(const Vector3 &axis, float angle)
{
	float half_angle = angle * 0.5f;
	w = cos(half_angle);
	float sin_ha = sin(half_angle);
	x = axis.x * sin_ha;
	y = axis.y * sin_ha;
	z = axis.z * sin_ha;
}

inline void Quaternion::rotate(const Vector3 &axis, float angle)
{
	Quaternion q;
	float half_angle = angle * 0.5f;
	q.w = cos(half_angle);
	float sin_ha = sin(half_angle);
	q.x = axis.x * sin_ha;
	q.y = axis.y * sin_ha;
	q.z = axis.z * sin_ha;
	*this *= q;
}

inline void Quaternion::rotate(const Quaternion &rq)
{
	*this = rq * *this * gph::conjugate(rq);
}

inline Matrix4x4 Quaternion::calc_matrix() const
{
	float xsq2 = 2.0 * x * x;
	float ysq2 = 2.0 * y * y;
	float zsq2 = 2.0 * z * z;
	float sx = 1.0 - ysq2 - zsq2;
	float sy = 1.0 - xsq2 - zsq2;
	float sz = 1.0 - xsq2 - ysq2;

	return Matrix4x4(
			sx,	2.0 * x * y - 2.0 * w * z, 2.0 * z * x + 2.0 * w * y, 0,
			2.0 * x * y + 2.0 * w * z, sy, 2.0 * y * z - 2.0 * w * x, 0,
			2.0 * z * x - 2.0 * w * y, 2.0 * y * z + 2.0 * w * x, sz, 0,
			0, 0, 0, 1);
}

inline Quaternion slerp(const Quaternion &quat1, const Quaternion &q2, float t)
{
	Quaternion q1 = quat1;
	float dot = q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;

	if(dot < 0.0) {
		/* make sure we interpolate across the shortest arc */
		q1 = -quat1;
		dot = -dot;
	}

	/* clamp dot to [-1, 1] in order to avoid domain errors in acos due to
	 * floating point imprecisions
	 */
	if(dot < -1.0) dot = -1.0;
	if(dot > 1.0) dot = 1.0;

	float angle = acos(dot);
	float a, b;

	float sin_angle = sin(angle);
	if(sin_angle == 0.0f) {
		// use linear interpolation to avoid div/zero
		a = 1.0f - t;
		b = t;
	} else {
		a = sin((1.0f - t) * angle) / sin_angle;
		b = sin(t * angle) / sin_angle;
	}

	float x = q1.x * a + q2.x * b;
	float y = q1.y * a + q2.y * b;
	float z = q1.z * a + q2.z * b;
	float w = q1.w * a + q2.w * b;

	return Quaternion(x, y, z, w);
}

inline Quaternion lerp(const Quaternion &a, const Quaternion &b, float t)
{
	return slerp(a, b, t);
}
