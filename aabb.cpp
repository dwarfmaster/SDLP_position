#include "aabb.hpp"

namespace sdl
{
	AABB::AABB()
	{
		this->clear();
	}

	AABB::AABB(const SDL_Rect& cp)
	{
		this->set(cp);
	}

	AABB::AABB(const AABB& cp)
	{
		this->set(cp);
	}

	AABB::AABB(const Pointsi& p1, const Pointsi& p2)
	{
		this->set(p1, p2);
	}

	AABB& AABB::set(const SDL_Rect& cp)
	{
		m_aabb=cp;
		return *this;
	}

	AABB& AABB::set(const AABB& cp)
	{
		m_aabb = cp.m_aabb;
		return *this;
	}

	AABB& AABB::set(const Pointsi& p1, const Pointsi& p2)
	{
		Pointsi min(std::min(p1.x,p2.x), std::min(p1.y,p2.y));
		Pointsi max(std::max(p1.x,p2.x), std::max(p1.y,p2.y));

		m_aabb.x = min.x;
		m_aabb.y = min.y;

		m_aabb.w = max.x - min.x;
		m_aabb.h = max.y - min.y;

		return *this;
	}

	AABB& AABB::clear()
	{
		m_aabb = makeRect(0, 0, 0, 0);
		return *this;
	}

	void AABB::move(const Pointsi& ori)
	{
		m_aabb.x = ori.x;
		m_aabb.y = ori.y;
	}

	void AABB::resize(const SDL_Rect& nsize)
	{
		m_aabb.w = nsize.w;
		m_aabb.h = nsize.h;
	}

	bool AABB::resize(const Pointsi& second)
	{
		Pointsi first(m_aabb);

		if(first.x > second.x
				|| first.y > second.y)
			return false;
		
		this->set(first, second);
		return true;
	}

	SDL_Rect AABB::rect() const
	{
		return m_aabb;
	}

	Pointsi AABB::location(Location p) const
	{
		switch(p)
		{
			case TOP_LEFT:
				return Pointsi(m_aabb);
				break;
			case TOP_MIDDLE:
				break;
			case TOP_RIGHT:
				return Pointsi(m_aabb.x + m_aabb.w, m_aabb.y);
				break;
			case RIGHT:
				break;
			case BOTTOM_RIGHT:
				return Pointsi(m_aabb.x + m_aabb.w, m_aabb.y + m_aabb.h);
				break;
			case BOTTOM_MIDDLE:
				break;
			case BOTTOM_LEFT:
				return Pointsi(m_aabb.x, m_aabb.y + m_aabb.h);
				break;
			case LEFT:
				break;
		}
	}

	unsigned int AABB::area() const
	{
		return m_aabb.w * m_aabb.h;
	}

	unsigned int AABB::perimeter() const
	{
		return 2*m_aabb.w + 2*m_aabb.h;
	}

	bool AABB::colision(const AABB& other) const
	{
		if(m_aabb.x > other->x + other->w
				|| m_aabb.x + m_aabb.w < other->x
				|| m_aabb.y > other->y + other->h
				|| m_aabb.y + m_aabb.h < other->y )
			return false;
		else
			return true;
	}

	AABB& AABB::operator=(const AABB& cp)
	{
		return this->set(cp);
	}

	SDL_Rect& AABB::operator*()
	{
		return m_aabb;
	}

	const SDL_Rect& AABB::operator*() const
	{
		return m_aabb;
	}

	SDL_Rect* AABB::operator->()
	{
		return &m_aabb;
	}

	const SDL_Rect* AABB::operator->() const
	{
		return &m_aabb;
	}
};
