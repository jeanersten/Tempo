#include "Components.h"
#include <SFML/System/Vector2.hpp>

CTransform::CTransform(sf::Vector2f position, sf::Vector2f speed, float angle)
  : position(position)
  , speed(speed)
  , angle(angle)
{}

CShape::CShape(float radius, int points,
               const sf::Color& fill_color,
               const sf::Color& outline_color)
  : visual(radius, points)
{
  visual.setOrigin(radius, radius);
  visual.setFillColor(fill_color);
  visual.setOutlineColor(outline_color);
  visual.setOutlineThickness(2.0f);
}

CCollider::CCollider(float radius)
  : radius(radius)
{}

CLifeSpan::CLifeSpan(int total, int remaining)
  : total(total)
  , remaining(remaining)
{}

CInput::CInput()
{}

CScore::CScore(int count)
  : count(count)
{}
