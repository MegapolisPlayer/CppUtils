//CppUtils/Integer - integer utilities (min, max)
//CppUtils/Integer.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

namespace CppUtils {
    bool IsBetween(const uint64_t aValue, const uint64_t aLower, const uint64_t aHigher) {
		return aValue >= aLower && aValue <= aHigher;
    }
    //for other utilities
    #define CPP_UTILS_MINMAX 1
	uint64_t Min(const uint64_t aNum1, const uint64_t aNum2) {
		if(aNum1 < aNum2) { return aNum1; }
		else { return aNum2; }
	}
	uint64_t Max(const uint64_t aNum1, const uint64_t aNum2) {
		if(aNum1 > aNum2) { return aNum1; }
		else { return aNum2; }
  }
}
