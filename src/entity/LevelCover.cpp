#include "entity/LevelCover.hpp"
#include "util.hpp"

LevelCover::LevelCover()
 : m_rectangle(sf::Vector2f(1024.f,768.f)), m_nbStars(40)
{
	m_rectangle.setFillColor(sf::Color::Black);
	srand (time(NULL));
	for (int i = 0; i < m_nbStars ; i++)
	{
		int x = rand() % 1024;
		int y = rand() % 768;
		sf::Vector2f position(x,y);
		while(!isPositionCorrect(position))
		{
			x = rand() % 1024;
			y = rand() % 768;
			position = sf::Vector2f(x,y);
		}
		sf::Time t1 = sf::seconds(((float)(rand() % 200))/200);
		Star star(t1);
		star.setPosition(position);
		star.setColor(sf::Color(255,255,255,192));
		m_stars.push_back(star);
	}
}

void LevelCover::update(sf::Time deltaTime)
{
	for (Star& s : m_stars)
    {
    	s.update(deltaTime);
    }
}

void LevelCover::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
    target.draw(m_rectangle, states);
    for (const Star& s : m_stars)
    {
    	target.draw(s, states);
    }
}

bool LevelCover::isPositionCorrect(const sf::Vector2f position)
{
	for (const Star& s : m_stars)
	{
		if(length( s.getPosition() - position)<25.f)
			return false;
	}
	return true;
}
