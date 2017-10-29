#include "gui/RoundButton.hpp"
#include "util.hpp"

RoundButton::RoundButton(const sf::Vector2f position, float radius, const sf::String& text, const sf::Font& font)
 : m_shape(radius)
 {
 	setPosition(position);
 	m_shape.setOrigin(sf::Vector2f(radius, radius));
	setColor(m_colorShapeNoHover);

	m_text.setString(text);
	m_text.setFont(font);
	m_text.setStyle(sf::Text::Bold);
	m_text.setCharacterSize(30);

	//Positionnement au milieu du rectangle
	sf::FloatRect rect = m_text.getGlobalBounds();
	m_text.setPosition(-sf::Vector2f(rect.width,rect.height)/2.f);
 }

const sf::Color& RoundButton::getColor() const
{
    return m_shape.getFillColor();
}

void RoundButton::setColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
}

const sf::CircleShape& RoundButton::getCircle() const
{
    return m_shape;
}

void RoundButton::update(sf::Time deltaTime)
{}

void RoundButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text, states);
}

void RoundButton::changeColor(const sf::Vector2f& position)
{
	if(inButton(position))
	{
		setColor(m_colorShapeHover);
	}
	else
	{
		setColor(m_colorShapeNoHover);
	}
}

bool RoundButton::inButton(const sf::Vector2f& position)
{
	float size = m_shape.getRadius();
	return squaredLength(position - getPosition()) <= size * size;
}
