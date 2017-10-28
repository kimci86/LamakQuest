#include "entity/Wall.hpp"

Wall::Wall(const sf::Vector2f& p1, const sf::Vector2f& p2)
 : m_vertexArray(sf::Lines, 2)
{
    m_vertexArray[0].position = p1;
    m_vertexArray[1].position = p2;
}

const sf::Vector2f& Wall::getPoint1() const
{
    return m_vertexArray[0].position;
}

const sf::Vector2f& Wall::getPoint2() const
{
    return m_vertexArray[1].position;
}

void Wall::update(sf::Time deltaTime)
{}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_vertexArray, states);
}
