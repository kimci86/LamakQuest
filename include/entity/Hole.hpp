#ifndef HOLE_HPP
#define HOLE_HPP

#include "entity/Circle.hpp"
#include "entity/Ball.hpp"

class Hole : public Circle
{
    public:
//        Hole(float radius = 32.f);
        Hole(float radius = 60.f, float winnerRadius = 10.f);

        virtual void update(sf::Time deltaTime);

        bool contains(const Ball& ball) const;

        bool isWon(const Ball& ball) const;

	private:
        sf::CircleShape m_shape;
        float m_winnerRadius;
};

#endif
