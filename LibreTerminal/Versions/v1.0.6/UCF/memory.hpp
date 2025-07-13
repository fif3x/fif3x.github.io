#ifndef MEM_HPP
#define MEM_HPP


#include <iostream>

#include "shapes/cone.hpp"
#include "shapes/sphere.hpp"
#include "shapes/pyramid.hpp"
#include "shapes/triangle.hpp"
#include "preferences.h"
#include "calchelpers.h"

pref prefs;
uint16_t mem = sizeof(prefs) + sizeof(prefs.showMem) + sizeof(shouldClose) + sizeof(op) + sizeof(mem) + sizeof(a) + sizeof(b);

void showMem() {
	std::cout << "                                                                                              Memory Usage: " << mem << " Bytes" << std::endl;
}

#endif
