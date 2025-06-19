#pragma once

class OS {
public:
	bool win = false;
	bool lin = false;
	bool mac = false;

	void get() {
	#if defined(_WIN32) || defined(_WIN64)
		win = true;
	}
	#elif defined(__linux__)
		lin = true;
	#elif defined(__APPLE__) || defined(__MACH__)
		mac = true;
	#else
		std::cout << "ERROR: Unsupported OS" << std::endl;
	#endif
};