#include "util.hpp"
#include <cmath>

float det(const sf::Vector2f& u, const sf::Vector2f& v)
{
    return u.x * v.y - u.y * v.x;
}

float dot(const sf::Vector2f& u, const sf::Vector2f& v)
{
    return u.x * v.x + u.y * v.y;
}

float squaredLength(const sf::Vector2f& u)
{
    return dot(u, u);
}

float length(const sf::Vector2f& u)
{
    return std::sqrt(squaredLength(u));
}

sf::Vector2f normalized(const sf::Vector2f& u)
{
    return u / length(u);
}

sf::Vector2f turned(const sf::Vector2f& u)
{
    return sf::Vector2f(-u.y, u.x);
}

sf::Vector2f reflection(const sf::Vector2f& u, const sf::Vector2f& normal)
{
    return u - normal * 2.f * dot(u, normal) / squaredLength(normal);
}

bool circleLineIntersection(const sf::Vector2f& center, float radius, const sf::Vector2f& point, const sf::Vector2f& direction, sf::Vector2f& intersection)
{
    sf::Vector2f p = point - center;
    float a = squaredLength(direction),
          b = 2.f * dot(direction, p),
          c = squaredLength(p) - radius * radius;
    float delta = b * b - 4.f * a * c;

    if(delta >= 0.f)
    {
        float alpha = - (b + std::sqrt(delta)) / 2.f / a;
        intersection = point + direction * alpha;
        return true;
    }
    else
        return false;
}
