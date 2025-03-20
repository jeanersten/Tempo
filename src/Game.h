#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>

class Game
{
private:
  bool running {};

  sf::RenderWindow window {};
  EntityManager entity_manager {};
  std::shared_ptr<Entity> player {};
  std::shared_ptr<Entity> enemy {};

  void init();
  void update();

  void handleInput();
  void handleRendering();

public:
  Game();

  void run();
};
