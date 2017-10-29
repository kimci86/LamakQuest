#include "state/LevelChainer.hpp"
#include "state/LevelRepeater.hpp"
#include "state/Finished.hpp"

LevelChainer::LevelChainer(Stack& stack, const Assets& assets, const std::vector<World>& worlds, int firstLevel)
 : State(stack, assets), m_worlds(worlds), m_currentLevel(firstLevel)
{}

void LevelChainer::update(sf::Time deltaTime)
{
    if(m_currentLevel < m_worlds.size())
        push(std::unique_ptr<State>(new LevelRepeater(getStack(), m_assets, m_worlds[m_currentLevel++])));
    else
        push(std::unique_ptr<State>(new Finished(getStack(), m_assets)));
}

void LevelChainer::draw(sf::RenderTarget& target) const
{}
