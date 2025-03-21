#include "Entity.h"

#include <cstddef>
#include <string>

Entity::Entity(size_t id, const std::string& tag)
  : active(true)
  , id(id)
  , tag(tag)
{}

bool Entity::isActive() const
{
  return active;
}

size_t Entity::getID() const
{
  return id;
}

const std::string& Entity::getTag() const
{
  return tag;
}

void Entity::destroy()
{
  active = false;
}
