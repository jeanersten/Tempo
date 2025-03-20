#include "Components.h"


CTransform::CTransform(sf::Vector2f position)
  : position(position)
{}

CShape::CShape(float radius, const sf::Color& color)
  : visual(radius)
{
  visual.setOrigin(radius, radius);
  visual.setFillColor(color);
}

CInput::CInput()
{}
