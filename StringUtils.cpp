//CppUtils/StringUtils - utilities for strings
//CppUtils/StringUtils.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

namespace CppUtils {
	uint64_t StringLength(const char* const aString) {
		uint64_t lId = 0;
		while (aString[lId] != '\0') { lId++; }
		return lId;
	}
	bool IsNumber(const char* aString) {
		for(uint64_t lId = 0; lId < StringLength(aString); lId++) {
			if((aString[lId] < 48) || (aString[lId] > 57)) { return false; }
		}
		return true;
	}	
	bool StringCompare(const char* const aString1, const char* const aString2) {
		uint64_t lString1Len = StringLength(aString1);
		uint64_t lString2Len = StringLength(aString2);
		if(lString1Len != lString2Len) { return false; } //string size not equal
		for(uint64_t lId = 0; lId < lString1Len; lId++) {
			if(aString1[lId] != aString2[lId]) { return false; }
		}
		return true;
	}
	bool IsStringInArray(const char** aArray, const uint64_t aArrayAmount, const char* aString) {
		for(uint64_t lId = 0; lId < aArrayAmount; lId++) {
			if(StringCompare(aArray[lId], aString)) { return true; }
		}
		return false;
	}
}
