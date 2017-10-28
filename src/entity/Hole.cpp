#include "entity/Hole.hpp"
#include "util.hpp"

Hole::Hole(float radius)
 : Circle(radius)
{
    m_shape.setFillColor(sf::Color::Blue);
}

void Hole::update(sf::Time deltaTime)
{}

bool Hole::contains(const Ball& ball) const
{
    float r = ball.getRadius() - getRadius();
    return squaredLength(ball.getPosition() - getPosition()) <= r * r;
}
