#include "entity/Ball.hpp"
#include "util.hpp"

Ball::Ball(float radius)
 : Circle(radius)
{

}

void Ball::update(sf::Time deltaTime)
{
    move(m_velocity*deltaTime.asSeconds());
}

void Ball::launch(const sf::Vector2f& position)
{
    m_velocity = (getPosition() - position) * 1.5f;
}

bool Ball::intersects(const Wall& wall, sf::Vector2f& hitPoint, sf::Vector2f& normal) const
{
    const sf::Vector2f& p = getPosition();
    const sf::Vector2f& p1 = wall.getPoint1();
    const sf::Vector2f& p2 = wall.getPoint2();
    float r = getRadius();
    float r2 = r * r;

    sf::Vector2f u = p2 - p1;
    float u2 = squaredLength(u);
    float r_over_u = r / length(u);

    sf::Vector2f v = turned(u) * r_over_u;
    float v2 = squaredLength(v);

    sf::Vector2f local = p - p1;

    float a = dot(v, local) / v2;
    float b = dot(u, local) / u2;
    if(a < - 1.f || 1.f < a || b < - r_over_u || 1.f + r_over_u < b)
        return false;

    if(dot(v, m_velocity) > 0.f)
    {
        a = -a;
        v = -v;
    }
    float orientation = det(u, v) >= 0.f ? 1.f : -1.f;

    float c = orientation * det(m_velocity, local);
    float c1 = orientation * det(m_velocity, v);
    float c2 = orientation * det(m_velocity, u + v);

    if(c < c1)
    {
        if(squaredLength(local) <= r2)
        {
            circleLineIntersection(p1, r, p, m_velocity, hitPoint);
            normal = hitPoint - p1;
            return true;
        }
        else
            return false;
    }
    else if(c <= c2)
    {
        if(0.f <= b && b <= 1.f || squaredLength(local) <= r2 || squaredLength(p - p2) <= r2)
        {
            normal = v;
            hitPoint = p1 + v + u * (c - c1) / (c2 - c1);
            return true;
        }
        else
            return false;
    }
    else
    {
        if(squaredLength(p - p2) <= r2)
        {
            circleLineIntersection(p2, r, p, m_velocity, hitPoint);
            normal = hitPoint - p2;
            return true;
        }
        else
            return false;
    }
}

void Ball::bounce(const sf::Vector2f& hitPoint, const sf::Vector2f& normal)
{
    setPosition(hitPoint + reflection(getPosition() - hitPoint, normal));
    m_velocity = reflection(m_velocity, normal) * 0.95f;
}

const sf::Vector2f& Ball::getVelocity() const
{
    return m_velocity;
}

void Ball::setVelocity(const sf::Vector2f& velocity)
{
    m_velocity = velocity;
}

void Ball::applyFriction(float friction)
{
    m_velocity = m_velocity * friction;
}
