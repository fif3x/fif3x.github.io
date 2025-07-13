#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"

namespace triangle {


	void calcArea() {
		float base = 0.0f;
		float height = 0.0f;
		float area = 0.0f;
		std::cout << "Enter the base of the triangle: ";
		std::cin >> base;
		std::cout << "Enter the height of the triangle: ";
		std::cin >> height;
		area = (base * height) / 2.0f;
		std::cout << "The area of the triangle is: " << area << std::endl;
		results.push_back(area);
	}
}

#endif
