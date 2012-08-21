
/*!
 * \file tools.hpp
 * \brief Définit certains outils sur les points et les aabbs. Implémente les fonctions template.
 */

#ifndef DEF_SDLP_POS_TOOLS
#define DEF_SDLP_POS_TOOLS

#include <SDL/SDL.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "point_dec.hpp"
#include "vector2f.hpp"

namespace sdl
{
	SDL_Rect makeRect(int x, int y, int w=0, int h=0);

	template<typename T>
		Point<T> middle(const Point<T>& p1, const Point<T>& p2)
		{
			T x = p1.x + p2.x;
			x /= 2;
			T y = p1.y + p2.y;
			y /= 2;

			return Point<T>(x, y);
		}

	template<typename T>
		unsigned int length(const Point<T>& p1, const Point<T>& p2)
		{
			unsigned int xcar = (p1.x-p2.x) * (p1.x-p2.x);
			unsigned int ycar = (p1.y-p2.y) * (p1.y-p2.y);

			return static_cast<unsigned int>(std::sqrt(xcar + ycar));
		}

	template<typename T>
		Point<T> min(const Point<T>& p1, const Point<T>& p2)
		{
			return Point<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
		}

	template<typename T>
		Point<T> max(const Point<T>& p1, const Point<T>& p2)
		{
			return Point<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
		}
};

#endif//DEF_SDLP_POS_TOOLS
