#include "state/Map.hpp"
#include "state/LevelChainer.hpp"

Map::Map(Stack& stack, const Assets& assets)
 : State(stack, assets), m_sizeButton(200.f),
   m_buttons({
    {{150.f,150.f}, 50.f, L"1", assets.font},
    {{360.f,230.f}, 50.f, L"2", assets.font},
    {{630.f,220.f}, 50.f, L"3", assets.font},
    {{890.f,320.f}, 50.f, L"4", assets.font},
    {{600.f,400.f}, 50.f, L"5", assets.font},
    {{300.f,390.f}, 50.f, L"6", assets.font},
    {{210.f,540.f}, 50.f, L"7", assets.font},
    {{460.f,560.f}, 50.f, L"8", assets.font},
    {{710.f,580.f}, 50.f, L"9", assets.font},
    {{880.f,660.f}, 50.f, L"10", assets.font}
   }),
   m_path(assets.path),
   m_worlds({{"levels/tutoHole.txt", assets}, {"levels/tutoWall.txt", assets}, {"levels/tutoAttractive.txt", assets}, {"levels/tutoRepulsive.txt", assets}, {"levels/ourson.txt", assets}, {"levels/dinosaur.txt", assets}, {"levels/initialSpeed.txt", assets}, {"levels/hell.txt", assets}, {"levels/arrow.txt", assets}, {"levels/turnAround.txt", assets}}),m_id(1)
{
    m_path.setPosition({110, 100});
}

void Map::update(sf::Time deltaTime)
{
    m_stars.update(deltaTime);
}

void Map::draw(sf::RenderTarget& target) const
{
    target.draw(m_stars);
    target.draw(m_path);
    for(const RoundButton& b : m_buttons)
       target.draw(b);
}

void Map::mouseMoved(const sf::Vector2f& position)
{
    for(RoundButton& b : m_buttons)
        b.changeColor(position);
}

void Map::mouseReleased(const sf::Vector2f& position)
{
    for(int i = 0; i < m_buttons.size(); i++)
	    if(m_buttons[i].inButton(position))
    	   push(std::unique_ptr<State>(new LevelChainer(getStack(), m_assets, m_worlds, i)));
}
