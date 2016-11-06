/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
#include "matrix.h"
#include "quat.h"

namespace gph {

Mat2 Mat2::identity(1, 0, 0, 1);
Mat3 Mat3::identity(1, 0, 0, 0, 1, 0, 0, 0, 1);
Mat4 Mat4::identity(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
Mat4 Mat4::zero(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

void gph::Mat4::rotation(const Quat &q)
{
	*this = q.calc_matrix();
}

// Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
// article "Quaternion Calculus and Fast Animation".
// adapted from: http://www.geometrictools.com/LibMathematics/Algebra/Wm5Quaternion.inl
Quat gph::Mat4::get_rotation() const
{
	static const int next[3] = {1, 2, 0};
	float quat[4];

	float trace = m[0][0] + m[1][1] + m[2][2];
	float root;

	if(trace > 0.0f) {
		// |w| > 1/2
		root = sqrt(trace + 1.0f);	// 2w
		quat[0] = 0.5f * root;
		root = 0.5f / root;	// 1 / 4w
		quat[1] = (m[1][2] - m[2][1]) * root;
		quat[2] = (m[2][0] - m[0][2]) * root;
		quat[3] = (m[0][1] - m[1][0]) * root;
	} else {
		// |w| <= 1/2
		int i = 0;
		if(m[1][1] > m[0][0]) {
			i = 1;
		}
		if(m[2][2] > m[i][i]) {
			i = 2;
		}
		int j = next[i];
		int k = next[j];

		root = sqrt(m[i][i] - m[j][j] - m[k][k] + 1.0f);
		quat[i + 1] = 0.5f * root;
		root = 0.5f / root;
		quat[0] = (m[j][k] - m[k][j]) * root;
		quat[j + 1] = (m[i][j] - m[j][i]) * root;
		quat[k + 1] = (m[i][k] - m[k][i]) * root;
	}
	return Quat(quat[1], quat[2], quat[3], quat[0]);
}


}	// namespace gph
