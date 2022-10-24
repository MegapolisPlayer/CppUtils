//CppUtils/BoolUtils - utility for booleans
//CppUtils/BoolUtils.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

namespace CppUtils {
	void Toggle(bool* aBool) {
		if(*aBool == true) { *aBool = false; }
		else { *aBool = true; }
	}
	enum struct BoolToTextMode {
		LOWERCASE = 0, //all lowercase
		FLCAPITAL,	   //first letter capital
		CAPITAL		   //all capital
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
}
