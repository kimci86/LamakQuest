#include "state/LevelRepeater.hpp"
#include "state/Level.hpp"

LevelRepeater::LevelRepeater(Stack& stack, const Assets& assets, const World& world)
 : State(stack, assets), m_world(world)
{}

void LevelRepeater::update(sf::Time deltaTime)
{
    push(std::unique_ptr<State>(new Level(getStack(), m_assets, m_world)));
}

void LevelRepeater::draw(sf::RenderTarget& target) const
{}
