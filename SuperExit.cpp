//CppUtils/SuperExit - exit() function abstractions and format
//CppUtils/SuperExit.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

namespace CppUtils {
	[[noreturn]] void PauseExit(int aCode = EXIT_SUCCESS) {
		std::cout << "Press any key and enter to exit.\n";
		char lBuffer;
		std::cin >> lBuffer;
		exit(aCode);
	}
	[[noreturn]] void ErrorExit(const std::string& aMessage) {
		std::cout << "[ERROR]: " << aMessage << '\n';
		PauseExit(EXIT_FAILURE);
	}
}
