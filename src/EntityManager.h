#pragma once

#include "Entity.h"
#include <memory>
#include <vector>


typedef std::vector<std::shared_ptr<Entity>> EntityList;

class EntityManager
{
private:
  EntityList entities {};
  EntityList entities_to_add {};

public:
  void update();

  std::shared_ptr<Entity> makeEntity();

  EntityList& getEntities();
};
