#ifndef WON_HPP
#define WON_HPP

#include "state/LevelMenu.hpp"

class Won : public LevelMenu
{
    public:
        Won(Stack& stack, const Assets& assets, const State& pausedState);

        virtual void buttonClicked(int button);

    private:
        sf::Sound m_sound;
};

#endif
