#include "Entity.h"

Entity::Entity()
  : active(true)
{}

bool Entity::isActive()
{
  return active;
}

void Entity::destroy()
{
  active = false;
}
