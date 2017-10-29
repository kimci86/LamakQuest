#ifndef LEVELCHOICE_HPP
#define LEVELCHOICE_HPP

#include "gui/Button.hpp"
#include "state/State.hpp"
#include "World.hpp"

class LevelChoice : public State
{
    public:
        LevelChoice(Stack& stack, const Assets& assets);

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        int m_page = 0;
        int m_nbLevels = 20;
        float m_sizeButton;
        Button m_button;
        std::vector<World> m_worlds;
        int m_id;
};

#endif
