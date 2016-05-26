/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
inline Quat operator -(const Quat &q)
{
	return Quat(-q.x, -q.y, -q.z, -q.w);
}

inline Quat operator +(const Quat &a, const Quat &b)
{
	return Quat(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Quat operator -(const Quat &a, const Quat &b)
{
	return Quat(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Quat operator *(const Quat &a, const Quat &b)
{
	Vec3 a_im = Vec3(a.x, a.y, a.z);
	Vec3 b_im = Vec3(b.x, b.y, b.z);

	float w = a.w * b.w - dot(a_im, b_im);
	Vec3 im = a.w * b_im + b.w * a_im + cross(a_im, b_im);
	return Quat(im.x, im.y, im.z, w);
}

inline Quat &operator +=(Quat &a, const Quat &b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}

inline Quat &operator -=(Quat &a, const Quat &b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}

inline Quat &operator *=(Quat &a, const Quat &b)
{
	Vec3 a_im = Vec3(a.x, a.y, a.z);
	Vec3 b_im = Vec3(b.x, b.y, b.z);

	float w = a.w * b.w - dot(a_im, b_im);
	Vec3 im = a.w * b_im + b.w * a_im + cross(a_im, b_im);
	a = Quat(im.x, im.y, im.z, w);
	return a;
}

inline float length(const Quat &q)
{
	return (float)sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

inline float length_sq(const Quat &q)
{
	return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

inline void Quat::normalize()
{
	float len = length(*this);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}
}

inline Quat normalize(const Quat &q)
{
	float len = length(q);
	if(len != 0.0f) {
		return Quat(q.x / len, q.y / len, q.z / len, q.w / len);
	}
	return q;
}

inline void Quat::conjugate()
{
	x = -x;
	y = -y;
	z = -z;
}

inline Quat conjugate(const Quat &q)
{
	return Quat(-q.x, -q.y, -q.z, q.w);
}

inline void Quat::invert()
{
	Quat conj = gph::conjugate(*this);
	float len_sq = length_sq(conj);
	if(len_sq != 0.0) {
		x = conj.x / len_sq;
		y = conj.y / len_sq;
		z = conj.z / len_sq;
		w = conj.w / len_sq;
	}
}

inline Quat inverse(const Quat &q)
{
	Quat conj = conjugate(q);
	float len_sq = length_sq(conj);
	if(len_sq != 0.0) {
		return Quat(conj.x / len_sq, conj.y / len_sq, conj.z / len_sq, conj.w / len_sq);
	}
	return q;
}

inline void Quat::set_rotation(const Vec3 &axis, float angle)
{
	float half_angle = angle * 0.5f;
	w = cos(half_angle);
	float sin_ha = sin(half_angle);
	x = axis.x * sin_ha;
	y = axis.y * sin_ha;
	z = axis.z * sin_ha;
}

inline void Quat::rotate(const Vec3 &axis, float angle)
{
	Quat q;
	float half_angle = angle * 0.5f;
	q.w = cos(half_angle);
	float sin_ha = sin(half_angle);
	q.x = axis.x * sin_ha;
	q.y = axis.y * sin_ha;
	q.z = axis.z * sin_ha;
	*this *= q;
}

inline void Quat::rotate(const Quat &rq)
{
	*this = rq * *this * gph::conjugate(rq);
}

inline Mat4 Quat::calc_matrix() const
{
	float xsq2 = 2.0 * x * x;
	float ysq2 = 2.0 * y * y;
	float zsq2 = 2.0 * z * z;
	float sx = 1.0 - ysq2 - zsq2;
	float sy = 1.0 - xsq2 - zsq2;
	float sz = 1.0 - xsq2 - ysq2;

	return Mat4(
			sx, 2.0 * x * y + 2.0 * w * z, 2.0 * z * x - 2.0 * w * y, 0,
			2.0 * x * y - 2.0 * w * z, sy, 2.0 * y * z + 2.0 * w * x, 0,
			2.0 * z * x + 2.0 * w * y, 2.0 * y * z - 2.0 * w * x, sz, 0,
			0, 0, 0, 1);

}

inline Quat slerp(const Quat &quat1, const Quat &q2, float t)
{
	Quat q1 = quat1;
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

	return Quat(x, y, z, w);
}

inline Quat lerp(const Quat &a, const Quat &b, float t)
{
	return slerp(a, b, t);
}
