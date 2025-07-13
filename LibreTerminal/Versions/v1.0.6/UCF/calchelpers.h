#pragma once

#include <iostream>

#include "shapes/cone.hpp"
#include "shapes/pyramid.hpp"
#include "shapes/sphere.hpp"
#include "shapes/triangle.hpp"
#include "preferences.h"

bool shouldClose = false;

float a = 0.0f;
float b = 0.0f;

float pwr(float num1, float num2) {
	float result = 1.0f;
	for (int i = 0; i < num2; ++i) {
		result *= num1;
	}
	return result;
}

std::string op = { };