#ifndef LEVELCOVER_HPP
#define LEVELCOVER_HPP

#include "entity/Entity.hpp"
#include "entity/Star.hpp"
#include <stdlib.h>
#include <time.h>

class LevelCover : public Entity
{
	public :
		LevelCover();

		virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool isPositionCorrect(const sf::Vector2f position);
	private :
		int m_nbStars;
		std::vector<Star> m_stars;
		sf::Time m_time;
        sf::RectangleShape m_rectangle;
};

#endif
