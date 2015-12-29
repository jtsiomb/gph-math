#ifndef QUATERNION_H_
#define QUATERNION_H_

namespace gph {

class Quaternion {
public:
	float x, y, z, w;	// w + xi + yj + zk

	Quaternion() : x(0), y(0), z(0), w(1) {}
	Quaternion(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	Quaternion(const Vector3 &v, float s) : x(v.x), y(v.y), z(v.z), w(s) {}

	// TODO more
};

}	// namespace gph

#endif	// QUATERNION_H_
