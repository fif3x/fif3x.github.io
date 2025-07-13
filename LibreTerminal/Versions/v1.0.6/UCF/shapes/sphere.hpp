#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"

namespace sphere {

	void calcV() {
		float r = 0.0f;
		float rCubed = 0.0f;
		float V = 0.0f;
		float pi = 3.14159265f;
		std::cout << "Enter the radius of the sphere: ";
		std::cin >> r;
		rCubed = r * r * r;
		V = (4.0f / 3.0f) * pi * rCubed;
		std::cout << "The volume of the sphere is: " << V << std::endl;
		results.push_back(V);
	}
}

#endif