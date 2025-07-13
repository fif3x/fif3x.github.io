#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"

namespace cube {
	void calcV() {
		float side = 0.0f;
		float volume = 0.0f;
		std::cout << "Enter the area of a side of the cube: ";
		std::cin >> side;
		volume = side * side * side;
		std::cout << "The volume of the cube is: " << volume << std::endl;
		results.push_back(volume);
	}
}

#endif