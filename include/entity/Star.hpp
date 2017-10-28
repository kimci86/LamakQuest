#ifndef STAR_HPP
#define STAR_HPP

#include "entity/Entity.hpp"

class Star : public Entity
{
	public:
		Star(sf::Time t);

		virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void setColor(sf::Color color);
	private:
		sf::ConvexShape m_shape;
		sf::Time m_time;
};

#endif
