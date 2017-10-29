#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "entity/Entity.hpp"
#include <string>

class RoundButton : public Entity
{
	public :
		RoundButton(const sf::Vector2f position, float radius, const sf::String& text, const sf::Font& font);

        const sf::Color& getColor() const;
        void setColor(const sf::Color& color);

        virtual void update(sf::Time deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void changeColor(const sf::Vector2f& position);

		bool inButton(const sf::Vector2f& position);

		const sf::CircleShape& getCircle() const;
	private :
		sf::CircleShape m_shape;
		sf::Text m_text;
		sf::Color m_colorShapeNoHover = sf::Color(36,49,168);
		sf::Color m_colorShapeHover = sf::Color(36,49,218);
		sf::Color m_colorTextNoHover = sf::Color::White;
		sf::Color m_colorTextHover = sf::Color::Yellow;
};

#endif
