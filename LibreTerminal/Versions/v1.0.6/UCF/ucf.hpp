#include <iostream>
#include <vector>

#include "preferences.h"

#include "shapes/pyramid.hpp"
#include "shapes/cone.hpp"
#include "shapes/sphere.hpp"
#include "shapes/triangle.hpp"
#include "shapes/circle.hpp"
#include "shapes/cube.hpp"
#include "shapes/cylinder.hpp"

#include "calchelpers.h"

#include "results.hpp"

void ucf() {

	pref prefs;

	while (!shouldClose) {
		std::cout << "> ";
		std::cin >> op;
		if (op == "exit") {
			shouldClose = true;
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else if (op == "+") {
			std::cout << "Number #1: "; std::cin >> a;
			std::cout << "Number #2: "; std::cin >> b;
			std::cout << "Result: " << a + b << std::endl;
			results.push_back(a + b);
		}
		else if (op == "-") {
			std::cout << "Number #1: "; std::cin >> a;
			std::cout << "Number #2: "; std::cin >> b;
			std::cout << "Result: " << a - b << std::endl;
			results.push_back(a - b);
		}
		else if (op == "*") {
			std::cout << "Number #1: "; std::cin >> a;
			std::cout << "Number #2: "; std::cin >> b;
			std::cout << "Result: " << a * b << std::endl;
			results.push_back(a * b);
		}
		else if (op == "/") {
			std::cout << "Number #1: "; std::cin >> a;
			std::cout << "Number #2: "; std::cin >> b;
			std::cout << "Result: " << a / b << std::endl;
			results.push_back(a / b);
		}
		else if (op == "^") {
			std::cout << "Number #1: "; std::cin >> a;
			std::cout << "Number #2: "; std::cin >> b;
			std::cout << "Result: " << pwr(a, b) << std::endl;
			results.push_back(pwr(a, b));
		}
		else if (op == "cone") {
			cone::calcV();
		}
		else if (op == "pyramid") {
			pyramid::calcV();
		}
		else if (op == "sphere") {
			sphere::calcV();
		}
		else if (op == "triangle") {
			triangle::calcArea();
		}
		else if (op == "circle") {
			circle::calcArea();
		}
		else if (op == "cube") {
			cube::calcV();
		}
		else if (op == "cylinder") {
			cylinder::calcV();
		}
		else if (op.empty()) {

		}
		else if (op == "res") {
			if (results.empty()) {
				std::cout << "No results yet." << std::endl;
			}
			else {
				std::cout << "Previous results: ";
				for (const auto& res : results) {
					std::cout << res << " ";
				}
				std::cout << std::endl;
			}
		}
		else if (op == "help"){
			std::cout << "Available commands: " << std::endl;
			std::cout << "+ : Addition" << std::endl;
			std::cout << "- : Subtraction" << std::endl;
			std::cout << "* : Multiplication" << std::endl;
			std::cout << "/ : Division" << std::endl;
			std::cout << "^ : Power" << std::endl;
			std::cout << "cone : Calculate volume of a cone" << std::endl;
			std::cout << "pyramid : Calculate volume of a pyramid" << std::endl;
			std::cout << "sphere : Calculate volume of a sphere" << std::endl;
			std::cout << "triangle : Calculate area of a triangle" << std::endl;
			std::cout << "circle : Calculate area of a circle" << std::endl;
			std::cout << "cube : Calculate volume of a cube" << std::endl;
			std::cout << "cylinder : Calculate volume of a cylinder" << std::endl;
			std::cout << "res : Show previous results" << std::endl;
			std::cout << "exit : Exit the calculator" << std::endl;
		}
		else {
			std::cout << "Incorect operator or shape" << std::endl;
		}
		std::cout << "[------------------------------]\n";
		std::cout << "\n";
		std::cout << "[------------------------------]\n";

	}
}