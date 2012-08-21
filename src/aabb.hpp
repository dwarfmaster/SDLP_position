
/*
 * Copyright (C) 2012 Chabassier Luc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*!
 * \file aabb.hpp
 * \brief définit la classe AABB.
 */

#ifndef DEF_SDLP_AABB
#define DEF_SDLP_AABB

#include <SDL/SDL.h>
#include <vector>

#include "point_dec.hpp"
#include "tools.hpp"

namespace sdl
{
	class AABB
	{
		public:
			enum Location{
				TOP_RIGHT, /*!< Le coin en haut à droite. */
				TOP,  /*!< Le point en haut au milieu. */
				TOP_LEFT, /*!< Le coin en haut à gauche. */
				BOTTOM_RIGHT, /*!< Le coin en bas à droite. */
				BOTTOM, /*!< Le point en bas au milieu. */
				BOTTOM_LEFT, /*!< Le coin en bas à gauche. */
				LEFT, /*!< Le point à gauche au milieu. */
				RIGHT /*!< Le point à droite au milieu. */
			};

			AABB();
			AABB(const SDL_Rect& cp);
			AABB(const AABB& cp);
			AABB(const Pointsi& p1, const Pointsi& p2);

			AABB& set(const SDL_Rect& cp);
			AABB& set(const AABB& cp);
			AABB& set(const Pointsi& p1, const Pointsi& p2);
			AABB& englobe(const std::vector<AABB>& aabbs, bool strict=false);
			AABB& englobe(const std::vector<Pointsi>& points, bool strict=false);
			AABB& clear();

			void move(const Pointsi& ori); // Déplace l'aabb à cette position
			void resize(const SDL_Rect& nsize); // N'utilise que w et h
			bool resize(const Pointsi& second); // Va changer la valeur de façon à ce que l'aabb aille du point enregistré au point donné en paramètre (ce derniers doit être plus en bas à droite du premier)

			SDL_Rect rect() const;
			Pointsi location(Location p) const;
			unsigned int area() const; // Aire
			unsigned int perimeter() const; // Périmètre

			bool colision(const AABB& other) const;
			bool contain(const Pointsi& p) const;

			AABB& operator=(const AABB& cp);
			SDL_Rect& operator*();
			const SDL_Rect& operator*() const;
			SDL_Rect* operator->();
			const SDL_Rect* operator->() const;
			Pointsi operator[](Location p) const;

		private:
			SDL_Rect m_aabb; /*!< Contient la aabb. */
	};
};

#endif//DEF_SDLP_AABB
