#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
#include "ray.h"
#include "misc.h"

namespace gph {

/* Generates a random vector on the disc */
Vec2 discrand(float rad)
{
	float theta = 2.0 * M_PI * (float)rand() / RAND_MAX;
	float r = sqrt((float)rand() / RAND_MAX) * rad;
	return Vec2(cos(theta) * r, sin(theta) * r);
}

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

}	// namespace gph

#if defined(__APPLE__) && !defined(TARGET_IPHONE)
#include <xmmintrin.h>

void gph::enable_fpexcept()
{
	unsigned int bits;
	bits = _MM_MASK_INVALID | _MM_MASK_DIV_ZERO | _MM_MASK_OVERFLOW | _MM_MASK_UNDERFLOW;
	_MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() & ~bits);
}

void gph::disable_fpexcept()
{
	unsigned int bits;
	bits = _MM_MASK_INVALID | _MM_MASK_DIV_ZERO | _MM_MASK_OVERFLOW | _MM_MASK_UNDERFLOW;
	_MM_SET_EXCEPTION_MASK(_MM_GET_EXCEPTION_MASK() | bits);
}

#elif defined(__GLIBC__) && !defined(__MINGW32__)
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <fenv.h>

void gph::enable_fpexcept()
{
	feenableexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
}

void gph::disable_fpexcept()
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

void gph::enable_fpexcept()
{
	_clearfp();
	_controlfp(_controlfp(0, 0) & ~(_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW), _MCW_EM);
}

void gph::disable_fpexcept()
{
	_clearfp();
	_controlfp(_controlfp(0, 0) | (_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW), _MCW_EM);
}
#else
void gph::enable_fpexcept() {}
void gph::disable_fpexcept() {}
#endif


gph::Vec3 gph::unproject(const Vec3 &norm_scrpos, const Mat4 &inv_viewproj)
{
	Vec4 in = Vec4(2.0f * norm_scrpos.x - 1.0f, 2.0f * norm_scrpos.y - 1.0f,
			2.0f * norm_scrpos.z - 1.0f, 1.0f);
	Vec4 out = inv_viewproj * in;
	return Vec3(out.x / out.w, out.y / out.w, out.z / out.w);
}

gph::Vec3 gph::unproject(const Vec3 &norm_scrpos, const Mat4 &viewmat, const Mat4 &projmat)
{
	Mat4 xform = inverse(viewmat * projmat);
	return unproject(norm_scrpos, xform);
}

void gph::unproject(float winx, float winy, float winz, const float *view, const float *proj,
		const int *vp, float *objx, float *objy, float *objz)
{
	Mat4 viewmat = Mat4(view);
	Mat4 projmat = Mat4(proj);
	Mat4 inv_pv = inverse(viewmat * projmat);

	Vec3 in = Vec3((winx - vp[0]) / vp[2], (winy - vp[1]) / vp[3], winz);
	Vec3 out = unproject(in, inv_pv);
	*objx = out.x;
	*objy = out.y;
	*objz = out.z;
}

gph::Ray gph::mouse_pick_ray(float nx, float ny, const Mat4 &viewmat, const Mat4 &projmat)
{
	Mat4 inv_pv = inverse(viewmat * projmat);
	Vec3 npos = unproject(Vec3(nx, ny, 0.0f), inv_pv);
	Vec3 fpos = unproject(Vec3(nx, ny, 1.0f), inv_pv);
	return Ray(npos, fpos - npos);
}
