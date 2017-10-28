#ifndef UTIL_HPP
#define UTIL_HPP

#include <SFML/System.hpp>

float det(const sf::Vector2f& u, const sf::Vector2f& v);

float dot(const sf::Vector2f& u, const sf::Vector2f& v);

float squaredLength(const sf::Vector2f& u);

float length(const sf::Vector2f& u);

sf::Vector2f normalized(const sf::Vector2f& u);

sf::Vector2f turned(const sf::Vector2f& u);

sf::Vector2f reflection(const sf::Vector2f& u, const sf::Vector2f& normal);

bool circleLineIntersection(const sf::Vector2f& center, float radius, const sf::Vector2f& point, const sf::Vector2f& direction, sf::Vector2f& intersection);

#endif
