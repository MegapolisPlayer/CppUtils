//CppUtils/StringUtils - utilities for strings
//CppUtils/StringUtils.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

#define CPP_UTILS_STRING

namespace CppUtils {
	uint64_t StringLength(const char* const aString) {
		uint64_t lId = 0;
		while (aString[lId] != '\0') { lId++; }
		return lId;
	}
	
	bool IsNumber(char aChar) {
		if((aChar < 48) || (aChar > 57)) { return false; }
		return true;
	}
	bool IsNumber(const char* aString) {
		for(uint64_t lId = 0; lId < StringLength(aString); lId++) {
			if((aString[lId] < 48) || (aString[lId] > 57)) { return false; }
		}
		return true;
	}
	
	bool Contains(const char* aString, const char aChar) {
		for(uint64_t lId = 0; lId < StringLength(aString); lId++) {
			if(aString[lId] == aChar) { return true; }
		}
		return false;
	}
	bool ContainsMultiple(const char* aString, const char* aChars, const uint64_t aCharsAmount) {
		for(uint64_t lId = 0; lId < StringLength(aString); lId++) {
			for(uint64_t lId2 = 0; lId2 < aCharsAmount; lId2++) {
				if(aString[lId] == aChars[lId2]) { return true; }
			}
		}
		return false;
	}
	bool IsOneOf(const char aChar, const char* aChars, const uint64_t aCharsAmount) {
		for(uint64_t lId = 0; lId < aCharsAmount; lId++) {
			if(aChar == aChars[lId]) { return true; }
		}
		return false;
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
	
	uint64_t AmountOccurences(const char* aString, const char aChar) {
		uint64_t lCount = 0;
		for(uint64_t lId = 0; lId < StringLength(aString); lId++) {
			if(aString[lId] == aChar) { lCount++; }
		}
		return lCount;
	}
}