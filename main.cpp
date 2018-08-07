#include <iostream>
#include <fstream>
#include "sphere.h" // pastes entire contents of header file
#include "hitable_list.h"
#include "float.h"
#include "camera.h"

vec3 color(const ray& r, hitable *world) {
	hit_record rec;
	if(world->hit(r, 0.0, MAXFLOAT, rec)) {
		return 0.5*vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);// making the normal between 0 and 1
	} else {
		// linear interpolation (making the gradient) along y from 0 - 1
		vec3 unit_direction = unit_vector(r.direction()); // unit vector(B)
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0); // making a gradient
	}
}

int main() {
		// print to file
		FILE *output = fopen("output.ppm", "wb");
		// Image Dimention
		int nx = 200;
		int ny = 100;
		int ns = 100; // ?
		fprintf(output, "P3\n");
		fprintf(output, "%d %d\n", nx, ny);
		fprintf(output, "255\n ");

		vec3 lower_left_corner(-2.0, -1.0, -1.0);
		vec3 horizontal(4.0, 0.0, 0.0);
		vec3 vertical(0.0, 2.0, 0.0);
		vec3 origin(0.0, 0.0, 0.0);

		hitable *list[2]; // pointer to an array of 2 hitable objs
		list[0] = new sphere(vec3(0, 0, -1), 0.5);
		list[1] = new sphere(vec3(0, -100.5, -1), 100);
		hitable *world = new hitable_list(list, 2); // points to the address of the first element in list or the the list itself
		camera cam;
		for(int j = ny-1; j >= 0; j--) {
			for(int i = 0; i < nx; i++) {
				vec3 col(0,0,0);
				for (int s=0; s<ns; s++) {
					float u = float(i + drand48()) / float(nx);
					float v = float(j + drand48()) / float(ny);
					// starting at the origin interpolate along u and v 
					ray r = cam.get_ray(u, v);
					vec3 p = r.point_at_parameter(2.0);
					col+= color(r, world);
				}
				col /= float(ns); // taking the average of all the samples
				int ri = int(255.99*col[0]);
				int bi = int(255.99*col[1]);
				int gi = int(255.99*col[2]);
				fprintf(output, "%d %d %d\n", ri, bi, gi);
			}
		}
}