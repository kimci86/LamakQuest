#ifndef MENU_HPP
#define MENU_HPP

#include "entity/Entity.hpp"
#include "gui/Button.hpp"

class Menu : public Entity
{
	public :
		Menu(sf::Vector2f size, const sf::String& text, const sf::Font& font, std::vector<Button> buttons);

		virtual void update(sf::Time deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void changeColor(const sf::Vector2f& position);

		bool numButtonClicked(const sf::Vector2f& position, int& idButtonClicked);

	private :
		sf::Vector2f m_size;
		std::vector<Button> m_buttons;
		sf::Text m_title;
};

#endif
