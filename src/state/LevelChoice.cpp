#include "state/LevelChoice.hpp"
#include "state/LevelChainer.hpp"

LevelChoice::LevelChoice(Stack& stack, const Assets& assets)
 : State(stack, assets), m_sizeButton(200.f),
   m_button(Button(sf::Vector2f(200.f,200.f),L"", assets.font)),
   m_worlds({{"levels/1.txt"}}),m_id(1)
{
}

void LevelChoice::update(sf::Time deltaTime)
{
}

void LevelChoice::draw(sf::RenderTarget& target) const
{
	target.draw(m_button);
}

void LevelChoice::mouseMoved(const sf::Vector2f& position)
{
    m_button.changeColor(position);
}

void LevelChoice::mouseReleased(const sf::Vector2f& position)
{
	if(m_button.inButton(position))
    	push(std::unique_ptr<State>(new LevelChainer(getStack(), m_assets, m_worlds, 0)));
}