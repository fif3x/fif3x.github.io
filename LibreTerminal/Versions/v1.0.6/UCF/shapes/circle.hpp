#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include <vector>
#include "../results.hpp"

namespace circle {
	void calcArea() {
		float r = 0.0f;
		float pi = 3.14159f;
		float area = 0.0f;
		std::cout << "Enter the radius of the circle: ";
		std::cin >> r;
		area = pi * (r * r);
		std::cout << "The area of the circle is: " << area << std::endl;
		results.push_back(area);

	}
}

#endif