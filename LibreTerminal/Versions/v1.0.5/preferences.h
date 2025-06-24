#pragma once

class preferences {
public:
	bool resetScreenWhenEnter = false;
	bool safeMode = false;
	bool debugMode = true;
	bool unsupportedOSallow = false;
	bool showMemoryUsage = false;
	bool alwaysWindows = false;
	bool alwaysLinux = false;
	bool alwaysMac = false;

	void resetToDefault() {
		resetScreenWhenEnter = false;
		safeMode = false;
		debugMode = false;
		unsupportedOSallow = false;
		showMemoryUsage = false;
		alwaysWindows = false;
		alwaysLinux = false;
		alwaysMac = false;
	}
};