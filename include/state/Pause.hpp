#ifndef PAUSE_HPP
#define PAUSE_HPP

#include "state/State.hpp"
#include "entity/Overlay.hpp"
#include "gui/Menu.hpp"

class Pause : public State
{
    public:
        Pause(Stack& stack, const Assets& assets, const State& pausedState);

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        const State& m_pausedState;
        Overlay m_overlay;
        Menu m_menu;
};

#endif
