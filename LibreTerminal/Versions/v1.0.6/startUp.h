#pragma once

#include <string>

#include "os.h"
#include "preferences.h"

class _STARTUP_ {
public:

	preferences prefs; // preferences instance

	void _initTerminal_() {
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