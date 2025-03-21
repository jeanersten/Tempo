#pragma once

#include "Components.h"

#include <cstddef>
#include <memory>
#include <string>


class Entity
{
friend class EntityManager;

private:
  Entity(size_t id, const std::string& tag = "Undefined");

  bool active {};

  size_t id {};
  std::string tag {};

public:
  std::shared_ptr<CTransform> ctransform {};
  std::shared_ptr<CShape> cshape {};
  std::shared_ptr<CCollider> ccollider {};
  std::shared_ptr<CLifeSpan> clife_span {};
  std::shared_ptr<CInput> cinput {};
  std::shared_ptr<CScore> cscore {};

  bool isActive() const;

  size_t getID() const;
  const std::string& getTag() const;

  void destroy();
};
