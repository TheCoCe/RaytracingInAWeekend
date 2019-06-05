// RaytracingInAWeekend.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "ray.h"
#include <fstream>

vec3 color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5*(unit_direction.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main()
{
	int nx = 200;
	int ny = 100;

	std::ofstream file;
	file.open("image.ppm");

	//std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	file << "P3\n" << nx << " " << ny << "\n255\n";

	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);

	for (int j = ny; j > 0; j--) {
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			vec3 col = color(r);

			// Convert color to 0 - 1
			int ir = int(255.99*col.r());
			int ig = int(255.99*col.g());
			int ib = int(255.99*col.b());
			//std::cout << ir << " " << ig << " " << ib << "\n";
			file << ir << " " << ig << " " << ib << "\n";
		}
	}

	file.close();
}
