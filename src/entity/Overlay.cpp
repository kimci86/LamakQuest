#include "entity/Overlay.hpp"
#include <cmath>

Overlay::Overlay()
 : m_rectangle(sf::Vector2f(1024.f, 768.f))
{
    m_rectangle.setFillColor(sf::Color(0, 0, 0, 192));
}

void Overlay::update(sf::Time deltaTime)
{
    m_time += deltaTime;
    m_rectangle.setFillColor(sf::Color(0, 0, 0, 192+16*std::sin(m_time.asSeconds()*M_PI)));
}

void Overlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_rectangle, states);
}
