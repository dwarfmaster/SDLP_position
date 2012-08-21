
/*!
 * \file point.doc.hpp
 * \brief Contient la doc de la classe point.
 */

/*!
 * \class sdl::Point
 * \brief Classe template représentant un point.
 */

/*!
 * \fn sdl::Point::Point(Type mx, Type my)
 * \brief Construit le point à partir des valeurs mx et my.
 * \param mx Valeur x du point à construire.
 * \param my Valeur y du point à construire.
 */

/*!
 * \fn explicit sdl::Point::Point(Type all)
 * \brief Construit le point en donnant la même valeur à x et y.
 * \param all Valeur x et y du point à construire.
 */

/*!
 * \fn sdl::Point::Point(const SDL_Rect& cp)
 * \brief Construit le point à partir d'un SDL_Rect.
 * \param cp SDL_Rect à utiliser. Seuls cp.x et cp.y seront utilisés.
 */

/*!
 * \fn sdl::Point::Point(const Point<Cpt>& cp)
 * \brief Construit le point à partir d'un autre type de point.
 * \param cp Point à copier.
 */

/*!
 * \fn Point& sdl::Point::set(Type mx, Type my)
 * \brief Donne au point les valeurs mx et my.
 * \param mx Valeur x du point.
 * \param my Valeur y du point.
 * \return Une référence sur le point.
 */

/*!
 * \fn Point& sdl::Point::set(Type all)
 * \brief Donne à x et à y la même valeur.
 * \param all Valeur x et y du point.
 * \return Une référence sur le point.
 */

/*!
 * \fn Point& sdl::Point::set(const SDL_Rect& cp)
 * \brief Donne au point la valeur d'un SDL_Rect.
 * \param cp SDL_Rect à utiliser. Seuls cp.x et cp.y seront utilisés.
 * \return Une référence sur le point.
 */

/*!
 * \fn Point& sdl::Point::set(const Point<Cpt>& cp)
 * \brief Donne au point la valeur d'un autre type de point.
 * \param cp Point à copier.
 * \return Une référence sur le point.
 */

/*!
 * \fn Point& sdl::Point::clear()
 * \brief Met le point à l'origine (0;0).
 * \return Une référence sur le point.
 */

/*!
 * \fn Point& sdl::Point::operator=(const Point<Cpt>& cp)
 * \brief Donne au point la valeur d'un autre type de point.
 * \param cp Point à copier.
 * \return Une référence sur le point.
 */

/*!
 * \fn sdl::Point::operator SDL_Rect() const
 * \brief Convertit le point en un SDL_Rect.
 * \return Le SDL_Rect créé.
 */

/*!
 * \fn sdl::Point::operator SDL_Rect*() const
 * \brief Convertit le point en un pointeur sur SDL_Rect.
 * \return Le pointeur sur SDL_Rect créé. Ne doit PAS être libéré.
 */

/*!
 * \fn Point& sdl::Point::translate(const Vector2f& v)
 * \brief Déplace le point selon le vecteur v.
 * \param v Vecteur à utiliser pour la translation.
 * \return Une référence sur le point.
 */

/*! 
 * \fn Point sdl::Point::operator+(const Vector2f& v) const
 * \brief Déplace le point selon le vecteur v.
 * \param v Vecteur à utiliser pour la translation.
 * \return Un nouveau point, résultat de la translation de l'actuel par le vecteur v.
 */

/*!
 * \fn Point& sdl::Point::operator+=(const Vector2f& v)
 * \brief Déplace le point selon le vecteur v.
 * \param v Vecteur à utiliser pour la translation.
 * \return Une référence sur le point.
 */

/*!
 * \fn Point sdl::Point::operator-(const Vector2f& v) const
 * \brief Déplace le point selon l'inverse du vecteur v.
 * \param v Vecteur dont l'inverse sera utilisé pour la translation.
 * \return Un nouveau point, résultat de la translation de l'actuel par l'inverse du vecteur v.
 */

/*!
 * \fn Point& sdl::Point::operator-=(const Vector2f& v)
 * \brief Déplace le point selon l'inverse du vecteur v.
 * \param v Vecteur dont l'inverse sera utilisé pour la translation.
 * \return Une référence sur le point.
 */



