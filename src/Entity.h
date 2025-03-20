#pragma once

#include "Components.h"

#include <memory>

class Entity
{
private:
  bool active {};

public:
  Entity();

  std::shared_ptr<CTransform> c_transform;
  std::shared_ptr<CShape> c_shape;

  bool isActive();

  void destroy();
};
