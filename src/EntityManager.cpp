#include "EntityManager.h"

#include <memory>

EntityManager::EntityManager()
{}

void EntityManager::removeInactiveEntities(EntityList& entity_list)
{
  for (auto it = entity_list.begin(); it != entity_list.end();)
  {
    if (!(*it)->isActive())
    {
      it = entity_list.erase(it);
    }
    else
    {
      ++it;
    }
  }
}

std::shared_ptr<Entity> EntityManager::makeEntity(const std::string& tag)
{
  auto entity = std::shared_ptr<Entity>(new Entity(total_entities++, tag));
  entities_to_add.push_back(entity);
  return entity;
}

void EntityManager::update()
{
  removeInactiveEntities(entity_list);
  for (auto [tag, entities] : entities_map)
  {
    removeInactiveEntities(entities);
  }

  for (auto entity : entities_to_add)
  {
    entity_list.push_back(entity);
    entities_map[entity->getTag()].push_back(entity);
  }
  entities_to_add.clear();
}


const EntityList& EntityManager::getEntities()
{
  return entity_list;
}

const EntityList& EntityManager::getEntities(const std::string& tag)
{
  return entities_map[tag];
}
