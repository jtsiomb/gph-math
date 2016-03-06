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

void Mat4::rotation(const Quat &q)
{
	*this = q.calc_matrix();
}

}	// namespace gph
