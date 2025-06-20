// Free and Open Source Software (FOSS) made by @fif3x
// Simple terminal, ideal for development and testing purposes.
// This code is licensed under the GNU General Public License v3.0 (GPL-3.0).
// Telegram: https://t.me/fif3x
// Discord: @fifex_
// Feel free to contribute, report issues, suggest improvements or copy code
// Shoutout to @hlelo for some pieces of code, his Github username is @hlelo101, you should check it out
// Shoutout to TCD (The Coding Den) for the help they have given to multiple people, including me



#include <cstring>
#include <string>
#include <windows.h>
#include <cstdlib>  // include many libraries
#include <iostream>
#include <fstream>
#include <vector>

#include "preferences.h" 
#include "os.h"

class helpers { //class with helper functions
public:
	preferences prefs;

	const char* input;

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
		system("cls"); // clear the screen
	}
};

int cmpstr(const char* s1, const char* s2) { // Code by @hlelo translated into C++
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
} // code by @hlelo ends here

int main() {
	 
	OS os; // instances
	preferences prefs; // instantces
	helpers h; // instances

	os.get(); // get the OS type

	std::vector<std::string> twLines = {};

	while (true) {
        
		if (os.win) {
			std::cout << "WIN$> ";
		}
		else if (os.lin) {
			std::cout << "LIN$> ";
		}
		else if (os.mac) {
			std::cout << "MAC$> ";
		}
		else {
			if (prefs.unsupportedOSallow) {
				std::cout << "UKWN$> ";
			}
			else {
				std::cout << "ERROR: Unsupported OS, if you wish to continue using the program, please change unsupportedOSallow in preferences.h" << std::endl;

				break;
			}
		}

		std::string input; // input
		std::string cmd; // variable
		std::string arg1; // placeholder 1
		std::string arg2; // placeholder 2


		std::string compileCmd; // command to run
		std::string winCmd; // command to run

		std::string IP; // argument
		std::string color; // argument
		std::string file; // argument
		std::string* f = &file; // pointer to file
		std::string name; // argument
		std::string text; // text for tw

		std::getline(std::cin, input);
		h.input = input.c_str();

		auto it = std::find(input.begin(), input.end(), ' ');
		if (it != input.end()) {
			cmd = std::string(input.begin(), it);
			arg1 = std::string(it + 1, input.end());
			arg2 = std::string(it + 2, input.end());
		}
		else {
			cmd = input;
			arg1 = "";
			arg2 = "";
		}

		if (cmd == "exit" || cmd == "Exit") {
			exit(0);
		}
		else if (cmd == "cls" || cmd == "clear" || cmd == "clearScreen") {
			system("cls");
		}
		else if (cmd == "parrot") {
			system("curl parrot.live");
		}
		else if (cmd == "help" || cmd == "Help") {
			std::cout << "-------------------------------COMMANDS---------------------------------" << std::endl;
			std::cout << "1. show ip - shows IP (ipconfig)" << std::endl;
			std::cout << "2. exit - Exit program" << std::endl;
			std::cout << "3. cls/clear/clearScreen - Clear the screen" << std::endl;
			std::cout << "4. parrot - Show a parrot" << std::endl;
			std::cout << "5. ping <IP> - Ping an IP address" << std::endl;
			std::cout << "6. show IP - Show IP configuration (ipconfig)" << std::endl;
			std::cout << "7. stats/netstat/scanPorts/scan_ports - Show network statistics" << std::endl;
			std::cout << "8. tracert/traceroute <IP> - Trace route to an IP address" << std::endl;
			std::cout << "9. info/systemInfo/systeminfo - Show system information" << std::endl;
			std::cout << "10. color <color> - Change terminal color" << std::endl;
			std::cout << "11. run/open <file> - Run a file with a specific path" << std::endl;     
			std::cout << "12. compileCPP/compileC++ <file> - Compile a C++ file with a specific path" << std::endl;
			std::cout << "13. name/hostname - Show hostname" << std::endl;
			std::cout << "14. listFiles/lf - List files in the current directory" << std::endl;
			std::cout << "15. tree/fileTree/ft - Show a tree of all files" << std::endl;
			std::cout << "16. removeFile/removefile/rf - Remove a file" << std::endl;
			std::cout << "17. tWrite/twrite/tw - Write into the terminal (code by @hlelo)" << std::endl;
			std::cout << "-------------------------------------------------------------------------" << std::endl;

		}
		else if (cmd.empty()) {
			
		}
		else if (cmd == "ping") {
			IP = arg1;
			winCmd = cmd + " " + IP;
			h.logCmd(winCmd);
			h.exeCmd(winCmd);
		}
		else if (cmd == "show IP" || cmd == "showip" || cmd == "showIP" || cmd == "show_ip" || cmd == "show_IP") {
			h.logCmd("ipconfig");
			h.exeCmd("ipconfig");
		}
		else if (cmd == "stats" || cmd == "netstat" || cmd == "scanPorts" || cmd == "scan_ports") {
			h.logCmd("netstat");
			h.exeCmd("netstat");
		}
		else if (cmd == "tracert" || cmd == "traceroute") {
			IP = arg1;
			winCmd = cmd + " " + IP + " 4";
			h.logCmd(winCmd);
			h.exeCmd(winCmd);
		}
		else if (cmd == "info" || cmd == "systemInfo" || cmd == "systeminfo") {
			h.logCmd("systeminfo");
			h.exeCmd("systeminfo");
		}
		else if (cmd == "color") {
			color = arg1;
			winCmd = cmd + " " + color;
			h.logCmd(winCmd);
			h.exeCmd(winCmd);
		}
		else if (cmd == "run" || cmd == "open") {
			*f = arg1;
			h.logCmd("Run file: " + *f);
			h.exeCmd(*f);
		}
		else if (cmd == "compileCPP" || cmd == "compileC++") { //COMPILATION COMMAND IS WITH G++/MINGW
			*f = arg1;
			name = arg2;
			compileCmd = "g++ " + *f + " -o " + name;
			h.logCmd(compileCmd);
			h.exeCmd(compileCmd);
		}
		else if (cmd == "name" || cmd == "hostname") {
			h.logCmd("hostname");
			h.exeCmd("hostname");
		}
		else if (cmd == "listFiles" || cmd == "lf") {
			h.logCmd("dir");
			h.exeCmd("dir");
		}
		else if (cmd == "tree" || cmd == "fileTree" || cmd == "ft") {
			h.logCmd("tree");
			h.exeCmd("tree");
		}
		else if (cmd == "removeFile" || cmd == "removefile" || cmd == "rf") {
			*f = arg1;
			winCmd = "rmdir " + *f;
			if (prefs.safeMode){
				std::cout << "ERROR: Safe mode is enabled, if you wish to disable it, please change its state in the preferences.h file" << std::endl;
			}
			else {
				h.logCmd(winCmd);
				h.exeCmd(winCmd);
				
			}
		}
		else if (cmd == "tWrite" || cmd == "twrite" || cmd == "tw") {
			char twinput[80]; //code by hlelo 
			std::string twinput__SPECIAL__;

			std::cout << "INPUT 'twexit' TO EXIT" << std::endl;
			while (1) {
				std::cout << "> ";
				std::cin.getline(twinput, sizeof(twinput)); //code by hlelo ends


				auto it__TW__ = std::find(twinput__SPECIAL__.begin(), twinput__SPECIAL__.end(), ' ');
				if (it__TW__ != twinput__SPECIAL__.end()) {
					cmd = std::string(twinput__SPECIAL__.begin(), it__TW__);
					arg1 = std::string(it__TW__ + 1, twinput__SPECIAL__.end());
					arg2 = std::string(it__TW__ + 2, twinput__SPECIAL__.end());
				}
				else {
					cmd = twinput__SPECIAL__;
					arg1 = "";
					arg2 = "";
				}

				if (cmpstr(twinput, "tw:exit") == 0) break; // line of code by @hlelo
				else {
					twLines.push_back(twinput);
				}
				if (cmpstr(twinput, "tw:save") == 0) {

					if (twLines.at(0) == "#include <iostream>") {
						std::ofstream saveFile("NEW_TRWITE__LT__C++.cpp");

						for (int i = 0; i <= twLines.size(); i++) {
							if (twLines.at(i) != "tw:save") {
								saveFile << twLines.at(i) << std::endl;
							}
						}

						saveFile.close();
					}
					else {
						std::ofstream saveFile("NEW_TRWITE__LT__DOC.txt");

						for (int i = 0; i <= twLines.size(); i++) {
							if (twLines.at(i) != "tw:save") {
								saveFile << twLines.at(i) << std::endl;
							}
						}

						saveFile.close();
					}


					
				}
				if (cmd == "tw:saveas") {
					std::ofstream file(arg1);

					for (int i = 0; i <= twLines.size(); i++) {
						if (twLines.at(i) != "tw:saveas") {
							file << twLines.at(i) << std::endl;
						}
					}
				}
				if (cmd == "tw:openFile") {
					std::ifstream fileToOpen(arg1);

					while (std::getline(fileToOpen, text)) {
						std::cout << text << std::endl;
					}
				}
			} 
		}
		else {
			std::cout << "Unknown command: " << cmd << std::endl;
			std::cout << "Type 'help' for a list of commands." << std::endl;
		}

		if (prefs.resetScreenWhenEnter) {
			h.exeCmd("cls");
		}


	}


	std::cin.get();

	return 0;


}