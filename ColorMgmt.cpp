//CppUtils/ColorMgmt - cross-platofrm utility for terminal color
//CppUtils/ColorMgmt.cpp © 2022 by MegapolisPlayer is licensed under CC BY 4.0 

namespace CppUtils {
#ifdef _WIN32
	enum Color {
		COLOR_BLACK = 0,
		COLOR_BLUE,
		COLOR_GREEN,
		COLOR_CYAN,
		COLOR_RED,
		COLOR_PURPLE,
		COLOR_BROWN,
		COLOR_LIGHT_GREY,
		COLOR_GREY,
		COLOR_LIGHT_BLUE,
		COLOR_LIGHT_GREEN,
		COLOR_LIGHT_CYAN,
		COLOR_LIGHT_RED,
		COLOR_PINK,
		COLOR_YELLOW,
		COLOR_WHITE,
		COLOR_DEFAULT
	};
#endif
#ifdef __linux
	enum Color {
		COLOR_BLACK = 0,
		COLOR_RED,
		COLOR_GREEN,
		COLOR_BROWN,
		COLOR_BLUE,
		COLOR_PURPLE,
		COLOR_CYAN,
		COLOR_LIGHT_GREY,
		COLOR_DARK_GREY = 8,
		COLOR_LIGHT_RED,
		COLOR_LIGHT_GREEN,
		COLOR_YELLOW,
		COLOR_LIGHT_BLUE,
		COLOR_PINK,
		COLOR_LIGHT_CYAN,
		COLOR_WHITE,
		COLOR_DEFAULT = 39
	};
#endif
	void SetColor(const Color aForeground, const Color aBackground = COLOR_DEFAULT) {
#ifdef WIN32
		HANDLE lHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if(aForeground == COLOR_DEFAULT) { SetConsoleTextAttribute(lHandle, 7); }
		else { SetConsoleTextAttribute(lHandle, (aBackground * 16) + aForeground); }
#endif
#ifdef __linux
		std::string lTemp;
		lTemp.append("\x1b[0;");
		if(aForeground == COLOR_DEFAULT) { lTemp.append("39"); }
		else if(aForeground <= 8) { lTemp.append(std::to_string(aForeground + 30)); }
		else { lTemp.append(std::to_string(aForeground + 82)); }
		lTemp += ';';
		if(aBackground == COLOR_DEFAULT) { lTemp.append("49"); }
		else if(aBackground <= 8) { lTemp.append(std::to_string(aBackground + 40)); }
		else { lTemp.append(std::to_string(aBackground + 92)); }
		lTemp += 'm';
		std::cout << lTemp;
#endif
	}
	void ResetColor() {
#ifdef WIN32
		HANDLE lHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(lHandle, 7);
#endif
#ifdef __linux
		std::cout << "\x1b[0;39;49m";
#endif
	}
	class ScopedColor {
	public:
		ScopedColor(const Color& aForeground, const Color& aBackground = COLOR_DEFAULT) { SetColor(aForeground, aBackground); }
		~ScopedColor() { ResetColor(); }
	};
}
