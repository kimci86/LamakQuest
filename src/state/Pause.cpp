#include "state/Pause.hpp"

Pause::Pause(Stack& stack, const Assets& assets, const State& pausedState)
 : State(stack, assets), m_pausedState(pausedState),
   m_menu({340.f,500.f}, L"Pause", assets.font,
    {
        Button(300.f,L"Restart", assets.font),
        Button(300.f,L"Resume", assets.font),
        Button(300.f,L"Map", assets.font)
    })
{}

void Pause::mouseMoved(const sf::Vector2f& position)
{
    m_menu.changeColor(position);
}

void Pause::mouseReleased(const sf::Vector2f& position)
{
    int idButton;
    if(m_menu.numButtonClicked(position, idButton))
        switch(idButton)
        {
            case 0: // restart
                pop(2);
                break;
            case 1: // resume
                pop();
                break;
            case 2: // map
                pop(4);
                break;
        }
}

void Pause::update(sf::Time deltaTime)
{}

void Pause::draw(sf::RenderTarget& target) const
{
    m_pausedState.draw(target);
    target.draw(m_overlay);
    target.draw(m_menu);
}
