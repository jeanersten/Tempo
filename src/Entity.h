#pragma once

#include "Components.h"

#include <memory>

class Entity
{
public:
  std::shared_ptr<CTransform> c_transform;
  std::shared_ptr<CShape> c_shape;
};
