#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "state/State.hpp"
#include "World.hpp"
#include "entity/Overlay.hpp"
#include "gui/Button.hpp"
#include "gui/Menu.hpp"
#include "entity/LevelCover.hpp"

class Level : public State
{
    public:
        Level(Stack& stack, const Assets& assets, const World& world);

        void initialize();

        virtual void mouseReleased(const sf::Vector2f& position);
        virtual void restart();

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

        virtual void mouseMoved(const sf::Vector2f& position);

        bool checkLost();
        void collisions();
        void nextLevel();
        void menu();

    private:
        bool m_launched;
        const World& m_initialWorld;
        World m_world;
        Overlay m_overlay;
        LevelCover m_levelCover;
        std::vector<Menu> m_menus;
};

#endif
