#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

struct CTransform
{
  sf::Vector2f position {};

  CTransform(sf::Vector2f position);
};

struct CShape
{
  sf::CircleShape visual {};

  CShape(float radius, const sf::Color& color);
};
