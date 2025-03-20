#include "EntityManager.h"
#include "Entity.h"
#include <memory>

void EntityManager::update()
{
  for (auto it = entities.begin(); it != entities.end();)
  {
    if (!(*it)->isActive())
    {
      it = entities.erase(it);
    }
    else
    {
      ++it;
    }
  }

  for (auto entity : entities_to_add)
  {
    entities.push_back(entity);
  }
  entities_to_add.clear();
}

std::shared_ptr<Entity> EntityManager::makeEntity()
{
  auto entity = std::make_shared<Entity>();
  entities_to_add.push_back(entity);
  return entity;
}

EntityList& EntityManager::getEntities()
{
  return entities;
}
