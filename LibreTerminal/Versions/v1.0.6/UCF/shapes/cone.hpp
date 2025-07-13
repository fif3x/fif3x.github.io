#ifndef CONE_HPP
#define CONE_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"

namespace cone {

	void calcV() {

		float r = 0.0f;
		float Y = 0.0f;
		float rSq = 0.0f;
		float V = 0.0f;
		const float pi = 3.14159265f;

		std::cout << "Enter the radius of base of the cone: ";
		std::cin >> r;
		std::cout << "Enter the height of the cone: ";
		std::cin >> Y;

		rSq = r * r;

		V = (pi * rSq * Y) / 3.0f;

		std::cout << "The volume of the cone is: " << V << std::endl;
		results.push_back(V);

	}
}

#endif