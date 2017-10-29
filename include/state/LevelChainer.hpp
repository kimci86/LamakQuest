#ifndef LEVELCHAINER_HPP
#define LEVELCHAINER_HPP

#include "state/State.hpp"
#include "World.hpp"

class LevelChainer : public State
{
    public:
        LevelChainer(Stack& stack, const Assets& assets, const std::vector<World>& worlds, int firstLevel);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        const std::vector<World>& m_worlds;
        int m_currentLevel;
};

#endif
