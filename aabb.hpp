#ifndef DEF_SDLP_AABB
#define DEF_SDLP_AABB

#include <SDL/SDL.h>
#include <algorithm>

#include "point_dec.hpp"
#include "tools.hpp"

namespace sdl
{
	class AABB
	{
		public:
			enum Location{TOP_RIGHT, TOP_MIDDLE, TOP_LEFT, BOTTOM_RIGHT, BOTTOM_MIDDLE, BOTTOM_LEFT, LEFT, RIGHT};

			AABB();
			AABB(const SDL_Rect& cp);
			AABB(const AABB& cp);
			AABB(const Pointsi& p1, const Pointsi& p2);

			AABB& set(const SDL_Rect& cp);
			AABB& set(const AABB& cp);
			AABB& set(const Pointsi& p1, const Pointsi& p2);
			AABB& clear();

			void move(const Pointsi& ori); // Déplace l'aabb à cette position
			void resize(const SDL_Rect& nsize); // N'utilise que w et h
			bool resize(const Pointsi& second); // Va changer la valeur de façon à ce que l'aabb aille du point enregistré au point donné en paramètre (ce derniers doit être plus en bas à droite du premier)

			SDL_Rect rect() const;
			Pointsi location(Location p) const;
			unsigned int area() const; // Aire
			unsigned int perimeter() const; // Périmètre

			bool colision(const AABB& other) const;

			AABB& operator=(const AABB& cp);
			SDL_Rect& operator*();
			const SDL_Rect& operator*() const;
			SDL_Rect* operator->();
			const SDL_Rect* operator->() const;

		private:
			SDL_Rect m_aabb;
	};
};

#endif//DEF_SDLP_AABB
