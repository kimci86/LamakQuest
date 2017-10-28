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
        virtual void apply(State::Stack& stack);
};

class Push : public Transition
{
    public:
        Push(std::unique_ptr<State> state);

        virtual void apply(State::Stack& stack);

    private:
        std::unique_ptr<State> m_state;
};

class Change : public Transition
{
    public:
        Change(std::unique_ptr<State> state);

        virtual void apply(State::Stack& stack);

    private:
        std::unique_ptr<State> m_state;
};

#endif
