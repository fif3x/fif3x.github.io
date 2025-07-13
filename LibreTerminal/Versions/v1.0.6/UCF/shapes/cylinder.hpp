#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"

namespace cylinder {
	void calcV() {
		float r = 0.0f;
		float h = 0.0f;
		float pi = 3.14159f;
		float volume = 0.0f;
		std::cout << "Enter the radius of the cylinder: ";
		std::cin >> r;
		std::cout << "Enter the height of the cylinder: ";
		std::cin >> h;
		volume = (pi * (r * r)) * h;
		std::cout << "The volume of the cylinder is: " << volume << std::endl;
		results.push_back(volume);
	}
}

#endif
