#include "entity/Star.hpp"

Star::Star(sf::Time t)
 : m_time(t)
{
	m_shape.setFillColor(sf::Color(255,255,255,192));
	m_shape.setPointCount(8);
	int i = 2;
	int j = 9;
	m_shape.setPoint(0, sf::Vector2f(j, 0));
	m_shape.setPoint(1, sf::Vector2f(i, i));
	m_shape.setPoint(2, sf::Vector2f(0, j));
	m_shape.setPoint(3, sf::Vector2f(-i, i));
	m_shape.setPoint(4, sf::Vector2f(-j, 0));
	m_shape.setPoint(5, sf::Vector2f(-i, -i));
	m_shape.setPoint(6, sf::Vector2f(0, -j));
	m_shape.setPoint(7, sf::Vector2f(i, -i));
}

void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
    target.draw(m_shape, states);
}

void Star::update(sf::Time deltaTime)
{
	m_time += deltaTime;
	m_shape.setFillColor(sf::Color(255, 255, 255, 130+30*std::sin(m_time.asSeconds()*M_PI)));
	float fact = 0.005*std::sin(m_time.asSeconds()*M_PI)+1;

	m_shape.scale(fact,fact);
}

void Star::setColor(sf::Color color)
{
	m_shape.setFillColor(color);
}
