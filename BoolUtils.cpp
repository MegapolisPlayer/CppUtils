//CppUtils/BoolUtils - utility for booleans
//CppUtils/BoolUtils.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

namespace CppUtils {
#ifndef CPP_UTILS_STRING
	uint64_t StringLength(const char* const aString) {
		uint64_t lId = 0;
		while(aString[lId] != '\0') { lId++; }
		return lId;
	}
#endif
	void Toggle(bool* aBool) {
		if(*aBool == true) { *aBool = false; }
		else { *aBool = true; }
	}
	enum struct BoolToTextMode {
		LOWERCASE = 0, //all lowercase
		FLCAPITAL, //first letter capital
		CAPITAL	//all capital
	};
	const char* BoolToText(bool aBool, BoolToTextMode aMode = BoolToTextMode::FLCAPITAL) {
		if(aBool) {
			switch(aMode) {
				case(BoolToTextMode::LOWERCASE): return "true";
				case(BoolToTextMode::FLCAPITAL): return "True";
				case(BoolToTextMode::CAPITAL):	 return "TRUE";
			}
		}
		else {
			switch(aMode) {
				case(BoolToTextMode::LOWERCASE): return "false";
				case(BoolToTextMode::FLCAPITAL): return "False";
				case(BoolToTextMode::CAPITAL):	 return "FALSE";
			}
		}
	}
	//returns -1 if fails, otherwise 0 or 1
	int8_t TextToBool(const char* aString) {
		uint64_t lStringLength = StringLength(aString);
		if(lStringLength < 4 || lStringLength > 5) { return -1; }
		//checks for true
		if(aString[0] == 't' || aString[0] == 'T') {
			if(aString[1] != 'r' && aString[1] != 'R') { return -1; }
			if(aString[2] != 'u' && aString[2] != 'U') { return -1; }
			if(aString[3] != 'e' && aString[3] != 'E') { return -1; }
			return true;
		}
		//checks for false
		if(aString[0] == 'f' || aString[0] == 'F') {
			if(aString[1] != 'a' && aString[1] != 'A') { return -1; }
			if(aString[2] != 'l' && aString[2] != 'L') { return -1; }
			if(aString[3] != 's' && aString[3] != 'S') { return -1; }
			if(aString[4] != 'e' && aString[4] != 'E') { return -1; }
			return false;
		}
		return -1;
	}
}
