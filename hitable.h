#ifndef HITABLEH
#define HITABLEH

#include "ray.h"

struct hit_record {
	float t;
	vec3 p;
	vec3 normal;
};

class hitable {
	public: // i dont understand why we want bounds for t_min < t < t_max
		// virtual means this method can be overriden by classes that extend this one
		virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif

