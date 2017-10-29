#include "state/Finished.hpp"
#include <cmath>

Finished::Finished(Stack& stack, const Assets& assets)
 : State(stack, assets), m_text("Well done!", assets.font, 50.f), m_button(300.f, "Back to map", assets.font)
{
    m_button.setPosition({362, 384});
    m_text.setOrigin(sf::Vector2f(m_text.getLocalBounds().width, m_text.getCharacterSize()) / 2.f);
    m_text.setPosition({512, 200});
}

void Finished::mouseMoved(const sf::Vector2f& position)
{
    m_button.changeColor(position);
}

void Finished::mouseReleased(const sf::Vector2f& position)
{
    if(m_button.inButton(position))
        pop(2);
}

void Finished::update(sf::Time deltaTime)
{
    m_time += deltaTime;
    if(m_time < sf::seconds(3.f))
        m_text.setScale(sf::Vector2f(1.f, 1.f) * (1.f + std::sin(m_time.asSeconds() * 15.f) / 2.f * std::exp(-m_time.asSeconds()*m_time.asSeconds())));
}

void Finished::draw(sf::RenderTarget& target) const
{
    target.draw(m_text);
    target.draw(m_button);
}
