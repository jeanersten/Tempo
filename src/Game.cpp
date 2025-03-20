#include "Game.h"
#include "Components.h"
#include "EntityManager.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <memory>

Game::Game()
{
  player = entity_manager.makeEntity();
  player->c_transform = std::make_shared<CTransform>(sf::Vector2f{320.0f, 240.0f});
  player->c_shape = std::make_shared<CShape>(25.0f, sf::Color::Red);
  player->c_shape->visual.setPosition(player->c_transform->position);
  init();
}

void Game::init()
{
  running = true;
  window.create(sf::VideoMode{640u, 480u}, "Tempo Engine v0.1");
  window.setFramerateLimit(60u);
}

void Game::update()
{
  entity_manager.update();
  handleInput();
  handleRendering();
}

void Game::handleInput()
{
  sf::Event event {};
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      running = false;
    }

    if (event.type == sf::Event::KeyPressed)
    {
      if (event.key.code == sf::Keyboard::Space)
      {
        player->destroy();
      }
    }
  }
}

void Game::handleRendering()
{
  window.clear();

  for (auto& entity : entity_manager.getEntities())
  {
    if (entity->c_shape != nullptr)
    {
      window.draw(entity->c_shape->visual);
    }
  }

  window.display();
}

void Game::run()
{
  while (running)
  {
    update();
  }

  window.close();
}
