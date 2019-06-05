// RaytracingInAWeekend.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "vec3.h"
#include <fstream>

int main()
{
	int nx = 200;
	int ny = 100;

	std::ofstream file;
	file.open("image.ppm");

	//std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	file << "P3\n" << nx << " " << ny << "\n255\n";

	for (int i = ny; i > 0; i--) {
		for (int j = 0; j < nx; j++)
		{
			vec3 col(float(i) / float(ny), float(j) / float(nx), 0.2);

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
