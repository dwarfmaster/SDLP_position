
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
 * \file point_def.hpp
 * \brief Implémente la classe Point.
 */

#ifndef DEF_SDLP_DEF_POINT
#define DEF_SDLP_DEF_POINT

namespace sdl
{
	template<typename Type>
		Point<Type>::Point()
		: m_pointer(NULL)
		{
			this->clear();
		}

	template<typename Type>
		Point<Type>::Point(Type mx, Type my)
		: m_pointer(NULL)
		{
			this->set(mx, my);
		}

	template<typename Type>
		Point<Type>::Point(Type all)
		:m_pointer(NULL)
		{
			this->set(all);
		}

	template<typename Type>
		Point<Type>::Point(const SDL_Rect& cp)
		:m_pointer(NULL)
		{
			this->set(cp);
		}

	template<typename Type>
		Point<Type>::Point(const Point<Type>& cp)
		:m_pointer(NULL)
		{
			this->set(cp);
		}

	template<typename Type> template<typename Cpt>
		Point<Type>::Point(const Point<Cpt>& cp)
		{
			this->set<Cpt>(cp);
		}

	template<typename Type>
		Point<Type>& Point<Type>::set(Type mx, Type my)
		{
			x=mx;
			y=my;
			return *this;
		}

	template<typename Type>
		Point<Type>& Point<Type>::set(Type all)
		{
			x=y=all;
			return *this;
		}

	template<typename Type>
		Point<Type>& Point<Type>::set(const Point<Type>& cp)
		{
			x=cp.x;
			y=cp.y;
			return *this;
		}

	template<typename Type>
		Point<Type>& Point<Type>::set(const SDL_Rect& cp)
		{
			x=cp.x;
			y=cp.y;
			return *this;
		}

	template<typename Type> template<typename Cpt>
		Point<Type>& Point<Type>::set(const Point<Cpt>& cp)
		{
			x = static_cast<Type>(cp.x);
			y = static_cast<Type>(cp.y);
			return *this;
		}

	template<typename Type>
		Point<Type>& Point<Type>::clear()
		{
			if(m_pointer != NULL)
			{
				delete m_pointer;
				m_pointer = NULL;
			}

			x=y=0;
			return *this;
		}

	template<typename Type>
		Point<Type>& Point<Type>::operator=(const Point& cp)
		{
			return this->set(cp);
		}

	template<typename Type> template<typename Cpt>
		Point<Type>& Point<Type>::operator=(const Point<Cpt>& cp)
		{
			return this->set<Cpt>(cp);
		}

	template<typename Type>
		Point<Type>::~Point()
		{
			if(m_pointer != NULL)
				delete m_pointer;
		}

	template<typename Type>
		Point<Type>::operator SDL_Rect() const
		{
			SDL_Rect rect;
			rect.w=rect.h=0;
			rect.x = static_cast<signed int>(x);
			rect.y = static_cast<signed int>(y);

			return rect;
		}

	template<typename Type>
		Point<Type>::operator SDL_Rect*() const
		{
			if(m_pointer != NULL)
			{
				delete m_pointer;
				m_pointer = NULL;
			}

			m_pointer = new SDL_Rect(*this);
			return m_pointer;
		}

	template<typename Type>
		Point<Type>& Point<Type>::translate(const Vector2f& v)
		{
			x += static_cast<Type>(v.x);
			y += static_cast<Type>(v.y);
			return *this;
		}

	template<typename Type>
		Point<Type> Point<Type>::operator+(const Vector2f& v) const
		{
			Point p(*this);
			p.translate(v);
			return p;
		}

	template<typename Type>
		Point<Type>& Point<Type>::operator+=(const Vector2f& v)
		{
			this->translate(v);
			return *this;
		}

	template<typename Type>
		Point<Type> Point<Type>::operator-(const Vector2f& v) const
		{
			Point p(*this);
			p.translate(-v);
			return p;
		}

	template<typename Type>
		Point<Type>& Point<Type>::operator-=(const Vector2f& v)
		{
			this->translate(-v);
			return *this;
		}

};

#endif//DEF_SDLP_DEF_POINT
