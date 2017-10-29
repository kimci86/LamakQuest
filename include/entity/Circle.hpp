#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "entity/Entity.hpp"

class Circle : public Entity
{
    public:
        Circle(float radius);

        float getRadius() const;
        void setRadius(float radius);

        const sf::Color& getColor() const;
        void setColor(const sf::Color& color);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::CircleShape m_shape;
        float m_winnerRadius;
};

#endif
