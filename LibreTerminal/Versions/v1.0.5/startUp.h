#pragma once

#include <string>

#include "os.h"
#include "preferences.h"

class __STARTUP__ {
public:

	preferences prefs; // preferences instance

	void __initTerminal__() {
		if (prefs.debugMode) { 
			std::cout << "Initializing terminal..." << std::endl; 
		}
		OS os;
		os.get();
		if (prefs.debugMode) { 
			std::cout << "Initialization complete!" << std::endl; 
		}
	}
    void _STARTUP_() {
		__initTerminal__();
	}
};