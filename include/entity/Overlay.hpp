#ifndef OVERLAY_HPP
#define OVERLAY_HPP

#include "entity/Entity.hpp"

class Overlay : public Entity
{
    public:
        Overlay();

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Time m_time;
        sf::RectangleShape m_rectangle;
};

#endif
