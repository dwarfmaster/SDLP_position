#include "tools.hpp"

namespace sdl
{
	SDL_Rect makeRect(int x, int y, int w, int h)
	{
		SDL_Rect rect;
		rect.x=x;
		rect.y=y;
		rect.w=w;
		rect.h=h;

		return rect;
	}
};

	template<typename T>
std::ostream& operator<<(std::ostream& oss, const sdl::Point<T>& p)
{
	oss << "(";

	std::ostringstream* os = new std::ostringstream;
	*os << p.x;
	oss << os->str();

	oss << ";";
	delete os;
	os = new std::ostringstream;

	*os << p.y;
	oss << os->str();

	oss << ")";
	return oss;
}

std::ostream& operator<<(std::ostream& oss, const sdl::Vector2f& v)
{
	oss << ">(";

	std::ostringstream* os = new std::ostringstream;
	*os << v.x;
	oss << os->str();

	oss << ";";
	delete os;
	os = new std::ostringstream;

	*os << v.y;
	oss << os->str();

	oss << ")>";
	return oss;
}

std::ostream& operator<<(std::ostream& oss, const SDL_Rect& r)
{
	oss << sdl::Point<signed int>(r);
	return oss;
}

