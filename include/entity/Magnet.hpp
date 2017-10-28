#ifndef MAGNET_HPP
#define MAGNET_HPP

#include "entity/Entity.hpp"
#include "entity/Ball.hpp"

class Magnet : public Entity
{
    public:
        Magnet(float radius = 100.f, int count = 4, float intensity = 1.f, const sf::Color& color = sf::Color::Black);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void interact(Ball& ball, sf::Time frameTime);

    private:
        float m_intensity;
        float m_accelMax;
        sf::Time m_duration;
        float m_radius;
        int m_count;
        sf::Color m_color;
        sf::Time m_time;
        std::vector<sf::CircleShape> m_circles;
};

#endif
