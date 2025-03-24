#pragma once

#include "Entity.h"

#include <map>
#include <string>
#include <vector>

typedef std::vector<std::shared_ptr<Entity>> EntityList;
typedef std::map<std::string, EntityList> EntityMap;

class EntityManager
{
private:
  EntityList entity_list {};
  EntityList entities_to_add {};
  EntityMap entities_map {};

  size_t total_entities {};

  void removeInactiveEntities(EntityList& entity_list);

public:
  EntityManager();

  std::shared_ptr<Entity> makeEntity(const std::string& tag);

  void update();

  const EntityList& getEntities();
  const EntityList& getEntities(const std::string& tag);
};

