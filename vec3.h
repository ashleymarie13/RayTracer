#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <math.h>

/*This class can be either a color or a coordinate.*/
class vec3 {
public:
	float e[3];
	vec3() {}
	vec3(float e1, float e2, float e3) {
		e[0] = e1;
		e[1] = e2;
		e[2] = e3;
	}

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[0]; }
	inline float b() const { return e[1]; }
	inline float g() const { return e[2]; }

	inline const vec3& operator+() const { return *this; } // const member function that returns const value
	inline vec3 operator-() const { 
		return vec3(-e[0], -e[1], -e[2]);
	}
	inline float operator[](int i) const { return e[i]; }
	// one returns an address and the other the value based on this const
	// value. But how??? TODO
	inline float& operator[](int i) { return e[i]; }

	// const & give direct read only access to the parameter without having to recopy the
	// value passed into the function to into the parameter object
	inline vec3& operator+=(const vec3 &v2); // the parameter value is immutable
	inline vec3& operator-=(const vec3 &v2); 
	inline vec3& operator*=(const vec3 &v2);
	inline vec3& operator/=(const vec3 &v2);
	inline vec3& operator*=(const float t);
	inline vec3& operator/=(const float t);

	inline float length() const {
		return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
	}
	inline float squared_length() const {
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}
	inline void make_unit_vector();
};

inline std::istream& operator>>(std::istream &is, vec3 &t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

// Example: cout << (vect3) t; // 
inline std::ostream& operator<<(std::ostream &os, const vec3 &t) {
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline void vec3::make_unit_vector() {
	float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
	e[0] *= k; e[1] *=k; e[2] *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator*(float t, const vec3 &v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, float t) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator/(vec3 v, float t) {
	return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
	return v1.e[0] *v2.e[0] + v1.e[1] *v2.e[1] + v1.e[2] *v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3((v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
				-(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0]),
				(v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]));
}

inline vec3& vec3::operator+=(const vec3 &v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline vec3& vec3::operator-=(const vec3 &v) {
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

inline vec3& vec3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline vec3& vec3::operator/=(const float t) {
	float k = 1.0/t;
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}
