#ifndef DEF_SDLP_TOOLS
#define DEF_SDLP_TOOLS

#include <SDL/SDL.h>
#include <iostream>
#include <sstream>

#include "point_dec.hpp"
#include "vector2f.hpp"

namespace sdl
{
	SDL_Rect makeRect(int x, int y, int w=0, int h=0);
};

template<typename T>
std::ostream& operator<<(std::ostream& oss, const sdl::Point<T>& p);
std::ostream& operator<<(std::ostream& oss, const sdl::Vector2f& v);
std::ostream& operator<<(std::ostream& oss, const SDL_Rect& r);

#endif//DEF_SDLP_TOOLS
