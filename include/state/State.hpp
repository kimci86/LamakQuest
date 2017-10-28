#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Assets.hpp"
#include "state/LevelStates.hpp"

class Transition;

class State
{
    public:
        using Stack = std::stack<std::unique_ptr<State>>;

        State(Stack& stack, const Assets& assets);
        virtual ~State();

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mousePressed(const sf::Vector2f& position);
        virtual void mouseDragged(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);

        virtual void restart();

        virtual void nextLevel();

        bool isPaused() const;
        virtual void pause();
        virtual void resume();

        bool isLost() const;
        void lose();

        bool isWon() const;
        void win();

        bool isNotRunning() const;

        bool hasTransition() const;
        void doTransition(Stack& stack);

        virtual void update(sf::Time deltaTime) = 0;

        virtual void draw(sf::RenderTarget& target) const = 0;

    protected:
        Stack& getStack();
        void pop();
        void push(std::unique_ptr<State> state);
        void change(std::unique_ptr<State> state);

        const Assets& m_assets;

    private:
        void setTransition(std::unique_ptr<Transition> transition);

        Stack& m_stack;
        std::unique_ptr<Transition> m_transition;
        LevelStates levelState = LevelStates::RUN;
};

#endif
