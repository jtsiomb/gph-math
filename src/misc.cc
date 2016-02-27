#include <stdlib.h>
#include "misc.h"

namespace gph {

/* Generates a random vector on the surface of a sphere */
Vec3 sphrand(float rad)
{
	float u = (float)rand() / RAND_MAX;
	float v = (float)rand() / RAND_MAX;

	float theta = 2.0 * M_PI * u;
	float phi = acos(2.0 * v - 1.0);

	float x = rad * cos(theta) * sin(phi);
	float y = rad * sin(theta) * sin(phi);
	float z = rad * cos(phi);
	return Vec3(x, y, z);
}

#if defined(__APPLE__) && !defined(TARGET_IPHONE)
#include <xmmintrin.h>

void enable_fpexcept()
{
	unsigned int bits;
	bits = _MM_MASK_INVALID | _MM_MASK_DIV_ZERO | _MM_MASK_OVERFLOW | _MM_MASK_UNDERFLOW;
	_MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~bits);
}

void disable_fpexcept()
{
	unsigned int bits;
	bits = _MM_MASK_INVALID | _MM_MASK_DIV_ZERO | _MM_MASK_OVERFLOW | _MM_MASK_UNDERFLOW;
	_MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() | bits);
}

#elif defined(__GNUC__) && !defined(TARGET_IPHONE) && !defined(__MINGW32__)
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <fenv.h>

void enable_fpexcept()
{
	feenableexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
}

void disable_fpexcept()
{
	fedisableexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
}

#elif defined(_MSC_VER) || defined(__MINGW32__)
#include <float.h>

#if defined(__MINGW32__) && !defined(_EM_OVERFLOW)
/* if gcc's float.h gets precedence, the mingw MSVC includes won't be declared */
#define _MCW_EM			0x8001f
#define _EM_INVALID		0x10
#define _EM_ZERODIVIDE	0x08
#define _EM_OVERFLOW	0x04
unsigned int __cdecl _clearfp();
unsigned int __cdecl _controlfp(unsigned int, unsigned int);
#endif

void enable_fpexcept()
{
	_clearfp();
	_controlfp(_controlfp(0, 0) & ~(_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW), _MCW_EM);
}

void disable_fpexcept()
{
	_clearfp();
	_controlfp(_controlfp(0, 0) | (_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW), _MCW_EM);
}
#else
void enable_fpexcept() {}
void disable_fpexcept() {}
#endif

}	// namespace gph
