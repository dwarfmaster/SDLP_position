
/*!
 * \file tools.doc.hpp
 * \brief Contient la doc des fonctions de tools.hpp.
 */


/*!
 * \fn SDL_Rect sdl::makeRect(int x, int y, int w=0, int h=0)
 * \brief Crée un SDL_Rect à partir des valeurs x, y, w et h.
 * \param x Valeur x du nouveau SDL_Rect.
 * \param y Valeur y du nouveau SDL_Rect.
 * \param w Valeur w du nouveau SDL_Rect.
 * \param h Valeur h du nouveau SDL_Rect.
 * \return Le SDL_Rect créé.
 */

/*!
 * \fn Point<T> sdl::middle(const Point<T>& p1, const Point<T>& p2)
 * \brief Donne le point au milieu des points p1 et p2.
 * \param p1 Le premier point.
 * \param p2 Le second point.
 * \return Le point au milieu.
 */

/*!
 * \fn unsigned int sdl::length(const Point<T>& p1, const Point<T>& p2)
 * \brief Donne la distance séparant les points p1 et p2.
 * \param p1 Le premier point.
 * \param p2 Le second point.
 * \return Le distance entre p1 et p2.
 */

/*!
 * \fn Point<T> sdl::min(const Point<T>& p1, const Point<T>& p2)
 * \brief Donne le point le plus en haut à gauche obtenu avec p1 et p2.
 * \param p1 Le premier point.
 * \param p2 Le second point.
 * \return Le point en haut à gauche de l'AABB englobant les points p1 et p2.
 */

/*!
 * \fn Point<T> sdl::max(const Point<T>& p1, const Point<T>& p2)
 * \brief Donne le point le plus en bas à droite obtenu avec p1 et p2.
 * \param p1 Le premier point.
 * \param p2 Le second point.
 * \return Le point en bas à droite de l'AABB englobant les points p1 et p2.
 */


