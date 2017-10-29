#include "state/Won.hpp"

Won::Won(Stack& stack, const Assets& assets, const State& pausedState)
 : LevelMenu(stack, assets, pausedState,
   {{340.f,500.f}, L"Winner!", assets.font,
    {
        Button(300.f,L"Restart", assets.font),
        Button(300.f,L"Next level", assets.font),
        Button(300.f,L"Map", assets.font)
    }})
{}

void Won::buttonClicked(int button)
{
    switch(button)
    {
        case 0: // restart
            pop(2);
            break;
        case 1: // next level
            pop(3);
            break;
        case 2: // map
            pop(4);
            break;
    }
}
