#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
private:
  bool running {};

  sf::RenderWindow window {};

  void init();
  void update();
  void render();

public:
  Game();

  void run();
};
