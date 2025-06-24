#pragma once

#include <iostream>

#include "preferences.h"

enum class OStype {
	Win,
	Mac,
	Linux,
	UKWN
};

class OS {
public:
	preferences prefs;

	OStype os_type = OStype::UKWN;

	void get() {
		if (prefs.debugMode) { 
			std::cout << "Detecting OS..." << std::endl;
		}

		if (prefs.alwaysWindows) {
			os_type = OStype::Win;
			if (prefs.debugMode) {
				std::cout << "OS forced to Windows!" << std::endl;
			}
		}
		else if (prefs.alwaysLinux) {
			os_type = OStype::Linux;
			if (prefs.debugMode) {
				std::cout << "OS forced to Linux!" << std::endl;
			}
		}
		else if (prefs.alwaysMac) {
			os_type = OStype::Mac;
			if (prefs.debugMode) {
				std::cout << "OS forced to Apple/Mac!" << std::endl;
			}
		}
		else {

			#if defined(_WIN32) || defined(_WIN64)
			os_type = OStype::Win;
			#elif defined(__linux__)
			os_type = OStype::Linux;
			#elif defined(__APPLE__) || defined(__MACH__)
			os_type = OStype::Mac;
			#else
			std::cout << "ERROR: Unsupported OS" << std::endl;
			os_type = OStype::UKWN;
			#endif

			if (prefs.debugMode) {
				std::cout << "OS detected!" << std::endl;
			}
		}
	}
};