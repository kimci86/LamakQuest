#ifndef LEVELREPEATER_HPP
#define LEVELREPEATER_HPP

#include "state/State.hpp"
#include "World.hpp"

class LevelRepeater : public State
{
    public:
        LevelRepeater(Stack& stack, const Assets& assets, const World& world);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        const World& m_world;
};

#endif
