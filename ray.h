#ifndef RAYH  // if not previouslt defined execute code up too the #endif
#define RAYH  // preprocessor will replace this with the entire code from the header 
#include "vec3.h" // from the file or from like std or string class if file is not found it will look elsewhere (libraries?)

class ray {
	public:
		ray() {}
		ray(const vec3& a, const vec3& b) { A = a; B = b; }
		vec3 origin() const { return A; }
		vec3 direction() const { return B; }
		vec3 point_at_parameter(float t) const {return A + t*B; }

		vec3 A;
		vec3 B;
};

#endif