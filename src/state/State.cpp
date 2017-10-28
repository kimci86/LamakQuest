#include "state/State.hpp"
#include "state/Transition.hpp"

State::State(Stack& stack, const Assets& assets)
 : m_stack(stack), m_assets(assets), levelState(LevelStates::RUN)
{}

State::~State()
{}

void State::mouseMoved(const sf::Vector2f& position)
{}

void State::mousePressed(const sf::Vector2f& position)
{}

void State::mouseDragged(const sf::Vector2f& position)
{}

void State::mouseReleased(const sf::Vector2f& position)
{}

void State::restart()
{}

bool State::isPaused() const
{
    return levelState == LevelStates::PAUSE;
}

void State::pause()
{
    levelState = LevelStates::PAUSE;
}

void State::resume()
{
    levelState = LevelStates::RUN;
}

bool State::isLost() const
{
    return levelState == LevelStates::LOST;
}

void State::lose()
{
    levelState = LevelStates::LOST;
}

bool State::isWon() const
{
    return levelState == LevelStates::WON;
}

void State::win()
{
    levelState = LevelStates::WON;
}

bool State::isNotRunning() const
{
    return levelState != LevelStates::RUN;
}

bool State::hasTransition() const
{
    return bool(m_transition);
}

void State::doTransition(Stack& stack)
{
    m_transition->apply(stack);
    m_transition.reset();
}

State::Stack& State::getStack()
{
    return m_stack;
}

void State::pop()
{
    setTransition(std::unique_ptr<Transition>(new Pop()));
}

void State::push(std::unique_ptr<State> state)
{
    setTransition(std::unique_ptr<Transition>(new Push(std::move(state))));
}

void State::change(std::unique_ptr<State> state)
{
    setTransition(std::unique_ptr<Transition>(new Change(std::move(state))));
}

void State::setTransition(std::unique_ptr<Transition> transition)
{
    m_transition = std::move(transition);
}

void State::nextLevel()
{}
