#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "state/State.hpp"
#include "World.hpp"
#include "entity/LevelCover.hpp"

class Level : public State
{
    public:
        Level(Stack& stack, const Assets& assets, const World& world);

        virtual void mouseReleased(const sf::Vector2f& position);
        virtual void keyPressed(sf::Keyboard::Key key);
        virtual void lostFocus();

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

        bool checkLost();
        void collisions();

    private:
        bool m_launched;
        World m_world;
        LevelCover m_levelCover;
        sf::Sound m_launch, m_hit;
};

#endif
