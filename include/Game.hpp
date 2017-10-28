#ifndef GAME_HPP
#define GAME_HPP

#include "state/State.hpp"
#include <string>

class Game
{
    public:
        Game();

        bool run();

    private:
        bool handleEvents();

        sf::Vector2f getWorldCoordinates(int x, int y) const;

        bool update(sf::Time deltaTime);

        void render();

        State& getState();

        const State& getState() const;

        sf::RenderWindow m_window;
        State::Stack m_stack;
        bool mousePressed = false;

        Assets m_assets;
};

#endif
