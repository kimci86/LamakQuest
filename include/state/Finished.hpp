#ifndef FINISHED_HHPP
#define FINISHED_HHPP

#include "state/State.hpp"
#include "gui/Button.hpp"

class Finished : public State
{
    public:
        Finished(Stack& stack, const Assets& assets);

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        sf::Text m_text;
        Button m_button;
        sf::Sound m_sound;
        sf::Time m_time;
};

#endif
