#ifndef PAUSE_HPP
#define PAUSE_HPP

#include "state/LevelMenu.hpp"

class Pause : public LevelMenu
{
    public:
        Pause(Stack& stack, const Assets& assets, const State& pausedState);

        virtual void buttonClicked(int button);
};

#endif
