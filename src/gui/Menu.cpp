#include "gui/Menu.hpp"

Menu::Menu(sf::Vector2f size, const sf::String& text, const sf::Font& font, std::vector<Button> buttons)
: m_size(size), m_buttons(buttons)
{
	m_title.setString(text);
	m_title.setFont(font);
	m_title.setCharacterSize(40);

	float heightButton = m_buttons[0].getRectangle().getGlobalBounds().height;

	float maxWidthButtons=0.f;
	for(const Button& b : m_buttons){
		maxWidthButtons=std::max(b.getRectangle().getGlobalBounds().width, maxWidthButtons);
	}

	float ecartHeight = (size.y-m_buttons.size()*heightButton)/m_buttons.size();
	float ecartWidth = (size.x - maxWidthButtons)/2;

	m_title.setPosition(sf::Vector2f(ecartWidth,0.5*ecartHeight));
	for(int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].setPosition(sf::Vector2f(ecartWidth,(i+1.5)*ecartHeight+i*heightButton));
	}
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for(const Button& b : m_buttons)
	{
		target.draw(b, states);
	}
	target.draw(m_title, states);
}

void Menu::update(sf::Time deltaTime)
{}

void Menu::changeColor(const sf::Vector2f& position)
{
	sf::Vector2f localPosition = getInverseTransform()*position;
	for(Button& b : m_buttons)
	{
		b.changeColor(localPosition);
	}
}

bool Menu::numButtonClicked(const sf::Vector2f& position, int& idButtonClicked)
{
	sf::Vector2f localPosition = getInverseTransform()*position;
	for(int i = 0; i < m_buttons.size(); i++)
		if(m_buttons[i].inButton(localPosition))
		{
			idButtonClicked = i;
			return true;
		}
	return false;
}
