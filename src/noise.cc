#include <stdlib.h>
#include "gmath.h"
#include "noise.h"

namespace gph {

/* ---- Ken Perlin's implementation of noise ---- */
#define B	0x100
#define BM	0xff
#define N	0x1000
#define NP	12   /* 2^N */
#define NM	0xfff

#define s_curve(t) (t * t * (3.0f - 2.0f * t))

#define setup(elem, b0, b1, r0, r1) \
	do {							\
		float t = elem + N;		\
		b0 = ((int)t) & BM;			\
		b1 = (b0 + 1) & BM;			\
		r0 = t - (int)t;			\
		r1 = r0 - 1.0f;				\
	} while(0)

#define setup_p(elem, b0, b1, r0, r1, p) \
	do {							\
		float t = elem + N;		\
		b0 = (((int)t) & BM) % p;	\
		b1 = ((b0 + 1) & BM) % p;	\
		r0 = t - (int)t;			\
		r1 = r0 - 1.0f;				\
	} while(0)


static int perm[B + B + 2];			/* permuted index from g_n onto themselves */
static Vec3 grad3[B + B + 2];		/* 3D random gradients */
static Vec2 grad2[B + B + 2];		/* 2D random gradients */
static float grad1[B + B + 2];		/* 1D random ... slopes */
static bool tables_valid;

#define init_once()	if(!tables_valid) init_noise()

static void init_noise()
{
	/* calculate random gradients */
	for(int i=0; i<B; i++) {
		perm[i] = i;	/* .. and initialize permutation mapping to identity */

		grad1[i] = (float)((rand() % (B + B)) - B) / B;

		grad2[i].x = (float)((rand() % (B + B)) - B) / B;
		grad2[i].y = (float)((rand() % (B + B)) - B) / B;
		grad2[i] = normalize(grad2[i]);

		grad3[i].x = (float)((rand() % (B + B)) - B) / B;
		grad3[i].y = (float)((rand() % (B + B)) - B) / B;
		grad3[i].z = (float)((rand() % (B + B)) - B) / B;
		grad3[i] = normalize(grad3[i]);
	}

	/* permute indices by swapping them randomly */
	for(int i=0; i<B; i++) {
		int rand_idx = rand() % B;

		int tmp = perm[i];
		perm[i] = perm[rand_idx];
		perm[rand_idx] = tmp;
	}

	/* fill up the rest of the arrays by duplicating the existing gradients */
	/* and permutations */
	for(int i=0; i<B+2; i++) {
		perm[B + i] = perm[i];
		grad1[B + i] = grad1[i];
		grad2[B + i] = grad2[i];
		grad3[B + i] = grad3[i];
	}

	tables_valid = true;
}


float noise(float x)
{
	int bx0, bx1;
	float rx0, rx1, sx, u, v;

	init_once();

	setup(x, bx0, bx1, rx0, rx1);
	sx = s_curve(rx0);
	u = rx0 * grad1[perm[bx0]];
	v = rx1 * grad1[perm[bx1]];
	return lerp(u, v, sx);
}

float noise(float x, float y)
{
	int i, j, b00, b10, b01, b11;
	int bx0, bx1, by0, by1;
	float rx0, rx1, ry0, ry1;
	float sx, sy, u, v, a, b;

	init_once();

	setup(x, bx0, bx1, rx0, rx1);
	setup(y, by0, by1, ry0, ry1);

	i = perm[bx0];
	j = perm[bx1];

	b00 = perm[i + by0];
	b10 = perm[j + by0];
	b01 = perm[i + by1];
	b11 = perm[j + by1];

	/* calculate hermite inteprolating factors */
	sx = s_curve(rx0);
	sy = s_curve(ry0);

	/* interpolate along the left edge */
	u = dot(grad2[b00], Vec2(rx0, ry0));
	v = dot(grad2[b10], Vec2(rx1, ry0));
	a = lerp(u, v, sx);

	/* interpolate along the right edge */
	u = dot(grad2[b01], Vec2(rx0, ry1));
	v = dot(grad2[b11], Vec2(rx1, ry1));
	b = lerp(u, v, sx);

	/* interpolate between them */
	return lerp(a, b, sy);
}

float noise(float x, float y, float z)
{
	int i, j;
	int bx0, bx1, by0, by1, bz0, bz1;
	int b00, b10, b01, b11;
	float rx0, rx1, ry0, ry1, rz0, rz1;
	float sx, sy, sz;
	float u, v, a, b, c, d;

	init_once();

	setup(x, bx0, bx1, rx0, rx1);
	setup(y, by0, by1, ry0, ry1);
	setup(z, bz0, bz1, rz0, rz1);

	i = perm[bx0];
	j = perm[bx1];

	b00 = perm[i + by0];
	b10 = perm[j + by0];
	b01 = perm[i + by1];
	b11 = perm[j + by1];

	/* calculate hermite interpolating factors */
	sx = s_curve(rx0);
	sy = s_curve(ry0);
	sz = s_curve(rz0);

	/* interpolate along the top slice of the cell */
	u = dot(grad3[b00 + bz0], Vec3(rx0, ry0, rz0));
	v = dot(grad3[b10 + bz0], Vec3(rx1, ry0, rz0));
	a = lerp(u, v, sx);

	u = dot(grad3[b01 + bz0], Vec3(rx0, ry1, rz0));
	v = dot(grad3[b11 + bz0], Vec3(rx1, ry1, rz0));
	b = lerp(u, v, sx);

	c = lerp(a, b, sy);

	/* interpolate along the bottom slice of the cell */
	u = dot(grad3[b00 + bz0], Vec3(rx0, ry0, rz1));
	v = dot(grad3[b10 + bz0], Vec3(rx1, ry0, rz1));
	a = lerp(u, v, sx);

	u = dot(grad3[b01 + bz0], Vec3(rx0, ry1, rz1));
	v = dot(grad3[b11 + bz0], Vec3(rx1, ry1, rz1));
	b = lerp(u, v, sx);

	d = lerp(a, b, sy);

	/* interpolate between slices */
	return lerp(c, d, sz);
}

float noise(float x, float y, float z, float w)
{
	return 0;	/* TODO */
}


float pnoise(float x, int period)
{
	int bx0, bx1;
	float rx0, rx1, sx, u, v;

	init_once();

	setup_p(x, bx0, bx1, rx0, rx1, period);
	sx = s_curve(rx0);
	u = rx0 * grad1[perm[bx0]];
	v = rx1 * grad1[perm[bx1]];
	return lerp(u, v, sx);
}

float pnoise(float x, float y, int per_x, int per_y)
{
	int i, j, b00, b10, b01, b11;
	int bx0, bx1, by0, by1;
	float rx0, rx1, ry0, ry1;
	float sx, sy, u, v, a, b;

	init_once();

	setup_p(x, bx0, bx1, rx0, rx1, per_x);
	setup_p(y, by0, by1, ry0, ry1, per_y);

	i = perm[bx0];
	j = perm[bx1];

	b00 = perm[i + by0];
	b10 = perm[j + by0];
	b01 = perm[i + by1];
	b11 = perm[j + by1];

	/* calculate hermite inteprolating factors */
	sx = s_curve(rx0);
	sy = s_curve(ry0);

	/* interpolate along the left edge */
	u = dot(grad2[b00], Vec2(rx0, ry0));
	v = dot(grad2[b10], Vec2(rx1, ry0));
	a = lerp(u, v, sx);

	/* interpolate along the right edge */
	u = dot(grad2[b01], Vec2(rx0, ry1));
	v = dot(grad2[b11], Vec2(rx1, ry1));
	b = lerp(u, v, sx);

	/* interpolate between them */
	return lerp(a, b, sy);
}

float pnoise(float x, float y, float z, int per_x, int per_y, int per_z)
{
	int i, j;
	int bx0, bx1, by0, by1, bz0, bz1;
	int b00, b10, b01, b11;
	float rx0, rx1, ry0, ry1, rz0, rz1;
	float sx, sy, sz;
	float u, v, a, b, c, d;

	init_once();

	setup_p(x, bx0, bx1, rx0, rx1, per_x);
	setup_p(y, by0, by1, ry0, ry1, per_y);
	setup_p(z, bz0, bz1, rz0, rz1, per_z);

	i = perm[bx0];
	j = perm[bx1];

	b00 = perm[i + by0];
	b10 = perm[j + by0];
	b01 = perm[i + by1];
	b11 = perm[j + by1];

	/* calculate hermite interpolating factors */
	sx = s_curve(rx0);
	sy = s_curve(ry0);
	sz = s_curve(rz0);

	/* interpolate along the top slice of the cell */
	u = dot(grad3[b00 + bz0], Vec3(rx0, ry0, rz0));
	v = dot(grad3[b10 + bz0], Vec3(rx1, ry0, rz0));
	a = lerp(u, v, sx);

	u = dot(grad3[b01 + bz0], Vec3(rx0, ry1, rz0));
	v = dot(grad3[b11 + bz0], Vec3(rx1, ry1, rz0));
	b = lerp(u, v, sx);

	c = lerp(a, b, sy);

	/* interpolate along the bottom slice of the cell */
	u = dot(grad3[b00 + bz0], Vec3(rx0, ry0, rz1));
	v = dot(grad3[b10 + bz0], Vec3(rx1, ry0, rz1));
	a = lerp(u, v, sx);

	u = dot(grad3[b01 + bz0], Vec3(rx0, ry1, rz1));
	v = dot(grad3[b11 + bz0], Vec3(rx1, ry1, rz1));
	b = lerp(u, v, sx);

	d = lerp(a, b, sy);

	/* interpolate between slices */
	return lerp(c, d, sz);
}

float pnoise(float x, float y, float z, float w, int per_x, int per_y, int per_z, int per_w)
{
	return 0;
}


float fbm(float x, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += noise(x * freq) / freq;
		freq *= 2.0f;
	}
	return res;
}

float fbm(float x, float y, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += noise(x * freq, y * freq) / freq;
		freq *= 2.0f;
	}
	return res;
}

float fbm(float x, float y, float z, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += noise(x * freq, y * freq, z * freq) / freq;
		freq *= 2.0f;
	}
	return res;

}

float fbm(float x, float y, float z, float w, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += noise(x * freq, y * freq, z * freq, w * freq) / freq;
		freq *= 2.0f;
	}
	return res;
}


float pfbm(float x, int per, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += pnoise(x * freq, per) / freq;
		freq *= 2.0f;
		per *= 2;
	}
	return res;
}

float pfbm(float x, float y, int per_x, int per_y, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += pnoise(x * freq, y * freq, per_x, per_y) / freq;
		freq *= 2.0f;
		per_x *= 2;
		per_y *= 2;
	}
	return res;
}

float pfbm(float x, float y, float z, int per_x, int per_y, int per_z, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += pnoise(x * freq, y * freq, z * freq, per_x, per_y, per_z) / freq;
		freq *= 2.0f;
		per_x *= 2;
		per_y *= 2;
		per_z *= 2;
	}
	return res;
}

float pfbm(float x, float y, float z, float w, int per_x, int per_y, int per_z, int per_w, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += pnoise(x * freq, y * freq, z * freq, w * freq,
				per_x, per_y, per_z, per_w) / freq;
		freq *= 2.0f;
		per_x *= 2;
		per_y *= 2;
		per_z *= 2;
		per_w *= 2;
	}
	return res;
}


float turbulence(float x, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(noise(x * freq) / freq);
		freq *= 2.0f;
	}
	return res;
}

float turbulence(float x, float y, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(noise(x * freq, y * freq) / freq);
		freq *= 2.0f;
	}
	return res;
}

float turbulence(float x, float y, float z, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(noise(x * freq, y * freq, z * freq) / freq);
		freq *= 2.0f;
	}
	return res;
}

float turbulence(float x, float y, float z, float w, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(noise(x * freq, y * freq, z * freq, w * freq) / freq);
		freq *= 2.0f;
	}
	return res;
}


float pturbulence(float x, int per, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(pnoise(x * freq, per) / freq);
		freq *= 2.0f;
		per *= 2;
	}
	return res;
}

float pturbulence(float x, float y, int per_x, int per_y, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(pnoise(x * freq, y * freq, per_x, per_y) / freq);
		freq *= 2.0f;
		per_x *= 2;
		per_y *= 2;
	}
	return res;
}

float pturbulence(float x, float y, float z, int per_x, int per_y, int per_z, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(pnoise(x * freq, y * freq, z * freq, per_x, per_y, per_z) / freq);
		freq *= 2.0f;
		per_x *= 2;
		per_y *= 2;
		per_z *= 2;
	}
	return res;
}

float pturbulence(float x, float y, float z, float w, int per_x, int per_y, int per_z, int per_w, int octaves)
{
	float res = 0.0f, freq = 1.0f;
	for(int i=0; i<octaves; i++) {
		res += fabs(pnoise(x * freq, y * freq, z * freq, w * freq,
				per_x, per_y, per_z, per_w) / freq);
		freq *= 2.0f;
		per_x *= 2;
		per_y *= 2;
		per_z *= 2;
		per_w *= 2;
	}
	return res;
}

}	// namespace gph
