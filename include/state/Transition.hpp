#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include "state/State.hpp"

class Transition
{
    public:
        virtual ~Transition();

        virtual void apply(State::Stack& stack) = 0;
};

class Pop : public Transition
{
    public:
        Pop(int depth);

        virtual void apply(State::Stack& stack);

    private:
        int m_depth;
};

class Push : public Transition
{
    public:
        Push(std::unique_ptr<State> state);

        virtual void apply(State::Stack& stack);

    private:
        std::unique_ptr<State> m_state;
};

#endif
