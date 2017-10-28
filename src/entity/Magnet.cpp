#include "entity/Magnet.hpp"
#include "util.hpp"

Magnet::Magnet(float radius, int count, float intensity, const sf::Color& color)
 : m_intensity(intensity),
   m_accelMax(2000.f * intensity),
   m_duration(sf::seconds(4.f * std::abs(1.f / intensity))),
   m_radius(radius),
   m_count(count),
   m_color(color),
   m_circles(count, sf::CircleShape(radius))
{

}

void Magnet::update(sf::Time deltaTime)
{
    m_time += deltaTime;
    m_time %= m_duration;
    sf::Time offset = m_duration / static_cast<float>(m_count);
    for(int i = 0; i < m_count; i++)
    {
        float t = (m_time + static_cast<float>(i)*offset) % m_duration / m_duration;
        if(m_intensity < 0.f)
            t = 1.f - t;
        m_circles[i].setRadius((1.f - t) * m_radius);
        m_circles[i].setOrigin(m_circles[i].getRadius(), m_circles[i].getRadius());
        m_circles[i].setFillColor(m_color * sf::Color(255, 255, 255, 255 * t));
    }
}

void Magnet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    for(int i = 0; i < m_count; i++)
        target.draw(m_circles[i], states);
}

void Magnet::interact(Ball& ball, sf::Time deltaTime)
{
    sf::Vector2f u = getPosition() - ball.getPosition();
    float d = length(u);
    if(d < m_radius)
    {
        float r = m_radius / m_count;
        float x = d / m_radius + 1.f;
        float accel = m_accelMax / x / x;
        ball.setVelocity((ball.getVelocity() + u / d * accel * deltaTime.asSeconds()));
    }
}
