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
