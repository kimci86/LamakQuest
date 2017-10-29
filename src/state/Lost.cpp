#include "state/Lost.hpp"

Lost::Lost(Stack& stack, const Assets& assets, const State& pausedState)
 : LevelMenu(stack, assets, pausedState,
   {{340.f,500.f}, L"Loser", assets.font,
    {
        Button(300.f,L"Restart", assets.font),
        Button(300.f,L"Map", assets.font)
    }}),
   m_sound(assets.lose)
{
    m_sound.play();
}

void Lost::keyPressed(sf::Keyboard::Key key)
{
    if(key == sf::Keyboard::Space)
        pop(2); // restart
}

void Lost::buttonClicked(int button)
{
    switch(button)
    {
        case 0: // restart
            pop(2);
            break;
        case 1: // map
            pop(4);
            break;
    }
}
