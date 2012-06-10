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
		Pointsi minp = min<signed int>(p1, p2);
		Pointsi maxp = max<signed int>(p1, p2);

		m_aabb.x = minp.x;
		m_aabb.y = minp.y;

		m_aabb.w = maxp.x - minp.x;
		m_aabb.h = maxp.y - minp.y;

		return *this;
	}

	AABB& AABB::englobe(const std::vector<AABB>& aabbs, bool strict)
	{
		if(aabbs.empty())
			return *this;

		Pointsi minp(aabbs[0].location(TOP_LEFT));
		Pointsi maxp(aabbs[0].location(BOTTOM_RIGHT));

		for(size_t i=1; i<aabbs.size(); ++i)
		{
			minp = min(minp, aabbs[i].location(TOP_LEFT));
			maxp = max(maxp, aabbs[i].location(BOTTOM_RIGHT));
		}

		if(strict)
		{
			--minp.x;
			--minp.y;
			maxp.x+=2;
			maxp.y+=2;
		}

		this->set(minp, maxp);
		return *this;
	}

	AABB& AABB::englobe(const std::vector<Pointsi>& points, bool strict)
	{
		if(points.empty())
			return *this;

		Pointsi minp(points[0]);
		Pointsi maxp(points[0]);

		for(size_t i=1; i<points.size(); ++i)
		{
			minp = min(minp, points[i]);
			maxp = max(maxp, points[i]);
		}

		if(strict)
		{
			--minp.x;
			--minp.y;
			maxp.x+=2;
			maxp.y+=2;
		}

		this->set(minp, maxp);
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
			case TOP:
				return middle<signed int>(location(TOP_LEFT), location(TOP_RIGHT));
				break;
			case TOP_RIGHT:
				return Pointsi(m_aabb.x + m_aabb.w, m_aabb.y);
				break;
			case RIGHT:
				return middle<signed int>(location(BOTTOM_RIGHT), location(TOP_RIGHT));
				break;
			case BOTTOM_RIGHT:
				return Pointsi(m_aabb.x + m_aabb.w, m_aabb.y + m_aabb.h);
				break;
			case BOTTOM:
				return middle<signed int>(location(BOTTOM_LEFT), location(BOTTOM_RIGHT));
				break;
			case BOTTOM_LEFT:
				return Pointsi(m_aabb.x, m_aabb.y + m_aabb.h);
				break;
			case LEFT:
				return middle<signed int>(location(TOP_LEFT), location(BOTTOM_LEFT));
				break;
			default://Ne peut pas arriver
				return Pointsi(0,0);
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

	Pointsi AABB::operator[](Location p) const
	{
		return this->location(p);
	}
};
