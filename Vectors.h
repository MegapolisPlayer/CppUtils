//CppUtils/Vectors - Vec2, Vec3 abd Vec4
//CppUtils/Vectors.h © 2022 by MegapolisPlayer is licensed under CC BY 4.0

namespace CppUtils {
  //xy, ab
	template<typename Type>
	struct Vec2 {
		union {
			Type x;
			Type a;
		};
		union {
			Type y;
			Type b;
		};
		
  	Vec2() : x{}, y{} {} //does somehow work, thanks c++
		Vec2(Type ax, Type ay) : x(ax), y(ay) {}
	};
	//xyz, abc, RGB
	template<typename Type>
	struct Vec3 {
		union {
			Type x;
			Type a;
			Type R;
		};
		union {
			Type y;
			Type b;
			Type G;
		};
		union {
			Type z;
			Type c;
			Type B;
		};
		
  	Vec3() : x{}, y{}, z{} {}
  	Vec3(Type ax, Type ay, Type az) : x(ax), y(ay), z(az) {}
	};
	//xyzw, abcd, RGBA
	template<typename Type>
	struct Vec4 {
		union {
			Type x;
			Type a;
			Type R;
		};
		union {
			Type y;
			Type b;
			Type G;
		};
		union {
			Type z;
			Type c;
			Type B;
		};
		union {
			Type w;
			Type d;
			Type A;
		};
		
  	Vec4() : x{}, y{}, z{}, w{} {}
  	Vec4(Type ax, Type ay, Type az, Type aw) : x(ax), y(ay), z(az), w(aw) {}
	};
}
