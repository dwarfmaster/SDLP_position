
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
 * \file vector2f.cpp
 * \brief Implémente la classe Vector2f
 */

#include "vector2f.hpp"

namespace sdl
{
	Vector2f::Vector2f()
	{
		this->clear();
	}

	Vector2f::Vector2f(float all)
	{
		this->set(all);
	}

	Vector2f::Vector2f(float mx, float my)
	{
		this->set(mx, my);
	}

	Vector2f::Vector2f(float x1, float y1, float x2, float y2)
	{
		this->set(x1, y1, x2, y2);
	}

	Vector2f::Vector2f(const SDL_Rect& cp)
	{
		this->set(cp);
	}

	Vector2f::Vector2f(const SDL_Rect& r1, const SDL_Rect& r2)
	{
		this->set(r1, r2);
	}

	Vector2f::Vector2f(const Vector2f& cp)
	{
		this->set(cp);
	}

	Vector2f& Vector2f::set(float all)
	{
		x=y=all;
		return *this;
	}

	Vector2f& Vector2f::set(float mx, float my)
	{
		x=mx;
		y=my;
		return *this;
	}

	Vector2f& Vector2f::set(float x1, float y1, float x2, float y2)
	{
		x=x2-x1;
		y=y2-y1;
		return *this;
	}

	Vector2f& Vector2f::set(const SDL_Rect& cp)
	{
		x=cp.x;
		y=cp.y;
		return *this;
	}

	Vector2f& Vector2f::set(const SDL_Rect& r1, const SDL_Rect& r2)
	{
		x=r2.x-r1.x;
		y=r2.y-r1.y;
		return *this;
	}

	Vector2f& Vector2f::set(const Vector2f& cp)
	{
		x=cp.x;
		y=cp.y;
		return *this;
	}

	Vector2f& Vector2f::clear()
	{
		x=y=0;
		return *this;
	}

	SDL_Rect Vector2f::posRect() const
	{
		SDL_Rect rect;
		rect.w=rect.h=0;
		rect.x=x;
		rect.y=y;
		return rect;
	}

	Vector2f::operator SDL_Rect() const
	{
		SDL_Rect rect;
		rect.x=rect.y=0;
		rect.w=x;
		rect.h=y;
		return rect;
	}

	Vector2f& Vector2f::operator=(float all)
	{
		return this->set(all);
	}

	Vector2f& Vector2f::operator=(const Vector2f& cp)
	{
		return this->set(cp);
	}

	float Vector2f::norm() const
	{
		return std::sqrt(x*x + y*y);
	}

	void Vector2f::reduce(float fact)
	{
		if(this->norm() == 0)
			return;


		float unitx = x/this->norm();
		float unity = y/this->norm();

		x = unitx * fact;
		y = unity * fact;
	}

	signed int Vector2f::angle(const Vector2f& a) const
	{
		Vector2f v1 = *this;
		Vector2f v2 = a;
		v1.reduce();
		v2.reduce();

		float cos = (v1.x*v2.x) + (v1.y*v2.y);
		float sin = (v1.x*v2.y) - (v1.y*v2.x);

		float rad;

		bool large=false;
		if(cos <= -1.0f)
			return 180;
		else if(cos < 0.0f)
		{
			cos*=-1;
			large=true;
		}

		if(cos >= 1.0f)
			return 0;
		else
			rad = std::acos(cos);

		int deg = (180 * rad / M_PI);

		if(large)
		{
			deg-=90;
			deg*=-1;
			deg+=90;
		}

		if(sin < 0.0f)
			return -deg;
		else
			return deg;
	}

	std::string Vector2f::str() const
	{
		std::string sx(""), sy(""), str("(");

		std::ostringstream oss1;
		oss1<<x;
		sx = oss1.str();

		std::ostringstream oss2;
		oss2<<y;
		sy = oss2.str();

		str+=sx;
		str+=";";
		str+=sy;
		str+=")";

		return str;
	}

	Vector2f Vector2f::operator-() const
	{
		return Vector2f(-x, -y);
	}

	Vector2f Vector2f::operator+(float a) const
	{
		Vector2f ret(*this);
		ret.reduce(ret.norm()+a);
		return ret;
	}

	Vector2f Vector2f::operator+(const Vector2f& a) const
	{
		return Vector2f(x+a.x, y+a.y);
	}

	Vector2f& Vector2f::operator+=(float a)
	{
		*this=*this+a;
		return *this;
	}

	Vector2f& Vector2f::operator+=(const Vector2f& a)
	{
		*this=*this+a;
		return *this;
	}

	Vector2f Vector2f::operator-(float a) const
	{
		Vector2f ret(*this);
		ret.reduce(ret.norm()-a);
		return ret;
	}

	Vector2f Vector2f::operator-(const Vector2f& a) const
	{
		return Vector2f(x-a.x, y-a.y);
	}

	Vector2f& Vector2f::operator-=(float a)
	{
		*this=*this-a;
		return *this;
	}

	Vector2f& Vector2f::operator-=(const Vector2f& a)
	{
		*this=*this-a;
		return *this;
	}

	Vector2f Vector2f::operator*(float a) const
	{
		return Vector2f(x*a, y*a);
	}

	Vector2f& Vector2f::operator*=(float a)
	{
		*this=*this*a;
		return *this;
	}

	Vector2f Vector2f::operator/(float a) const
	{
		return Vector2f(x/a, y/a);
	}

	Vector2f& Vector2f::operator/=(float a)
	{
		*this=*this/a;
		return *this;
	}

};
