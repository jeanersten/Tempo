#include "Utils.h"

#include <SFML/System.hpp>

namespace Utils
{
  sf::Vector2f vecNormalizef(sf::Vector2f other)
  {
    float magnitude = std::sqrt(other.x * other.x + other.y * other.y );
    if (magnitude < 1e-6f)
    {
      return sf::Vector2f {0.0f, 0.0f};
    }
    return other / magnitude;
  }
}
