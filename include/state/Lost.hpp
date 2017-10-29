#ifndef LOST_HPP
#define LOST_HPP

#include "state/LevelMenu.hpp"

class Lost : public LevelMenu
{
    public:
        Lost(Stack& stack, const Assets& assets, const State& pausedState);

        virtual void keyPressed(sf::Keyboard::Key key);

        virtual void buttonClicked(int button);
};

#endif
