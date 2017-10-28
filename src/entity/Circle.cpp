#include "entity/Circle.hpp"

Circle::Circle(float radius)
 : m_shape(radius)
{
    m_shape.setOrigin(radius, radius);
}

float Circle::getRadius() const
{
    return m_shape.getRadius();
}

void Circle::setRadius(float radius)
{
    m_shape.setRadius(radius);
}

const sf::Color& Circle::getColor() const
{
    return m_shape.getFillColor();
}

void Circle::setColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
}
