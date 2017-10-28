#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "entity/Entity.hpp"
#include <string>

class Button : public Entity
{
	public :
		Button(const float width, const sf::String& text, const sf::Font& font);
		Button(const sf::Vector2f size, const sf::String& text, const sf::Font& font);

		void initialize(const sf::String& text, const sf::Font& font);

        const sf::Color& getColor() const;
        void setColor(const sf::Color& color);

        virtual void update(sf::Time deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void changeColor(const sf::Vector2f& position);

		bool inButton(const sf::Vector2f& position);

		const sf::RectangleShape& getRectangle() const;
	private :
		sf::RectangleShape m_shape;
		sf::Text m_text;
		sf::Color m_colorShapeNoHover = sf::Color(36,49,168);
		sf::Color m_colorShapeHover = sf::Color(36,49,218);
		sf::Color m_colorTextNoHover = sf::Color::White;
		sf::Color m_colorTextHover = sf::Color::Yellow;
};

#endif
