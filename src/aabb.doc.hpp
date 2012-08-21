
/*!
 * \file aabb.doc.hpp
 * \brief Contient la doc de la classe AABB.
 */

/*!
 * \class sdl::AABB
 * \brief Sert à manipuler un rectangle aligné aux axes.
 */

/*!
 * \enum sdl::AABB::Location
 * \brief Indique les différents points remarquables de l'AABB.
 */

/*!
 * \fn sdl::AABB::AABB()
 * \brief Constructeur par défault. Crée une AABB vide (0;0) - 0x0.
 */

/*!
 * \fn sdl::AABB::AABB(const SDL_Rect& cp)
 * \brief Construit l'AABB à partir du SDL_Rect.
 * \param cp Le SDL_Rect utilisé pour initiliser la classe.
 */

/*!
 * \fn sdl::AABB::AABB(const Pointsi& p1, const Pointsi& p2)
 * \brief Construit l'AABB comme le rectangle le plus petit contenant les points p1 et p2.
 * \param p1 Le premier point à contenir.
 * \param p2 Le second point à contenir.
 */

/*!
 * \fn AABB& sdl::AABB::set(const SDL_Rect& cp)
 * \brief Donne au AABB les valeurs du SDL_Rect.
 * \param cp Le SDL_Rect copié.
 * \return Un référence sur l'AABB appelante.
 */

/*!
 * \fn AABB& sdl::AABB::set(const Pointsi& p1, const Pointsi& p2)
 * \brief définit l'AABB comme le rectangle le plus petit contenant les points p1 et p2.
 * \param p1 Le premier point à contenir.
 * \param p2 Le second point à contenir.
 * \return Un référence sur l'AABB appelante.
 */

/*!
 * \fn AABB& sdl::AABB::englobe(const std::vector<AABB>& aabbs, bool strict=false)
 * \brief Définit l'AABB comme le rectangle le plus petit englobant les aabbs.
 * \param aabbs Les AABBs à englober.
 * \param strict Si strict vaut true, les AABBs seront strictement comprises dans l'AABB appelante, sinon les bords pourront être en contact.
 * \return Un référence sur l'AABB appelante.
 */

/*!
 * \fn AABB& sdl::AABB::englobe(const std::vector<Pointsi>& points, bool strict=false)
 * \brief Définit l'AABB comme le rectangle le plus petit englobant les points.
 * \param points Les points à englober.
 * \param strict Si strict vaut true, les points seront strictement compris dans l'AABB appelante, sinon les bords pourront être en contact.
 * \return Un référence sur l'AABB appelante.
 */

/*!
 * \fn AABB& sdl::AABB::clear()
 * \brief vide l'AABB (0;0) - 0x0.
 * \return Un référence sur l'AABB appelante.
 */

/*!
 * \fn void sdl::AABB::move(const Pointsi& ori)
 * \brief Va déplacer l'AABB de sorte que le coint en haut à gauche soit sur ori.
 * \param ori La nouvelle position de l'AABB.
 */

/*!
 * \fn void sdl::AABB::resize(const SDL_Rect& nsize)
 * \brief Change la taille de l'AABB sans en changer la position.
 * \param nsize La nouvelle taille. Seuls nsize.w et nsize.h seront utilisés.
 */

/*!
 * \fn bool sdl::AABB::resize(const Pointsi& second)
 * \brief Va placer le point en bas à droite sur second sans bouger le point en haut à gauche.
 * \param second La nouvelle position du point.
 * \return Indique si la fonction à fait quelque chose : elle ne fait rien si l'argument second n'est pas en bas à droite de l'origine de l'AABB appelante.
 */

/*!
 * \fn SDL_Rect sdl::AABB::rect() const
 * \brief Donne un SDL_Rect aux valeurs de l'AABB appelante.
 * \return Un SDL_Rect aux valeurs de l'AABB appelante.
 */

/*!
 * \fn Pointsi sdl::AABB::location(Location p) const
 * \brief Donne le point à la position p de l'AABB.
 * \param p Le point de L'AABB dont on doit retourner la position.
 * \return La position du point voulu.
 */

/*!
 * \fn unsigned int sdl::AABB::area() const
 * \brief Donne l'aire de l'AABB.
 * \return L'aire de l'AABB.
 */

/*!
 * \fn unsigned int sdl::AABB::perimeter() const
 * \brief Donne le périmètre de l'AABB.
 * \return Le périmètre de l'AABB.
 */

/*!
 * \fn bool sdl::AABB::colision(const AABB& other) const
 * \brief Indique si l'AABB appelante est en contact avec other.
 * \param other L'AABB dont on doit tester la contact.
 * \return Contact ou pas avec l'AABB other.
 */

/*!
 * \fn bool sdl::AABB::contain(const Pointsi& p) const
 * \brief Indique si le point p est à l'intérieur de l'AABB.
 * \param p Le point à tester.
 * \return Si le point est à l'intérieur true, sinon false.
 */

/*!
 * \fn SDL_Rect& sdl::AABB::operator*()
 * \brief Permet de modifier directement les membres x, y, w et h de la classe.
 * \return Une référence sur le SDL_Rect de la classe.
 */

/*!
 * \fn const SDL_Rect& sdl::AABB::operator*() const
 * \brief Permet d'accéder directement aux membres x, y, w et h de la classe.
 * \return Une référence constante sur le SDL_Rect de la classe.
 */

/*!
 * \fn SDL_Rect* sdl::AABB::operator->()
 * \brief Permet de modifier directement les membres x, y, w et h de la classe.
 * \return Un pointeur sur le SDL_Rect de la classe.
 */

/*!
 * \fn const SDL_Rect* sdl::AABB::operator->() const
 * \brief Permet d'accéder directement aux membres x, y, w et h de la classe.
 * \return Un pointeur constant sur le SDL_Rect de la classe.
 */

/*!
 * \fn Pointsi sdl::AABB::operator[](Location p) const
 * \brief Donne le point à la position p de l'AABB.
 * \param p Le point de L'AABB dont on doit retourner la position.
 * \return La position du point voulu.
 */


