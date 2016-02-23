/*
gph-math - math library for graphics programs
Copyright (C) 2016 John Tsiombikas <nuclear@member.fsf.org>

This program is free software. Feel free to use, modify, and/or redistribute
it under the terms of the MIT/X11 license. See LICENSE for details.
If you intend to redistribute parts of the code without the LICENSE file
replace this paragraph with the full contents of the LICENSE file.
*/
// the only function of this file is to hide the swizzle-macro eyesore

// swizzle macros for Vec2
#define GPH_VEC2_SWIZZLE	\
	GPH_SWIZZLE2(Vec2, x, x) GPH_SWIZZLE2(Vec2, x, y) \
	GPH_SWIZZLE2(Vec2, y, x) GPH_SWIZZLE2(Vec2, y, y)

// swizzle macros for Vec3
#define GPH_VEC3_SWIZZLE	\
	GPH_SWIZZLE2(Vec3, x, x) GPH_SWIZZLE2(Vec3, x, y) GPH_SWIZZLE2(Vec3, x, z) \
	GPH_SWIZZLE2(Vec3, y, x) GPH_SWIZZLE2(Vec3, y, y) GPH_SWIZZLE2(Vec3, y, z) \
	GPH_SWIZZLE2(Vec3, z, x) GPH_SWIZZLE2(Vec3, z, y) GPH_SWIZZLE2(Vec3, z, z) \
	GPH_SWIZZLE3(Vec3, x, x, x) GPH_SWIZZLE3(Vec3, x, x, y) GPH_SWIZZLE3(Vec3, x, x, z) \
	GPH_SWIZZLE3(Vec3, x, y, x) GPH_SWIZZLE3(Vec3, x, y, y) GPH_SWIZZLE3(Vec3, x, y, z) \
	GPH_SWIZZLE3(Vec3, x, z, x) GPH_SWIZZLE3(Vec3, x, z, y) GPH_SWIZZLE3(Vec3, x, z, z) \
	GPH_SWIZZLE3(Vec3, y, x, x) GPH_SWIZZLE3(Vec3, y, x, y) GPH_SWIZZLE3(Vec3, y, x, z) \
	GPH_SWIZZLE3(Vec3, y, y, x) GPH_SWIZZLE3(Vec3, y, y, y) GPH_SWIZZLE3(Vec3, y, y, z) \
	GPH_SWIZZLE3(Vec3, y, z, x) GPH_SWIZZLE3(Vec3, y, z, y) GPH_SWIZZLE3(Vec3, y, z, z) \
	GPH_SWIZZLE3(Vec3, z, x, x) GPH_SWIZZLE3(Vec3, z, x, y) GPH_SWIZZLE3(Vec3, z, x, z) \
	GPH_SWIZZLE3(Vec3, z, y, x) GPH_SWIZZLE3(Vec3, z, y, y) GPH_SWIZZLE3(Vec3, z, y, z) \
	GPH_SWIZZLE3(Vec3, z, z, x) GPH_SWIZZLE3(Vec3, z, z, y) GPH_SWIZZLE3(Vec3, z, z, z) \
	GPH_SWIZZLE4(Vec3, x, x, x, x) GPH_SWIZZLE4(Vec3, x, x, x, y) GPH_SWIZZLE4(Vec3, x, x, x, z) \
	GPH_SWIZZLE4(Vec3, x, x, y, x) GPH_SWIZZLE4(Vec3, x, x, y, y) GPH_SWIZZLE4(Vec3, x, x, y, z) \
	GPH_SWIZZLE4(Vec3, x, x, z, x) GPH_SWIZZLE4(Vec3, x, x, z, y) GPH_SWIZZLE4(Vec3, x, x, z, z) \
	GPH_SWIZZLE4(Vec3, x, y, x, x) GPH_SWIZZLE4(Vec3, x, y, x, y) GPH_SWIZZLE4(Vec3, x, y, x, z) \
	GPH_SWIZZLE4(Vec3, x, y, y, x) GPH_SWIZZLE4(Vec3, x, y, y, y) GPH_SWIZZLE4(Vec3, x, y, y, z) \
	GPH_SWIZZLE4(Vec3, x, y, z, x) GPH_SWIZZLE4(Vec3, x, y, z, y) GPH_SWIZZLE4(Vec3, x, y, z, z) \
	GPH_SWIZZLE4(Vec3, x, z, x, x) GPH_SWIZZLE4(Vec3, x, z, x, y) GPH_SWIZZLE4(Vec3, x, z, x, z) \
	GPH_SWIZZLE4(Vec3, x, z, y, x) GPH_SWIZZLE4(Vec3, x, z, y, y) GPH_SWIZZLE4(Vec3, x, z, y, z) \
	GPH_SWIZZLE4(Vec3, x, z, z, x) GPH_SWIZZLE4(Vec3, x, z, z, y) GPH_SWIZZLE4(Vec3, x, z, z, z) \
	GPH_SWIZZLE4(Vec3, y, x, x, x) GPH_SWIZZLE4(Vec3, y, x, x, y) GPH_SWIZZLE4(Vec3, y, x, x, z) \
	GPH_SWIZZLE4(Vec3, y, x, y, x) GPH_SWIZZLE4(Vec3, y, x, y, y) GPH_SWIZZLE4(Vec3, y, x, y, z) \
	GPH_SWIZZLE4(Vec3, y, x, z, x) GPH_SWIZZLE4(Vec3, y, x, z, y) GPH_SWIZZLE4(Vec3, y, x, z, z) \
	GPH_SWIZZLE4(Vec3, y, y, x, x) GPH_SWIZZLE4(Vec3, y, y, x, y) GPH_SWIZZLE4(Vec3, y, y, x, z) \
	GPH_SWIZZLE4(Vec3, y, y, y, x) GPH_SWIZZLE4(Vec3, y, y, y, y) GPH_SWIZZLE4(Vec3, y, y, y, z) \
	GPH_SWIZZLE4(Vec3, y, y, z, x) GPH_SWIZZLE4(Vec3, y, y, z, y) GPH_SWIZZLE4(Vec3, y, y, z, z) \
	GPH_SWIZZLE4(Vec3, y, z, x, x) GPH_SWIZZLE4(Vec3, y, z, x, y) GPH_SWIZZLE4(Vec3, y, z, x, z) \
	GPH_SWIZZLE4(Vec3, y, z, y, x) GPH_SWIZZLE4(Vec3, y, z, y, y) GPH_SWIZZLE4(Vec3, y, z, y, z) \
	GPH_SWIZZLE4(Vec3, y, z, z, x) GPH_SWIZZLE4(Vec3, y, z, z, y) GPH_SWIZZLE4(Vec3, y, z, z, z) \
	GPH_SWIZZLE4(Vec3, z, x, x, x) GPH_SWIZZLE4(Vec3, z, x, x, y) GPH_SWIZZLE4(Vec3, z, x, x, z) \
	GPH_SWIZZLE4(Vec3, z, x, y, x) GPH_SWIZZLE4(Vec3, z, x, y, y) GPH_SWIZZLE4(Vec3, z, x, y, z) \
	GPH_SWIZZLE4(Vec3, z, x, z, x) GPH_SWIZZLE4(Vec3, z, x, z, y) GPH_SWIZZLE4(Vec3, z, x, z, z) \
	GPH_SWIZZLE4(Vec3, z, y, x, x) GPH_SWIZZLE4(Vec3, z, y, x, y) GPH_SWIZZLE4(Vec3, z, y, x, z) \
	GPH_SWIZZLE4(Vec3, z, y, y, x) GPH_SWIZZLE4(Vec3, z, y, y, y) GPH_SWIZZLE4(Vec3, z, y, y, z) \
	GPH_SWIZZLE4(Vec3, z, y, z, x) GPH_SWIZZLE4(Vec3, z, y, z, y) GPH_SWIZZLE4(Vec3, z, y, z, z) \
	GPH_SWIZZLE4(Vec3, z, z, x, x) GPH_SWIZZLE4(Vec3, z, z, x, y) GPH_SWIZZLE4(Vec3, z, z, x, z) \
	GPH_SWIZZLE4(Vec3, z, z, y, x) GPH_SWIZZLE4(Vec3, z, z, y, y) GPH_SWIZZLE4(Vec3, z, z, y, z) \
	GPH_SWIZZLE4(Vec3, z, z, z, x) GPH_SWIZZLE4(Vec3, z, z, z, y) GPH_SWIZZLE4(Vec3, z, z, z, z)

// swizzle macros for Vec4 (oh shit...)
#define GPH_VEC4_SWIZZLE	\
	GPH_SWIZZLE2(Vec4, x, x) GPH_SWIZZLE2(Vec4, x, y) GPH_SWIZZLE2(Vec4, x, z) GPH_SWIZZLE2(Vec4, x, w) \
	GPH_SWIZZLE2(Vec4, y, x) GPH_SWIZZLE2(Vec4, y, y) GPH_SWIZZLE2(Vec4, y, z) GPH_SWIZZLE2(Vec4, y, w) \
	GPH_SWIZZLE2(Vec4, z, x) GPH_SWIZZLE2(Vec4, z, y) GPH_SWIZZLE2(Vec4, z, z) GPH_SWIZZLE2(Vec4, z, w) \
	GPH_SWIZZLE2(Vec4, w, x) GPH_SWIZZLE2(Vec4, w, y) GPH_SWIZZLE2(Vec4, w, z) GPH_SWIZZLE2(Vec4, w, w) \
	GPH_SWIZZLE3(Vec4, x, x, x) GPH_SWIZZLE3(Vec4, x, x, y) GPH_SWIZZLE3(Vec4, x, x, z) GPH_SWIZZLE3(Vec4, x, x, w) \
	GPH_SWIZZLE3(Vec4, x, y, x) GPH_SWIZZLE3(Vec4, x, y, y) GPH_SWIZZLE3(Vec4, x, y, z) GPH_SWIZZLE3(Vec4, x, y, w) \
	GPH_SWIZZLE3(Vec4, x, z, x) GPH_SWIZZLE3(Vec4, x, z, y) GPH_SWIZZLE3(Vec4, x, z, z) GPH_SWIZZLE3(Vec4, x, z, w) \
	GPH_SWIZZLE3(Vec4, x, w, x) GPH_SWIZZLE3(Vec4, x, w, y) GPH_SWIZZLE3(Vec4, x, w, z) GPH_SWIZZLE3(Vec4, x, w, w) \
	GPH_SWIZZLE3(Vec4, y, x, x) GPH_SWIZZLE3(Vec4, y, x, y) GPH_SWIZZLE3(Vec4, y, x, z) GPH_SWIZZLE3(Vec4, y, x, w) \
	GPH_SWIZZLE3(Vec4, y, y, x) GPH_SWIZZLE3(Vec4, y, y, y) GPH_SWIZZLE3(Vec4, y, y, z) GPH_SWIZZLE3(Vec4, y, y, w) \
	GPH_SWIZZLE3(Vec4, y, z, x) GPH_SWIZZLE3(Vec4, y, z, y) GPH_SWIZZLE3(Vec4, y, z, z) GPH_SWIZZLE3(Vec4, y, z, w) \
	GPH_SWIZZLE3(Vec4, y, w, x) GPH_SWIZZLE3(Vec4, y, w, y) GPH_SWIZZLE3(Vec4, y, w, z) GPH_SWIZZLE3(Vec4, y, w, w) \
	GPH_SWIZZLE3(Vec4, z, x, x) GPH_SWIZZLE3(Vec4, z, x, y) GPH_SWIZZLE3(Vec4, z, x, z) GPH_SWIZZLE3(Vec4, z, x, w) \
	GPH_SWIZZLE3(Vec4, z, y, x) GPH_SWIZZLE3(Vec4, z, y, y) GPH_SWIZZLE3(Vec4, z, y, z) GPH_SWIZZLE3(Vec4, z, y, w) \
	GPH_SWIZZLE3(Vec4, z, z, x) GPH_SWIZZLE3(Vec4, z, z, y) GPH_SWIZZLE3(Vec4, z, z, z) GPH_SWIZZLE3(Vec4, z, z, w) \
	GPH_SWIZZLE3(Vec4, z, w, x) GPH_SWIZZLE3(Vec4, z, w, y) GPH_SWIZZLE3(Vec4, z, w, z) GPH_SWIZZLE3(Vec4, z, w, w) \
	GPH_SWIZZLE3(Vec4, w, x, x) GPH_SWIZZLE3(Vec4, w, x, y) GPH_SWIZZLE3(Vec4, w, x, z) GPH_SWIZZLE3(Vec4, w, x, w) \
	GPH_SWIZZLE3(Vec4, w, y, x) GPH_SWIZZLE3(Vec4, w, y, y) GPH_SWIZZLE3(Vec4, w, y, z) GPH_SWIZZLE3(Vec4, w, y, w) \
	GPH_SWIZZLE3(Vec4, w, z, x) GPH_SWIZZLE3(Vec4, w, z, y) GPH_SWIZZLE3(Vec4, w, z, z) GPH_SWIZZLE3(Vec4, w, z, w) \
	GPH_SWIZZLE3(Vec4, w, w, x) GPH_SWIZZLE3(Vec4, w, w, y) GPH_SWIZZLE3(Vec4, w, w, z) GPH_SWIZZLE3(Vec4, w, w, w) \
	GPH_SWIZZLE4(Vec4, x, x, x, x) GPH_SWIZZLE4(Vec4, x, x, x, y) GPH_SWIZZLE4(Vec4, x, x, x, z) GPH_SWIZZLE4(Vec4, x, x, x, w) \
	GPH_SWIZZLE4(Vec4, x, x, y, x) GPH_SWIZZLE4(Vec4, x, x, y, y) GPH_SWIZZLE4(Vec4, x, x, y, z) GPH_SWIZZLE4(Vec4, x, x, y, w) \
	GPH_SWIZZLE4(Vec4, x, x, z, x) GPH_SWIZZLE4(Vec4, x, x, z, y) GPH_SWIZZLE4(Vec4, x, x, z, z) GPH_SWIZZLE4(Vec4, x, x, z, w) \
	GPH_SWIZZLE4(Vec4, x, x, w, x) GPH_SWIZZLE4(Vec4, x, x, w, y) GPH_SWIZZLE4(Vec4, x, x, w, z) GPH_SWIZZLE4(Vec4, x, x, w, w) \
	GPH_SWIZZLE4(Vec4, x, y, x, x) GPH_SWIZZLE4(Vec4, x, y, x, y) GPH_SWIZZLE4(Vec4, x, y, x, z) GPH_SWIZZLE4(Vec4, x, y, x, w) \
	GPH_SWIZZLE4(Vec4, x, y, y, x) GPH_SWIZZLE4(Vec4, x, y, y, y) GPH_SWIZZLE4(Vec4, x, y, y, z) GPH_SWIZZLE4(Vec4, x, y, y, w) \
	GPH_SWIZZLE4(Vec4, x, y, z, x) GPH_SWIZZLE4(Vec4, x, y, z, y) GPH_SWIZZLE4(Vec4, x, y, z, z) GPH_SWIZZLE4(Vec4, x, y, z, w) \
	GPH_SWIZZLE4(Vec4, x, y, w, x) GPH_SWIZZLE4(Vec4, x, y, w, y) GPH_SWIZZLE4(Vec4, x, y, w, z) GPH_SWIZZLE4(Vec4, x, y, w, w) \
	GPH_SWIZZLE4(Vec4, x, z, x, x) GPH_SWIZZLE4(Vec4, x, z, x, y) GPH_SWIZZLE4(Vec4, x, z, x, z) GPH_SWIZZLE4(Vec4, x, z, x, w) \
	GPH_SWIZZLE4(Vec4, x, z, y, x) GPH_SWIZZLE4(Vec4, x, z, y, y) GPH_SWIZZLE4(Vec4, x, z, y, z) GPH_SWIZZLE4(Vec4, x, z, y, w) \
	GPH_SWIZZLE4(Vec4, x, z, z, x) GPH_SWIZZLE4(Vec4, x, z, z, y) GPH_SWIZZLE4(Vec4, x, z, z, z) GPH_SWIZZLE4(Vec4, x, z, z, w) \
	GPH_SWIZZLE4(Vec4, x, z, w, x) GPH_SWIZZLE4(Vec4, x, z, w, y) GPH_SWIZZLE4(Vec4, x, z, w, z) GPH_SWIZZLE4(Vec4, x, z, w, w) \
	GPH_SWIZZLE4(Vec4, x, w, x, x) GPH_SWIZZLE4(Vec4, x, w, x, y) GPH_SWIZZLE4(Vec4, x, w, x, z) GPH_SWIZZLE4(Vec4, x, w, x, w) \
	GPH_SWIZZLE4(Vec4, x, w, y, x) GPH_SWIZZLE4(Vec4, x, w, y, y) GPH_SWIZZLE4(Vec4, x, w, y, z) GPH_SWIZZLE4(Vec4, x, w, y, w) \
	GPH_SWIZZLE4(Vec4, x, w, z, x) GPH_SWIZZLE4(Vec4, x, w, z, y) GPH_SWIZZLE4(Vec4, x, w, z, z) GPH_SWIZZLE4(Vec4, x, w, z, w) \
	GPH_SWIZZLE4(Vec4, x, w, w, x) GPH_SWIZZLE4(Vec4, x, w, w, y) GPH_SWIZZLE4(Vec4, x, w, w, z) GPH_SWIZZLE4(Vec4, x, w, w, w) \
	GPH_SWIZZLE4(Vec4, y, x, x, x) GPH_SWIZZLE4(Vec4, y, x, x, y) GPH_SWIZZLE4(Vec4, y, x, x, z) GPH_SWIZZLE4(Vec4, y, x, x, w) \
	GPH_SWIZZLE4(Vec4, y, x, y, x) GPH_SWIZZLE4(Vec4, y, x, y, y) GPH_SWIZZLE4(Vec4, y, x, y, z) GPH_SWIZZLE4(Vec4, y, x, y, w) \
	GPH_SWIZZLE4(Vec4, y, x, z, x) GPH_SWIZZLE4(Vec4, y, x, z, y) GPH_SWIZZLE4(Vec4, y, x, z, z) GPH_SWIZZLE4(Vec4, y, x, z, w) \
	GPH_SWIZZLE4(Vec4, y, x, w, x) GPH_SWIZZLE4(Vec4, y, x, w, y) GPH_SWIZZLE4(Vec4, y, x, w, z) GPH_SWIZZLE4(Vec4, y, x, w, w) \
	GPH_SWIZZLE4(Vec4, y, y, x, x) GPH_SWIZZLE4(Vec4, y, y, x, y) GPH_SWIZZLE4(Vec4, y, y, x, z) GPH_SWIZZLE4(Vec4, y, y, x, w) \
	GPH_SWIZZLE4(Vec4, y, y, y, x) GPH_SWIZZLE4(Vec4, y, y, y, y) GPH_SWIZZLE4(Vec4, y, y, y, z) GPH_SWIZZLE4(Vec4, y, y, y, w) \
	GPH_SWIZZLE4(Vec4, y, y, z, x) GPH_SWIZZLE4(Vec4, y, y, z, y) GPH_SWIZZLE4(Vec4, y, y, z, z) GPH_SWIZZLE4(Vec4, y, y, z, w) \
	GPH_SWIZZLE4(Vec4, y, y, w, x) GPH_SWIZZLE4(Vec4, y, y, w, y) GPH_SWIZZLE4(Vec4, y, y, w, z) GPH_SWIZZLE4(Vec4, y, y, w, w) \
	GPH_SWIZZLE4(Vec4, y, z, x, x) GPH_SWIZZLE4(Vec4, y, z, x, y) GPH_SWIZZLE4(Vec4, y, z, x, z) GPH_SWIZZLE4(Vec4, y, z, x, w) \
	GPH_SWIZZLE4(Vec4, y, z, y, x) GPH_SWIZZLE4(Vec4, y, z, y, y) GPH_SWIZZLE4(Vec4, y, z, y, z) GPH_SWIZZLE4(Vec4, y, z, y, w) \
	GPH_SWIZZLE4(Vec4, y, z, z, x) GPH_SWIZZLE4(Vec4, y, z, z, y) GPH_SWIZZLE4(Vec4, y, z, z, z) GPH_SWIZZLE4(Vec4, y, z, z, w) \
	GPH_SWIZZLE4(Vec4, y, z, w, x) GPH_SWIZZLE4(Vec4, y, z, w, y) GPH_SWIZZLE4(Vec4, y, z, w, z) GPH_SWIZZLE4(Vec4, y, z, w, w) \
	GPH_SWIZZLE4(Vec4, y, w, x, x) GPH_SWIZZLE4(Vec4, y, w, x, y) GPH_SWIZZLE4(Vec4, y, w, x, z) GPH_SWIZZLE4(Vec4, y, w, x, w) \
	GPH_SWIZZLE4(Vec4, y, w, y, x) GPH_SWIZZLE4(Vec4, y, w, y, y) GPH_SWIZZLE4(Vec4, y, w, y, z) GPH_SWIZZLE4(Vec4, y, w, y, w) \
	GPH_SWIZZLE4(Vec4, y, w, z, x) GPH_SWIZZLE4(Vec4, y, w, z, y) GPH_SWIZZLE4(Vec4, y, w, z, z) GPH_SWIZZLE4(Vec4, y, w, z, w) \
	GPH_SWIZZLE4(Vec4, y, w, w, x) GPH_SWIZZLE4(Vec4, y, w, w, y) GPH_SWIZZLE4(Vec4, y, w, w, z) GPH_SWIZZLE4(Vec4, y, w, w, w) \
	GPH_SWIZZLE4(Vec4, z, x, x, x) GPH_SWIZZLE4(Vec4, z, x, x, y) GPH_SWIZZLE4(Vec4, z, x, x, z) GPH_SWIZZLE4(Vec4, z, x, x, w) \
	GPH_SWIZZLE4(Vec4, z, x, y, x) GPH_SWIZZLE4(Vec4, z, x, y, y) GPH_SWIZZLE4(Vec4, z, x, y, z) GPH_SWIZZLE4(Vec4, z, x, y, w) \
	GPH_SWIZZLE4(Vec4, z, x, z, x) GPH_SWIZZLE4(Vec4, z, x, z, y) GPH_SWIZZLE4(Vec4, z, x, z, z) GPH_SWIZZLE4(Vec4, z, x, z, w) \
	GPH_SWIZZLE4(Vec4, z, x, w, x) GPH_SWIZZLE4(Vec4, z, x, w, y) GPH_SWIZZLE4(Vec4, z, x, w, z) GPH_SWIZZLE4(Vec4, z, x, w, w) \
	GPH_SWIZZLE4(Vec4, z, y, x, x) GPH_SWIZZLE4(Vec4, z, y, x, y) GPH_SWIZZLE4(Vec4, z, y, x, z) GPH_SWIZZLE4(Vec4, z, y, x, w) \
	GPH_SWIZZLE4(Vec4, z, y, y, x) GPH_SWIZZLE4(Vec4, z, y, y, y) GPH_SWIZZLE4(Vec4, z, y, y, z) GPH_SWIZZLE4(Vec4, z, y, y, w) \
	GPH_SWIZZLE4(Vec4, z, y, z, x) GPH_SWIZZLE4(Vec4, z, y, z, y) GPH_SWIZZLE4(Vec4, z, y, z, z) GPH_SWIZZLE4(Vec4, z, y, z, w) \
	GPH_SWIZZLE4(Vec4, z, y, w, x) GPH_SWIZZLE4(Vec4, z, y, w, y) GPH_SWIZZLE4(Vec4, z, y, w, z) GPH_SWIZZLE4(Vec4, z, y, w, w) \
	GPH_SWIZZLE4(Vec4, z, z, x, x) GPH_SWIZZLE4(Vec4, z, z, x, y) GPH_SWIZZLE4(Vec4, z, z, x, z) GPH_SWIZZLE4(Vec4, z, z, x, w) \
	GPH_SWIZZLE4(Vec4, z, z, y, x) GPH_SWIZZLE4(Vec4, z, z, y, y) GPH_SWIZZLE4(Vec4, z, z, y, z) GPH_SWIZZLE4(Vec4, z, z, y, w) \
	GPH_SWIZZLE4(Vec4, z, z, z, x) GPH_SWIZZLE4(Vec4, z, z, z, y) GPH_SWIZZLE4(Vec4, z, z, z, z) GPH_SWIZZLE4(Vec4, z, z, z, w) \
	GPH_SWIZZLE4(Vec4, z, z, w, x) GPH_SWIZZLE4(Vec4, z, z, w, y) GPH_SWIZZLE4(Vec4, z, z, w, z) GPH_SWIZZLE4(Vec4, z, z, w, w) \
	GPH_SWIZZLE4(Vec4, z, w, x, x) GPH_SWIZZLE4(Vec4, z, w, x, y) GPH_SWIZZLE4(Vec4, z, w, x, z) GPH_SWIZZLE4(Vec4, z, w, x, w) \
	GPH_SWIZZLE4(Vec4, z, w, y, x) GPH_SWIZZLE4(Vec4, z, w, y, y) GPH_SWIZZLE4(Vec4, z, w, y, z) GPH_SWIZZLE4(Vec4, z, w, y, w) \
	GPH_SWIZZLE4(Vec4, z, w, z, x) GPH_SWIZZLE4(Vec4, z, w, z, y) GPH_SWIZZLE4(Vec4, z, w, z, z) GPH_SWIZZLE4(Vec4, z, w, z, w) \
	GPH_SWIZZLE4(Vec4, z, w, w, x) GPH_SWIZZLE4(Vec4, z, w, w, y) GPH_SWIZZLE4(Vec4, z, w, w, z) GPH_SWIZZLE4(Vec4, z, w, w, w) \
	GPH_SWIZZLE4(Vec4, w, x, x, x) GPH_SWIZZLE4(Vec4, w, x, x, y) GPH_SWIZZLE4(Vec4, w, x, x, z) GPH_SWIZZLE4(Vec4, w, x, x, w) \
	GPH_SWIZZLE4(Vec4, w, x, y, x) GPH_SWIZZLE4(Vec4, w, x, y, y) GPH_SWIZZLE4(Vec4, w, x, y, z) GPH_SWIZZLE4(Vec4, w, x, y, w) \
	GPH_SWIZZLE4(Vec4, w, x, z, x) GPH_SWIZZLE4(Vec4, w, x, z, y) GPH_SWIZZLE4(Vec4, w, x, z, z) GPH_SWIZZLE4(Vec4, w, x, z, w) \
	GPH_SWIZZLE4(Vec4, w, x, w, x) GPH_SWIZZLE4(Vec4, w, x, w, y) GPH_SWIZZLE4(Vec4, w, x, w, z) GPH_SWIZZLE4(Vec4, w, x, w, w) \
	GPH_SWIZZLE4(Vec4, w, y, x, x) GPH_SWIZZLE4(Vec4, w, y, x, y) GPH_SWIZZLE4(Vec4, w, y, x, z) GPH_SWIZZLE4(Vec4, w, y, x, w) \
	GPH_SWIZZLE4(Vec4, w, y, y, x) GPH_SWIZZLE4(Vec4, w, y, y, y) GPH_SWIZZLE4(Vec4, w, y, y, z) GPH_SWIZZLE4(Vec4, w, y, y, w) \
	GPH_SWIZZLE4(Vec4, w, y, z, x) GPH_SWIZZLE4(Vec4, w, y, z, y) GPH_SWIZZLE4(Vec4, w, y, z, z) GPH_SWIZZLE4(Vec4, w, y, z, w) \
	GPH_SWIZZLE4(Vec4, w, y, w, x) GPH_SWIZZLE4(Vec4, w, y, w, y) GPH_SWIZZLE4(Vec4, w, y, w, z) GPH_SWIZZLE4(Vec4, w, y, w, w) \
	GPH_SWIZZLE4(Vec4, w, z, x, x) GPH_SWIZZLE4(Vec4, w, z, x, y) GPH_SWIZZLE4(Vec4, w, z, x, z) GPH_SWIZZLE4(Vec4, w, z, x, w) \
	GPH_SWIZZLE4(Vec4, w, z, y, x) GPH_SWIZZLE4(Vec4, w, z, y, y) GPH_SWIZZLE4(Vec4, w, z, y, z) GPH_SWIZZLE4(Vec4, w, z, y, w) \
	GPH_SWIZZLE4(Vec4, w, z, z, x) GPH_SWIZZLE4(Vec4, w, z, z, y) GPH_SWIZZLE4(Vec4, w, z, z, z) GPH_SWIZZLE4(Vec4, w, z, z, w) \
	GPH_SWIZZLE4(Vec4, w, z, w, x) GPH_SWIZZLE4(Vec4, w, z, w, y) GPH_SWIZZLE4(Vec4, w, z, w, z) GPH_SWIZZLE4(Vec4, w, z, w, w) \
	GPH_SWIZZLE4(Vec4, w, w, x, x) GPH_SWIZZLE4(Vec4, w, w, x, y) GPH_SWIZZLE4(Vec4, w, w, x, z) GPH_SWIZZLE4(Vec4, w, w, x, w) \
	GPH_SWIZZLE4(Vec4, w, w, y, x) GPH_SWIZZLE4(Vec4, w, w, y, y) GPH_SWIZZLE4(Vec4, w, w, y, z) GPH_SWIZZLE4(Vec4, w, w, y, w) \
	GPH_SWIZZLE4(Vec4, w, w, z, x) GPH_SWIZZLE4(Vec4, w, w, z, y) GPH_SWIZZLE4(Vec4, w, w, z, z) GPH_SWIZZLE4(Vec4, w, w, z, w) \
	GPH_SWIZZLE4(Vec4, w, w, w, x) GPH_SWIZZLE4(Vec4, w, w, w, y) GPH_SWIZZLE4(Vec4, w, w, w, z) GPH_SWIZZLE4(Vec4, w, w, w, w)
