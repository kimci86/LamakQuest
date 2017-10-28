#include "state/Transition.hpp"

Transition::~Transition()
{}

void Pop::apply(State::Stack& stack)
{
    stack.pop();
}

Push::Push(std::unique_ptr<State> state)
 : m_state(std::move(state))
{}

void Push::apply(State::Stack& stack)
{
    stack.push(std::move(m_state));
}

Change::Change(std::unique_ptr<State> state)
 : m_state(std::move(state))
{}

void Change::apply(State::Stack& stack)
{
    stack.pop();
    stack.push(std::move(m_state));
}
