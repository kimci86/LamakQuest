#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
    public:
        virtual void update(sf::Time deltaTime) = 0;
};

#endif
