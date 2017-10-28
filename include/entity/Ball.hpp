#ifndef BALL_HPP
#define BALL_HPP

#include "entity/Circle.hpp"
#include "entity/Wall.hpp"

class Ball : public Circle
{
    public:
        Ball(float radius = 16.f);

        virtual void update(sf::Time deltaTime);

        void launch(const sf::Vector2f& position);

        bool intersects(const Wall& wall, sf::Vector2f& hitPoint, sf::Vector2f& normal) const;

        void bounce(const sf::Vector2f& hitPoint, const sf::Vector2f& normal);

        const sf::Vector2f& getVelocity() const;
        void setVelocity(const sf::Vector2f& offset);

    private:
        sf::Vector2f m_velocity;
};

#endif
