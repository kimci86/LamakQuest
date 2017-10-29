#include "state/Pause.hpp"

Pause::Pause(Stack& stack, const Assets& assets, const State& pausedState)
 : LevelMenu(stack, assets, pausedState,
   {{340.f,500.f}, L"Pause", assets.font,
    {
        Button(300.f,L"Restart", assets.font),
        Button(300.f,L"Resume", assets.font),
        Button(300.f,L"Map", assets.font)
    }})
{}

void Pause::buttonClicked(int button)
{
    switch(button)
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
