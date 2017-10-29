#include "entity/Hole.hpp"
#include "util.hpp"

Hole::Hole(float radius, float winnerRadius)
 : Circle(radius)
{
    m_shape.setFillColor(sf::Color::Blue);
    m_winnerRadius = winnerRadius;
}

void Hole::update(sf::Time deltaTime)
{}

bool Hole::contains(const Ball& ball) const
{
    float r = ball.getRadius() - getRadius();
    return squaredLength(ball.getPosition() - getPosition()) <= r * r;
}

bool Hole::isWon(const Ball& ball) const
{
	return squaredLength(ball.getPosition() - getPosition()) <= m_winnerRadius * m_winnerRadius;
}
