#include "gui/Button.hpp"

Button::Button(const float width, const sf::String& text, const sf::Font& font)
 : m_shape(sf::Vector2f(width,120.f))
{
	initialize(text, font);
}

Button::Button(const sf::Vector2f size, const sf::String& text, const sf::Font& font)
 : m_shape(size)
 {
 	initialize(text, font);
 }

void Button::initialize(const sf::String& text,const sf::Font& font)
{
	setColor(m_colorShapeNoHover);

	m_text.setString(text);
	m_text.setFont(font);
	m_text.setStyle(sf::Text::Bold);
	m_text.setCharacterSize(30);

	//Positionnement au milieu du rectangle
	sf::FloatRect rect = m_text.getGlobalBounds();
	sf::FloatRect size = m_shape.getGlobalBounds();
	m_text.setPosition(sf::Vector2f(size.width/2-rect.width/2,size.height/2-rect.height));

}

const sf::Color& Button::getColor() const
{
    return m_shape.getFillColor();
}

void Button::setColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
}

const sf::RectangleShape& Button::getRectangle() const
{
    return m_shape;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text, states);
}

void Button::update(sf::Time deltaTime)
{}

void Button::changeColor(const sf::Vector2f& position)
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

bool Button::inButton(const sf::Vector2f& position)
{
	sf::Vector2f locationShape = getPosition();
	sf::Vector2f size = m_shape.getSize();
	return locationShape.x < position.x && position.x < locationShape.x + size.x
	&& locationShape.y < position.y && position.y < locationShape.y + size.y;
}
