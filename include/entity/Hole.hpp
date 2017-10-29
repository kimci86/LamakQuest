#ifndef HOLE_HPP
#define HOLE_HPP

#include "Assets.hpp"
#include "entity/Ball.hpp"

class Hole : public Entity
{
    public:
        Hole(const Assets& assets, float radius = 60.f, float winnerRadius = 10.f);

        virtual void update(sf::Time deltaTime);

        bool contains(const Ball& ball) const;

        bool isWon(const Ball& ball) const;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
        sf::Sprite m_vortex;
        float m_radius, m_winnerRadius;
};

#endif
