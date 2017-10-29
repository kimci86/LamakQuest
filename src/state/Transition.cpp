#include "state/Transition.hpp"

Transition::~Transition()
{}

Pop::pop(int depth)
 : m_depth(depth)
{}

void Pop::apply(State::Stack& stack)
{
    if(int i = ; i < m_depth; i++)
        stack.pop();
}

Push::Push(std::unique_ptr<State> state)
 : m_state(std::move(state))
{}

void Push::apply(State::Stack& stack)
{
    stack.push(std::move(m_state));
}
