#include "entity/Hole.hpp"
#include "util.hpp"

Hole::Hole(const Assets& assets, float radius, float winnerRadius)
 : m_vortex(assets.vortex), m_radius(radius), m_winnerRadius(winnerRadius)
{
    m_vortex.setColor(sf::Color(0,0,0xff,0xc0));
    m_vortex.setOrigin(sf::Vector2f(m_vortex.getLocalBounds().width, m_vortex.getLocalBounds().height) / 2.f);
}

void Hole::update(sf::Time deltaTime)
{
    m_vortex.rotate(-deltaTime.asSeconds()*20.f);
}

bool Hole::contains(const Ball& ball) const
{
    float r = ball.getRadius() - m_radius;
    return squaredLength(ball.getPosition() - getPosition()) <= r * r;
}

bool Hole::isWon(const Ball& ball) const
{
	return squaredLength(ball.getPosition() - getPosition()) <= m_winnerRadius * m_winnerRadius;
}

void Hole::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_vortex, states);
}
