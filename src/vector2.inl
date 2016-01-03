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
