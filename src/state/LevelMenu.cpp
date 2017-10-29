#include "state/LevelMenu.hpp"

LevelMenu::LevelMenu(Stack& stack, const Assets& assets, const State& pausedState, const Menu& menu)
 : State(stack, assets), m_pausedState(pausedState), m_menu(menu)
{}

void LevelMenu::mouseMoved(const sf::Vector2f& position)
{
    m_menu.changeColor(position);
}

void LevelMenu::mouseReleased(const sf::Vector2f& position)
{
    int button;
    if(m_menu.numButtonClicked(position, button))
        buttonClicked(button);
}

void LevelMenu::update(sf::Time deltaTime)
{}

void LevelMenu::draw(sf::RenderTarget& target) const
{
    m_pausedState.draw(target);
    target.draw(m_overlay);
    target.draw(m_menu);
}
