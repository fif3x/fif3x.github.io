#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "preferences.h"

class helpers { //class with helper functions
public:
	preferences prefs;

	std::vector<std::string> cmdRan;

	void exeCmd(std::string arg) { //execute a commnad
		system(arg.c_str());
	}
	void logCmd(std::string arg) { // log a command
		cmdRan.push_back(arg); // add command to vector
		if (prefs.debugMode) { // if debug mode is enabled, print the command
			std::cout << "Executing command: " << arg << std::endl;
		}
	}
	void cls() {
		std::string clearScreen = "cls";
		system(clearScreen.c_str()); // clear the screen
	}
	void error() {
		std::cout << "ERROR: Unsupported OS, if you wish to continue using the program, please change unsupportedOSallow in preferences.h" << std::endl;
	}
};