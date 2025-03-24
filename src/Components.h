#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct CTransform
{
  sf::Vector2f position {};
  float speed {};
  float angle {};

  CTransform(sf::Vector2f position, float speed, float angle);
};

struct CShape
{
  sf::CircleShape visual {};

  CShape(float radius, int points,
         const sf::Color& fill_color,
         const sf::Color& outline_color);
};

struct CCollider
{
  float radius {};

  CCollider(float radius);
};

struct CLifeSpan
{
  int total {};
  int remaining {};

  CLifeSpan(int total, int remaining);
};

struct CInput
{
  bool left {};
  bool right {};
  bool up {};
  bool down {};

  bool shoot {};

  CInput();
};

struct CScore
{
  int count {};

  CScore(int count);
};
