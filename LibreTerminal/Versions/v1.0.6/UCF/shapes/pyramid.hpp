#ifndef PYRAMID_HPP
#define PYRAMID_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"


namespace pyramid {

	void calcV() {

		float sideX = 0.0f;
		float sideY = 0.0f;
		float sideZ = 0.0f;
		float base = 0.0f;
		float V = 0.0f;

		std::cout << "Enter the side #1 of the base of the pyramid: ";
		std::cin >> sideX;
		std::cout << "Enter the side #2 of the base of the pyramid: ";
		std::cin >> sideZ;
		std::cout << "Enter the height of the pyramid: ";
		std::cin >> sideY;

		base = sideX * sideZ;
		V = (base * sideY) / 3.0f;

		std::cout << "The volume of the pyramid is: " << V << std::endl;
		results.push_back(V);
	}
}

#endif
