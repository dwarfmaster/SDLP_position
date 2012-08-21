
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
 * \file vector2f.doc.hpp
 * \brief Contient la doc de la classe Vector2f.
 */

/*!
 * \namespace sdl
 * \brief Contient les fonctions des bibliothèques SDLP_qqchose.
 */

/*!
 * \class sdl::Vector2f
 * \brief Représente un vecteur 2D à valeur flottante.
 */

/*!
 * \fn explicit sdl::Vector2f::Vector2f(float all)
 * \brief Donne aux valeurs x et y du vecteur la valeur all.
 * \param all Valeur donnée aux valeurs x et y du vecteur.
 */

/*!
 * \fn sdl::Vector2f::Vector2f(float mx, float my)
 * \brief Construit le vecteur à partir de valeurs x et y.
 * \param mx La valeur x du vecteur.
 * \param my La valeur y du vecteur.
 */

/*!
 * \fn sdl::vector2f::Vector2f(float x1, float y1, float x2, float y2)
 * \brief Construit le vecteur comme allant du point (x1;y1) à (x2:y2).
 * \param x1 La valeur x du premier point.
 * \param y1 La valeur y du premier point.
 * \param x2 La valeur x du second point.
 * \param y2 La valeur y du second point.
 */

/*!
 * \fn sdl::Vector2f::Vector2f(const SDL_Rect& cp)
 * \brief Construit le vecteur à partir des valeur x et y de cp.
 * \param cp Un SDL_Rect dont les valeurs x et y seront utilisées pour initialiser le vecteur.
 */

/*!
 * \fn sdl::Vector2f::Vector2f(const SDL_Rect& r1, const SDL_Rect& r2)
 * \brief Construit le vecteur comme allant de r1 à r2.
 * \param r1 La position du premier point.
 * \param r2 La position du second point.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::set(float all)
 * \brief Donne aux valeurs x et y du vecteur la valeur all.
 * \param all Valeur donnée aux valeurs x et y du vecteur.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::set(float mx, float my)
 * \brief Donne au vecteur les valeurs mx et my.
 * \param mx La valeur x du vecteur.
 * \param my La valeur y du vecteur.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::set(float x1, float y1, float x2, float y2)
 * \brief Définit le vecteur comme allant du point (x1;y1) à (x2:y2).
 * \param x1 La valeur x du premier point.
 * \param y1 La valeur y du premier point.
 * \param x2 La valeur x du second point.
 * \param y2 La valeur y du second point.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::set(const SDL_Rect& cp)
 * \brief Donne au vecteur les valeur x et y de cp.
 * \param cp Un SDL_Rect dont les valeurs x et y seront utilisées.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::set(const SDL_Rect& r1, const SDL_Rect& r2)
 * \brief Définit le vecteur comme allant de r1 à r2.
 * \param r1 La position du premier point.
 * \param r2 La position du second point.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::set(const Vector2f& cp)
 * \brief Copie cp dans le vecteur.
 * \param cp Le vecteur à copier.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::clear()
 * \brief Fait du vecteur un vecteur nul (0;0).
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn SDL_Rect sdl::Vector2f::posRect() const
 * \brief Retourne la position du vecteur sous la forme d'un SDL_Rect.
 * \return La position du vecteur.
 */

/*!
 * \fn sdl::Vector2f::operator SDL_Rect() const
 * \brief Retourne la position du vecteur sous la forme d'un SDL_Rect.
 * \return La position du vecteur.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator=(float all)
 * \brief Donne aux valeurs x et y du vecteur la valeur all.
 * \param all Valeur donnée aux valeurs x et y du vecteur.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator=(const Vector2f& cp)
 * \brief Copie cp dans le vecteur.
 * \param cp Le vecteur à copier.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn float sdl::Vector2f::norm() const
 * \brief Donne la norme (la taille) du vecteur.
 * \return La norme du vecteur.
 */

/*!
 * \fn void sdl::Vector2f::reduce(float fact=1.0)
 * \brief Change le vecteur de norme.
 * \param fact La nouvelle norme du vecteur.
 */

/*!
 * \fn signed int sdl::Vector2f::angle(const Vector2f& a) const
 * \brief Donne l'angle allant du vecteur appelant à a.
 * \param a Le second vecteur définissant l'autre côté de l'angle.
 * \return L'angle entre les deux vecteurs.
 */

/*!
 * \fn std::string sdl::Vector2f::str() const
 * \brief Donne le vecteur sous la forme d'une chaine de caractères.
 * \return Le vecteur sous la forme "(valeur_x;valeur_y)".
 */

/*!
 * \fn Vector2f sdl::Vector2f::operator-() const
 * \brief Inverse le vecteur.
 * \return Un vecteur ayant une valeur inverse au vecteur appelant.
 */

/*!
 * \fn Vector2f sdl::Vector2f::operator+(float a) const
 * \brief Donne un vecteur dont la norme est plus grande de a que celle du vecteur appelant.
 * \param a La valeur à ajouter.
 * \return Le vecteur avec la nouvelle norme.
 */

/*!
 * \fn Vector2f sdl::Vector2f::operator+(const Vector2f& a) const
 * \brief Retourne l'addition du vecteur appelant et du vecteur a.
 * \param a Le vecteur à ajouter.
 * \return Un vecteur ayant pour valeur la somme du vecteur appelant et du vecteur a.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator+=(float a)
 * \brief Augmente de a la norme du vecteur appelant.
 * \param a La valeur à ajouter.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator+=(const Vector2f& a)
 * \brief Ajoute au vecteur appelant le vecteur a.
 * \param a Le vecteur à ajouter.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f sdl::Vector2f::operator-(float a) const
 * \brief Donne un vecteur dont la norme est plus petite de a que celle du vecteur appelant.
 * \param a La valeur à soutraire.
 * \return Le vecteur avec la nouvelle norme.
 */

/*!
 * \fn Vector2f sdl::Vector2f::operator-(const Vector2f& a) const
 * \brief Retourne l'addition du vecteur appelant et du vecteur inverse de a.
 * \param a Le vecteur à soustraire.
 * \return Un vecteur ayant pour valeur la somme du vecteur appelant et du vecteur inverse de a.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator-=(float a)
 * \brief Diminue de a la norme du vecteur appelant.
 * \param a La valeur à soustraire.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator-=(const Vector2f& a)
 * \brief Ajoute au vecteur appelant le vecteur inverse de a.
 * \param a Le vecteur dont l'inverse est à ajouter.
 * \return Un référence sur le vecteur appelant.
 */

/*! 
 * \fn Vector2f sdl::Vector2f::operator*(float a) const
 * \brief Donne un vecteur dont la norme est le multiple de a et de celle du vecteur appelant.
 * \param a La valeur à multiplier.
 * \return Le vecteur avec la nouvelle norme.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator*=(float a)
 * \brief Multiplie par a la norme du vecteur appelant.
 * \param a La valeur à multiplier.
 * \return Un référence sur le vecteur appelant.
 */

/*!
 * \fn Vector2f sdl::Vector2f::operator/(float a) const
 * \brief Donne un vecteur dont la norme est la division de celle du vecteur appelant par a.
 * \param a La valeur utilisée pour diviser.
 * \return Le vecteur avec la nouvelle norme.
 */

/*!
 * \fn Vector2f& sdl::Vector2f::operator/=(float a)
 * \brief Divise par a la norme du vecteur appelant.
 * \param a La valeur utilisée pour diviser.
 * \return Un référence sur le vecteur appelant.
 */

