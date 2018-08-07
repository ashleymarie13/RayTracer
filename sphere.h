#ifndef SPHEREH
#define SPHEREH

#include "hitable.h"

class sphere: public hitable {
	public:
		sphere() {}
		sphere(vec3 cen, float r) : center(cen), radius(r) {}; // what does this mean?
		virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
		vec3 center;
		float radius;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center; // A - C
	float a = dot(r.direction(), r.direction()); // B dot B
	float b = dot(oc, r.direction()); // 2* (A-C) dot B
	float c = dot(oc, oc) - radius*radius; // (A-C) fot (A-C) - R*R 
	// if it is negative sqrt(negative) is imaginary solution so 0 roots and no interection
	// if 0 then one intersection
	// if positive then there are 2 roots and 2 places where p(t) intercect the sphere
	float discriminant = b*b - a*c;

	if(discriminant > 0 ) {// if positive then there are 2 solutions/2 interections
		float temp = (-b - sqrt(b*b-a*c))/a; // want smallest intersection first so (-)
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t); //p(t)
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(b*b -a*c))/a; // (+)
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t); // on the ray that just intersected 
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}

#endif