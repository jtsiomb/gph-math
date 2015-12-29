inline Quaternion operator -(const Quaternion &q)
{
	return Quaternion(-q.x, -q.y, -q.z, -q.w);
}

inline Quaternion operator +(const Quaternion &a, const Quaternion &b)
{
	return Quaternion(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Quaternion operator -(const Quaternion &a, const Quaternion &b)
{
	return Quaternion(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Quaternion operator *(const Quaternion &a, const Quaternion &b)
{
	float x = a.w * b.w - (a.x * b.x + a.y * b.y + a.z * b.z);
