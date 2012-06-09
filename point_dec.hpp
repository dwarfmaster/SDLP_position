#ifndef DEF_SDLP_POINT
#define DEF_SDLP_POINT

#include <SDL/SDL.h>
#include "vector2f.hpp"

namespace sdl
{
	template<typename Type>
		class Point
		{
			public:
				Type x;
				Type y;

				Point();
				Point(Type mx, Type my);
				explicit Point(Type all);
				Point(const SDL_Rect& cp);
				Point(const Point& cp);
				template<typename Cpt>
					Point(const Point<Cpt>& cp);
				~Point();

				Point& set(Type mx, Type my);
				Point& set(Type all);
				Point& set(const Point& cp);
				template<typename Cpt>
					Point& set(const Point<Cpt>& cp);
				Point& clear();

				Point& operator=(const Point& cp);
				template<typename Cpt>
					Point& operator=(const Point<Cpt>& cp);
				operator SDL_Rect() const;
				operator SDL_Rect*() const;

				Point& translate(const Vector2f& v);

				Point operator+(const Vector2f& v) const;
				Point& operator+=(const Vector2f& v);

				Point operator-(const Vector2f& v) const;
				Point& operator-=(const Vector2f& v);

			private:
				mutable SDL_Rect* m_pointer;
		};

	typedef Point<signed int> Pointsi;
	typedef Point<unsigned int> Pointui;
	typedef Point<signed long> Pointsl;
	typedef Point<unsigned long> Pointul;
	typedef Point<float> Pointf;
};

#include "point_def.hpp"

#endif//DEF_SDLP_POINT
