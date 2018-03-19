/*
gph-math - math library for graphics programs
Copyright (C) 2016-2018 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/

inline Mat2::Mat2()
{
	memcpy((float*)m, (const float*)identity.m, 4 * sizeof(float));
}

inline Mat2::Mat2(float m00, float m01, float m10, float m11)
{
	m[0][0] = m00; m[0][1] = m01;
	m[1][0] = m10; m[1][1] = m11;
}

inline float *Mat2::operator [](int idx)
{
	return m[idx];
}

inline const float *Mat2::operator [](int idx) const
{
	return m[idx];
}

inline float Mat2::determinant() const
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

inline Mat3::Mat3()
{
	memcpy((float*)m, (const float*)identity.m, 9 * sizeof(float));
}

inline Mat3::Mat3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22)
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
}

inline float *Mat3::operator [](int idx)
{
	return m[idx];
}

inline const float *Mat3::operator [](int idx) const
{
	return m[idx];
}

inline Mat2 Mat3::submatrix(int row, int col) const
{
	Mat2 sub;
	int subi = 0;
	for(int i=0; i<3; i++) {
		if(i == row) continue;

		int subj = 0;
		for(int j=0; j<3; j++) {
			if(j == col) continue;

			sub.m[subi][subj++] = m[i][j];
		}
		++subi;
	}
	return sub;
}

inline float Mat3::subdet(int row, int col) const
{
	return submatrix(row, col).determinant();
}

inline float Mat3::determinant() const
{
	return m[0][0] * subdet(0, 0) - m[0][1] * subdet(0, 1) + m[0][2] * subdet(0, 2);
}

// ---- Mat4 functions ----

inline Mat4::Mat4()
{
	memcpy((float*)m, (const float*)identity.m, 16 * sizeof(float));
}

inline Mat4::Mat4(const float *m)
{
	memcpy((float*)this->m, (const float*)m, 16 * sizeof(float));
}

inline Mat4::Mat4(float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}

inline Mat4::Mat4(const Vec4 &v0, const Vec4 &v1, const Vec4 &v2, const Vec4 &v3)
{
	m[0][0] = v0.x; m[0][1] = v0.y; m[0][2] = v0.z; m[0][3] = v0.w;
	m[1][0] = v1.x; m[1][1] = v1.y; m[1][2] = v1.z; m[1][3] = v1.w;
	m[2][0] = v2.x; m[2][1] = v2.y; m[2][2] = v2.z; m[2][3] = v2.w;
	m[3][0] = v3.x; m[3][1] = v3.y; m[3][2] = v3.z; m[3][3] = v3.w;
}

inline Mat4::Mat4(const Vec3 &v0, const Vec3 &v1, const Vec3 &v2, const Vec3 &v3)
{
	m[0][0] = v0.x; m[0][1] = v0.y; m[0][2] = v0.z; m[0][3] = 0.0f;
	m[1][0] = v1.x; m[1][1] = v1.y; m[1][2] = v1.z; m[1][3] = 0.0f;
	m[2][0] = v2.x; m[2][1] = v2.y; m[2][2] = v2.z; m[2][3] = 0.0f;
	m[3][0] = v3.x; m[3][1] = v3.y; m[3][2] = v3.z; m[3][3] = 1.0f;
}

inline Mat3 Mat4::submatrix(int row, int col) const
{
	Mat3 sub;
	int subi = 0;
	for(int i=0; i<4; i++) {
		if(i == row) continue;

		int subj = 0;
		for(int j=0; j<4; j++) {
			if(j == col) continue;

			sub.m[subi][subj++] = m[i][j];
		}
		++subi;
	}
	return sub;
}

inline float *Mat4::operator [](int idx)
{
	return m[idx];
}

inline const float *Mat4::operator [](int idx) const
{
	return m[idx];
}

inline void Mat4::set_row(int idx, const Vec3 &v)
{
	m[idx][0] = v.x;
	m[idx][1] = v.y;
	m[idx][2] = v.z;
	m[idx][3] = 0.0f;
}

inline void Mat4::set_row(int idx, const Vec4 &v)
{
	m[idx][0] = v.x;
	m[idx][1] = v.y;
	m[idx][2] = v.z;
	m[idx][3] = v.w;
}

inline void Mat4::set_column(int idx, const Vec3 &v)
{
	m[0][idx] = v.x;
	m[1][idx] = v.y;
	m[2][idx] = v.z;
	m[3][idx] = 0.0f;
}

inline void Mat4::set_column(int idx, const Vec4 &v)
{
	m[0][idx] = v.x;
	m[1][idx] = v.y;
	m[2][idx] = v.z;
	m[3][idx] = v.w;
}

inline Vec4 Mat4::get_row(int idx) const
{
	return Vec4(m[idx][0], m[idx][1], m[idx][2], m[idx][3]);
}

inline Vec3 Mat4::get_row3(int idx) const
{
	return Vec3(m[idx][0], m[idx][1], m[idx][2]);
}

inline Vec4 Mat4::get_column(int idx) const
{
	return Vec4(m[0][idx], m[1][idx], m[2][idx], m[3][idx]);
}

inline Vec3 Mat4::get_column3(int idx) const
{
	return Vec3(m[0][idx], m[1][idx], m[2][idx]);
}

inline Mat4 Mat4::upper3x3() const
{
	return Mat4(get_row3(0), get_row3(1), get_row3(2));
}

inline float Mat4::subdet(int row, int col) const
{
	return submatrix(row, col).determinant();
}

inline float Mat4::cofactor(int row, int col) const
{
	float min = subdet(row, col);
	return (row + col) & 1 ? -min : min;
}

inline float Mat4::determinant() const
{
	return m[0][0] * subdet(0, 0) - m[0][1] * subdet(0, 1) +
		m[0][2] * subdet(0, 2) - m[0][3] * subdet(0, 3);
}

inline void Mat4::transpose()
{
	for(int i=0; i<4; i++) {
		for(int j=0; j<i; j++) {
			float tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
	}
}

inline bool Mat4::inverse()
{
	float det = determinant();
	if(!det) return false;

	*this = gph::transpose(cofactor_matrix(*this)) * (1.0f / det);
	return true;
}

inline void Mat4::translation(float x, float y, float z)
{
	*this = identity;
	m[3][0] = x;
	m[3][1] = y;
	m[3][2] = z;
}

inline void Mat4::translation(const Vec3 &v)
{
	translation(v.x, v.y, v.z);
}

inline void Mat4::scaling(float s)
{
	scaling(s, s, s);
}

inline void Mat4::scaling(float x, float y, float z)
{
	*this = identity;
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
}

inline void Mat4::scaling(const Vec3 &v)
{
	scaling(v.x, v.y, v.z);
}

inline void Mat4::rotation_x(float angle)
{
	*this = identity;
	float sa = sin(angle);
	float ca = cos(angle);
	m[1][1] = ca;
	m[1][2] = sa;
	m[2][1] = -sa;
	m[2][2] = ca;
}

inline void Mat4::rotation_y(float angle)
{
	*this = identity;
	float sa = sin(angle);
	float ca = cos(angle);
	m[0][0] = ca;
	m[0][2] = -sa;
	m[2][0] = sa;
	m[2][2] = ca;
}

inline void Mat4::rotation_z(float angle)
{
	*this = identity;
	float sa = sin(angle);
	float ca = cos(angle);
	m[0][0] = ca;
	m[0][1] = sa;
	m[1][0] = -sa;
	m[1][1] = ca;
}

inline void Mat4::rotation_axis(int idx, float angle)
{
	switch(idx) {
	case 0:
		rotation_x(angle);
		break;
	case 1:
		rotation_y(angle);
		break;
	case 2:
		rotation_z(angle);
		break;
	}
}

inline void Mat4::rotation(float angle, float x, float y, float z)
{
	float sa = sin(angle);
	float ca = cos(angle);
	float invca = 1.0f - ca;
	float xsq = x * x;
	float ysq = y * y;
	float zsq = z * z;

	*this = identity;
	m[0][0] = xsq + (1.0f - xsq) * ca;
	m[1][0] = x * y * invca - z * sa;
	m[2][0] = x * z * invca + y * sa;

	m[0][1] = x * y * invca + z * sa;
	m[1][1] = ysq + (1.0f - ysq) * ca;
	m[2][1] = y * z * invca - x * sa;

	m[0][2] = x * z * invca - y * sa;
	m[1][2] = y * z * invca + x * sa;
	m[2][2] = zsq + (1.0f - zsq) * ca;
}

inline void Mat4::rotation(float angle, const Vec3 &axis)
{
	rotation(angle, axis.x, axis.y, axis.z);
}

inline void Mat4::rotation(float a, float b, float c, EulerMode mode)
{
	Mat4 ma, mb, mc;
	/* this array must match the EulerMode enum */
	static const int axis[][3] = {
		{0, 1, 2}, {0, 2, 1},
		{1, 0, 2}, {1, 2, 0},
		{2, 0, 1}, {2, 1, 0},
		{2, 0, 2}, {2, 1, 2},
		{1, 0, 1}, {1, 2, 1},
		{0, 1, 0}, {0, 2, 0}
	};
	ma.rotation_axis(axis[mode][0], a);
	mb.rotation_axis(axis[mode][1], b);
	mc.rotation_axis(axis[mode][2], c);

	*this = mc * mb * ma;
}

inline void Mat4::rotation(const Vec3 &euler, EulerMode mode)
{
	rotation(euler.x, euler.y, euler.z, mode);
}

inline void Mat4::translate(float x, float y, float z)
{
	Mat4 mat;
	mat.translation(x, y, z);
	*this *= mat;
}

inline void Mat4::translate(const Vec3 &v)
{
	translate(v.x, v.y, v.z);
}

inline void Mat4::scale(float s)
{
	scale(s, s, s);
}

inline void Mat4::scale(float x, float y, float z)
{
	Mat4 mat;
	mat.scaling(x, y, z);
	*this *= mat;
}

inline void Mat4::scale(const Vec3 &v)
{
	scale(v.x, v.y, v.z);
}

inline void Mat4::rotate_x(float angle)
{
	Mat4 mat;
	mat.rotation_x(angle);
	*this *= mat;
}

inline void Mat4::rotate_y(float angle)
{
	Mat4 mat;
	mat.rotation_y(angle);
	*this *= mat;
}

inline void Mat4::rotate_z(float angle)
{
	Mat4 mat;
	mat.rotation_z(angle);
	*this *= mat;
}

inline void Mat4::rotate_axis(int idx, float angle)
{
	Mat4 mat;
	mat.rotation_axis(idx, angle);
	*this *= mat;
}

inline void Mat4::rotate(float angle, float x, float y, float z)
{
	Mat4 mat;
	mat.rotation(angle, x, y, z);
	*this *= mat;
}

inline void Mat4::rotate(float angle, const Vec3 &axis)
{
	rotate(angle, axis.x, axis.y, axis.z);
}

inline void Mat4::rotate(float x, float y, float z, EulerMode mode)
{
	Mat4 mat;
	mat.rotation(x, y, z, mode);
	*this *= mat;
}

inline void Mat4::rotate(const Vec3 &euler, EulerMode mode)
{
	rotate(euler.x, euler.y, euler.z, mode);
}

inline void Mat4::rotate(const Quat &q)
{
	Mat4 mat;
	mat.rotation(q);
	*this *= mat;
}

inline void Mat4::pre_translate(float x, float y, float z)
{
	Mat4 mat;
	mat.translation(x, y, z);
	*this = mat * *this;
}

inline void Mat4::pre_translate(const Vec3 &v)
{
	pre_translate(v.x, v.y, v.z);
}

inline void Mat4::pre_scale(float s)
{
	pre_scale(s, s, s);
}

inline void Mat4::pre_scale(float x, float y, float z)
{
	Mat4 mat;
	mat.scaling(x, y, z);
	*this = mat * *this;
}

inline void Mat4::pre_scale(const Vec3 &v)
{
	pre_scale(v.x, v.y, v.z);
}

inline void Mat4::pre_rotate_x(float angle)
{
	Mat4 mat;
	mat.rotation_x(angle);
	*this = mat * *this;
}

inline void Mat4::pre_rotate_y(float angle)
{
	Mat4 mat;
	mat.rotation_y(angle);
	*this = mat * *this;
}

inline void Mat4::pre_rotate_z(float angle)
{
	Mat4 mat;
	mat.rotation_z(angle);
	*this = mat * *this;
}

inline void Mat4::pre_rotate_axis(int idx, float angle)
{
	Mat4 mat;
	mat.rotation_axis(idx, angle);
	*this = mat * *this;
}

inline void Mat4::pre_rotate(float angle, float x, float y, float z)
{
	Mat4 mat;
	mat.rotation(angle, x, y, z);
	*this = mat * *this;
}

inline void Mat4::pre_rotate(float angle, const Vec3 &axis)
{
	pre_rotate(angle, axis.x, axis.y, axis.z);
}

inline void Mat4::pre_rotate(float x, float y, float z, EulerMode mode)
{
	Mat4 mat;
	mat.rotation(x, y, z, mode);
	*this = mat * *this;
}

inline void Mat4::pre_rotate(const Vec3 &euler, EulerMode mode)
{
	pre_rotate(euler.x, euler.y, euler.z, mode);
}

inline void Mat4::pre_rotate(const Quat &q)
{
	Mat4 mat;
	mat.rotation(q);
	*this = mat * *this;
}

inline Vec3 Mat4::get_translation() const
{
	return Vec3(m[3][0], m[3][1], m[3][2]);
}

inline Vec3 Mat4::get_scaling() const
{
	Vec3 vi = get_column3(0);
	Vec3 vj = get_column3(1);
	Vec3 vk = get_column3(2);
	return Vec3(length(vi), length(vj), length(vk));
}

inline Vec4 Mat4::get_frustum_plane(int p) const
{
	float plane[4];
	int idx = p >> 1;

	if((p & 1) == 0) {
		plane[0] = m[3][0] + m[idx][0];
		plane[1] = m[3][1] + m[idx][1];
		plane[2] = m[3][2] + m[idx][2];
		plane[3] = m[3][3] + m[idx][3];
	} else {
		plane[0] = m[3][0] - m[idx][0];
		plane[1] = m[3][1] - m[idx][1];
		plane[2] = m[3][2] - m[idx][2];
		plane[3] = m[3][3] - m[idx][3];
	}
	return Vec4(plane[0], plane[1], plane[2], plane[3]);
}

inline void Mat4::lookat(const Vec3 &pos, const Vec3 &targ, const Vec3 &up)
{
	Vec3 dir = normalize(targ - pos);
	Vec3 right = normalize(cross(dir, up));
	Vec3 vup = normalize(cross(right, dir));

	Mat4 rot;
	rot.set_row(0, right);
	rot.set_row(1, vup);
	rot.set_row(2, -dir);

	Mat4 trans;
	trans.translation(pos);

	*this = rot * trans;
}

inline void Mat4::inv_lookat(const Vec3 &pos, const Vec3 &targ, const Vec3 &up)
{
	Vec3 dir = normalize(targ - pos);
	Vec3 right = normalize(cross(dir, up));
	Vec3 vup = normalize(cross(right, dir));

	Mat4 rot;
	rot.set_column(0, right);
	rot.set_column(1, vup);
	rot.set_column(2, -dir);

	Mat4 trans;
	trans.translation(-pos);

	*this = trans * rot;
}

inline void Mat4::ortho(float left, float right, float bottom, float top, float znear, float zfar)
{
	float dx = right - left;
	float dy = top - bottom;
	float dz = zfar - znear;

	*this = identity;
	m[0][0] = 2.0f / dx;
	m[1][1] = 2.0f / dy;
	m[2][2] = -2.0f / dz;
	m[3][0] = -(right + left) / dx;
	m[3][1] = -(top + bottom) / dy;
	m[3][2] = -(zfar + znear) / dz;
}

inline void Mat4::frustum(float left, float right, float bottom, float top, float znear, float zfar)
{
	float dx = right - left;
	float dy = top - bottom;
	float dz = zfar - znear;

	*this = zero;
	m[0][0] = 2.0f * znear / dx;
	m[1][1] = 2.0f * znear / dy;
	m[2][0] = (right + left) / dx;
	m[2][1] = (top + bottom) / dy;
	m[2][2] = -(zfar + znear) / dz;
	m[3][2] = -2.0f * zfar * znear / dz;
	m[2][3] = -1.0f;
}

inline void Mat4::perspective(float fov, float aspect, float znear, float zfar)
{
	float s = 1.0f / tan(fov / 2.0f);
	float range = znear - zfar;

	*this = zero;
	m[0][0] = s / aspect;
	m[1][1] = s;
	m[2][2] = (znear + zfar) / range;
	m[3][2] = 2.0f * znear * zfar / range;
	m[2][3] = -1.0f;
}

inline void Mat4::mirror(float a, float b, float c, float d)
{
	m[0][0] = 1.0f - 2.0f * a * a;
	m[1][1] = 1.0f - 2.0f * b * b;
	m[2][2] = 1.0f - 2.0f * c * c;
	m[3][3] = 1.0f;

	m[0][1] = m[1][0] = -2.0f * a * b;
	m[0][2] = m[2][0] = -2.0f * a * c;
	m[1][2] = m[2][1] = -2.0f * b * c;

	m[3][0] = -2.0f * a * d;
	m[3][1] = -2.0f * b * d;
	m[3][2] = -2.0f * c * d;

	m[0][3] = m[1][3] = m[2][3] = 0.0f;
}

inline void Mat4::mirror(const Vec3 &n, float d)
{
	mirror(n.x, n.y, n.z, d);
}


inline void Mat4::print(FILE *fp) const
{
	if(!fp) fp = stdout;

	for(int i=0; i<4; i++) {
		fprintf(fp, "[ %4.4g %4.4g %4.4g %4.4g ]\n", m[i][0], m[i][1], m[i][2], m[i][3]);
	}
	fputc('\n', fp);
}

inline Mat4 operator *(const Mat4 &a, const Mat4 &b)
{
	Mat4 res;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			res.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] +
				a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
		}
	}
	return res;
}

inline Mat4 &operator *=(Mat4 &a, const Mat4 &b)
{
	a = a * b;
	return a;
}

inline Mat4 operator *(const Mat4 &m, float s)
{
	Mat4 res;
	for(int j=0; j<4; j++) {
		for(int i=0; i<4; i++) {
			res.m[i][j] = m.m[i][j] * s;
		}
	}
	return res;
}

inline Mat4 operator *(float s, const Mat4 &m)
{
	return m * s;
}

inline float determinant(const Mat4 &m)
{
	return m.determinant();
}

inline Mat4 transpose(const Mat4 &m)
{
	Mat4 res;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			res.m[i][j] = m.m[j][i];
		}
	}
	return res;
}

inline Mat4 cofactor_matrix(const Mat4 &m)
{
	Mat4 res;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			res.m[i][j] = m.cofactor(i, j);
		}
	}
	return res;
}

inline Mat4 inverse(const Mat4 &m)
{
	float det = m.determinant();
	if(!det) return Mat4::identity;

	return transpose(cofactor_matrix(m)) * (1.0f / det);
}

inline Vec4 normalize_plane(const Vec4 &p)
{
	float d = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	if(d == 0.0f) return p;

	float s = 1.0f / d;
	return Vec4(p.x * s, p.y * s, p.z * s, p.w * s);
}
