#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Assets.hpp"

class Transition;

class State
{
    public:
        using Stack = std::stack<std::unique_ptr<State>>;

        State(Stack& stack, const Assets& assets);
        virtual ~State();

        bool hasTransition() const;
        void doTransition();

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mousePressed(const sf::Vector2f& position);
        virtual void mouseDragged(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);
        virtual void keyPressed(sf::Keyboard::Key key);
        virtual void lostFocus();

        virtual void update(sf::Time deltaTime) = 0;

        virtual void draw(sf::RenderTarget& target) const = 0;

    protected:
        Stack& getStack();
        void pop(int depth = 1);
        void push(std::unique_ptr<State> state);

        const Assets& m_assets;

    private:
        void setTransition(std::unique_ptr<Transition> transition);

        Stack& m_stack;
        std::unique_ptr<Transition> m_transition;
};

#endif
