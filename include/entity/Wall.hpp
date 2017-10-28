#ifndef WALL_HPP
#define WALL_HPP

#include "entity/Entity.hpp"

class Wall : public Entity
{
    public:
        Wall(const sf::Vector2f& p1, const sf::Vector2f& p2);

        const sf::Vector2f& getPoint1() const;

        const sf::Vector2f& getPoint2() const;

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::VertexArray m_vertexArray;
};

#endif
