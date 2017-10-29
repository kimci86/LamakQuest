#include "state/State.hpp"
#include "state/Transition.hpp"

State::State(Stack& stack, const Assets& assets)
 : m_stack(stack), m_assets(assets)
{}

State::~State()
{}

bool State::hasTransition() const
{
    return bool(m_transition);
}

void State::doTransition()
{
    m_transition->apply(getStack());
    m_transition.reset();
}

void State::mouseMoved(const sf::Vector2f& position)
{}

void State::mousePressed(const sf::Vector2f& position)
{}

void State::mouseDragged(const sf::Vector2f& position)
{}

void State::mouseReleased(const sf::Vector2f& position)
{}

void State::keyPressed(sf::Keyboard::Key key)
{}

void State::lostFocus()
{}

State::Stack& State::getStack()
{
    return m_stack;
}

void State::pop(int depth)
{
    setTransition(std::unique_ptr<Transition>(new Pop(depth)));
}

void State::push(std::unique_ptr<State> state)
{
    setTransition(std::unique_ptr<Transition>(new Push(std::move(state))));
}

void State::setTransition(std::unique_ptr<Transition> transition)
{
    m_transition = std::move(transition);
}
