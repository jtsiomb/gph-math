#ifndef NOISE_H_
#define NOISE_H_

namespace gph {

float noise(float x);
float noise(float x, float y);
float noise(float x, float y, float z);
float noise(float x, float y, float z, float w);

float pnoise(float x, int period);
float pnoise(float x, float y, int per_x, int per_y);
float pnoise(float x, float y, float z, int per_x, int per_y, int per_z);
float pnoise(float x, float y, float z, float w, int per_x, int per_y, int per_z, int per_w);

float fbm(float x, int octaves);
float fbm(float x, float y, int octaves);
float fbm(float x, float y, float z, int octaves);
float fbm(float x, float y, float z, float w, int octaves);

float pfbm(float x, int per, int octaves);
float pfbm(float x, float y, int per_x, int per_y, int octaves);
float pfbm(float x, float y, float z, int per_x, int per_y, int per_z, int octaves);
float pfbm(float x, float y, float z, float w, int per_x, int per_y, int per_z, int per_w, int octaves);

float turbulence(float x, int octaves);
float turbulence(float x, float y, int octaves);
float turbulence(float x, float y, float z, int octaves);
float turbulence(float x, float y, float z, float w, int octaves);

float pturbulence(float x, int per, int octaves);
float pturbulence(float x, float y, int per_x, int per_y, int octaves);
float pturbulence(float x, float y, float z, int per_x, int per_y, int per_z, int octaves);
float pturbulence(float x, float y, float z, float w, int per_x, int per_y, int per_z, int per_w, int octaves);


}	// namespace gph

#endif	/* NOISE_H_ */
