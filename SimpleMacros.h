//CppUtils/SimpleMacros - utility for C++ types and macros
//CppUtils/SimpleMacros.h © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

#ifndef elif
#define elif else if
#endif
#ifndef loopover
#define loopover continue
#endif
#ifndef incr
#define incr ++
#endif

namespace CppUtilsMacros {
	typedef int8_t   	S08;
	typedef int16_t  	S16;
	typedef int32_t  	S32;
	typedef int64_t  	S64;
	
	typedef uint8_t  	U08;
	typedef uint16_t 	U16;
	typedef uint32_t 	U32;
	typedef uint64_t 	U64;
	
	//All functions marked with ERRVAL should return 0 on success and 1 on failure.
	//Other return values are marked in a comment near the function declaration.
	typedef S08 ERRVAL;
	
	//All functions marked with ERRVAL should return 0 on success and 1 on failure.
	//Please be sure to check the return value from this function.
	#define CANERR [[nodiscard]] ERRVAL
	
	typedef const char* RawStr;
	typedef char* 		ModRawStr;
}

#ifdef MP_CPPUTILS_SIMPLIFY
using namespace CppUtilsMacros;
#endif

#ifdef MP_CPPUTILS_SIMPLIFY_STD
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;
#endif

#ifdef MP_CPPUTILS_SIMPLIFY_STD_FULL
using namespace std;
#endif
