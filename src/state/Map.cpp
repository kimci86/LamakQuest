#include "state/Map.hpp"
#include "state/LevelChainer.hpp"

Map::Map(Stack& stack, const Assets& assets)
 : State(stack, assets), m_sizeButton(200.f),
   m_button(sf::Vector2f(200.f,200.f), 100.f,L"1", assets.font),
   m_path(assets.path),
   m_worlds({{"levels/tutoHole.txt", assets}, {"levels/tutoWall.txt", assets}, {"levels/tutoAttractive.txt", assets}, {"levels/tutoRepulsive.txt", assets}, {"levels/ourson.txt", assets}, {"levels/dinosaur.txt", assets}, {"levels/initialSpeed.txt", assets}, {"levels/hell.txt", assets}, {"levels/arrow.txt", assets}, {"levels/turnAround.txt", assets}}),m_id(1)
{
    m_path.setPosition({110, 120});
}

void Map::update(sf::Time deltaTime)
{
    m_stars.update(deltaTime);
}

void Map::draw(sf::RenderTarget& target) const
{
    target.draw(m_stars);
    target.draw(m_path);
	target.draw(m_button);
}

void Map::mouseMoved(const sf::Vector2f& position)
{
    m_button.changeColor(position);
}

void Map::mouseReleased(const sf::Vector2f& position)
{
	if(m_button.inButton(position))
    	push(std::unique_ptr<State>(new LevelChainer(getStack(), m_assets, m_worlds, 0)));
}
