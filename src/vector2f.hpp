/*!
 * \file vector2f.hpp
 * \brief Définit la classe Vector2f.
 */

#ifndef DEF_SDLP_VECTOR2F
#define DEF_SDLP_VECTOR2F

#include <SDL/SDL.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace sdl
{
	class Vector2f
	{
		public:
			float x; /*!< Valeur x du vecteur. */
			float y; /*!< Valeur y du vecteur. */

			Vector2f();
			explicit Vector2f(float all);
			Vector2f(float mx, float my);
			Vector2f(float x1, float y1, float x2, float y2); // Du point 1 au point 2
			Vector2f(const SDL_Rect& cp); // Seuls x et y sont considérés
			Vector2f(const SDL_Rect& r1, const SDL_Rect& r2);
			Vector2f(const Vector2f& cp);

			Vector2f& set(float all);
			Vector2f& set(float mx, float my);
			Vector2f& set(float x1, float y1, float x2, float y2);
			Vector2f& set(const SDL_Rect& cp);
			Vector2f& set(const SDL_Rect& r1, const SDL_Rect& r2);
			Vector2f& set(const Vector2f& cp);
			Vector2f& clear();

			SDL_Rect posRect() const; // Retourne la position du vecteur (x et y)
			operator SDL_Rect() const; // Retourne le vecteur sous format SDL_Rect (w et h)

			Vector2f& operator=(float all);
			Vector2f& operator=(const Vector2f& cp);

			float norm() const;
			void reduce(float fact=1.0);
			signed int angle(const Vector2f& a) const;

			std::string str() const;

			Vector2f operator-() const;

			Vector2f operator+(float a) const;
			Vector2f operator+(const Vector2f& a) const;
			Vector2f& operator+=(float a);
			Vector2f& operator+=(const Vector2f& a);

			Vector2f operator-(float a) const;
			Vector2f operator-(const Vector2f& a) const;
			Vector2f& operator-=(float a);
			Vector2f& operator-=(const Vector2f& a);

			Vector2f operator*(float a) const;
			Vector2f& operator*=(float a);

			Vector2f operator/(float a) const;
			Vector2f& operator/=(float a);
	};
};

#endif//DEF_SDLP_VECTOR2F
