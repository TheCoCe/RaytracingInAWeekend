// RaytracingInAWeekend.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "ray.h"
#include "sphere.h"
#include "hitableList.h"
#include <fstream>
#include "float.h"

vec3 color(const ray& r, hitable *world) {
	hit_record rec;
	if (world->hit(r, 0.0f, FLT_MAX, rec)) {
		return 0.5f * vec3(rec.normal.x() + 1.f, rec.normal.y() + 1.f, rec.normal.z() + 1.f);
	}
	else {
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5f*(unit_direction.y() + 1.0f);
		return (1.0f - t) * vec3(1.f, 1.f, 1.f) + t * vec3(0.5f, 0.7f, 1.f);
	}
}

int main()
{
	int nx = 200;
	int ny = 100;

	std::ofstream file;
	file.open("image.ppm");

	//std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	file << "P3\n" << nx << " " << ny << "\n255\n";

	vec3 lower_left_corner(-2.f, -1.f, -1.f);
	vec3 horizontal(4.f, 0.f, 0.f);
	vec3 vertical(0.f, 2.f, 0.f);
	vec3 origin(0.f, 0.f, 0.f);

	hitable *list[2];
	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitableList *world = new hitableList(list, 2);

	for (int j = ny; j > 0; j--) {
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			
			vec3 p = r.point_at_parameter(2.0);
			vec3 col = color(r, world);
			// Convert color to 0 - 1
			int ir = int(255.99f*col.r());
			int ig = int(255.99f*col.g());
			int ib = int(255.99f*col.b());
			//std::cout << ir << " " << ig << " " << ib << "\n";
			file << ir << " " << ig << " " << ib << "\n";
		}
	}

	file.close();
}
