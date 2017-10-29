#ifndef LEVELMENU_HPP
#define LEVELMENU_HPP

#include "state/State.hpp"
#include "entity/Overlay.hpp"
#include "gui/Menu.hpp"

class LevelMenu : public State
{
    public:
        LevelMenu(Stack& stack, const Assets& assets, const State& pausedState, const Menu& menu);

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);

        virtual void buttonClicked(int button) = 0;

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        const State& m_pausedState;
        Overlay m_overlay;
        Menu m_menu;
};

#endif
