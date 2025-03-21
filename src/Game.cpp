#include "Game.h"
#include "Components.h"
#include "EntityManager.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

#include <ctime>
#include <memory>

Game::Game(const std::string& config_path)
  : running(true)
{
  init(config_path);
}

void Game::init(const std::string& config_path)
{
  window.create(sf::VideoMode{640u, 480u}, "Tempo Engine v1.0");
  window.setFramerateLimit(60u);

  spawnPlayer();
  spawnEnemy();
}

void Game::update()
{
  handleUserInput();
  handleMovement();
  handleLifeSpan();
  handleEnemySpawner();
  handleCollision();
  handleRendering();
}

void Game::spawnPlayer()
{
  auto entity = entity_manager.makeEntity("Player");
  entity->cshape = std::make_shared<CShape>(25.0f, 8, sf::Color::Transparent, sf::Color::Blue);
  entity->ctransform = std::make_shared<CTransform>(sf::Vector2f {320.0f, 240.0f}, sf::Vector2f {0.0f, 0.0f}, 0.0f);
  player = entity;
}

void Game::spawnEnemy()
{

  auto entity  = entity_manager.makeEntity("Enemy");
  entity->cshape = std::make_shared<CShape>(25.0f, 4, sf::Color::Transparent, sf::Color::Red);
  entity->ctransform = std::make_shared<CTransform>(sf::Vector2f {220.0f, 140.0f}, sf::Vector2f {0.0f, 0.0f}, 0.0f);
}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> enemy)
{}

void Game::shoot(std::shared_ptr<Entity> player, sf::Vector2f mouse_pos)
{}

void Game::ultimate(std::shared_ptr<Entity> player)
{}

void Game::handleUserInput()
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      running = false;
    }
  }
}

void Game::handleMovement()
{}

void Game::handleLifeSpan()
{}

void Game::handleEnemySpawner()
{}

void Game::handleCollision()
{}

void Game::handleRendering()
{
  window.clear();
  for (auto entity : entity_manager.getEntities())
  {
    if (entity->cshape != nullptr && entity->ctransform != nullptr)
    {
      entity->cshape->visual.setPosition(entity->ctransform->position);
      entity->cshape->visual.setRotation(entity->ctransform->angle++);

      window.draw(entity->cshape->visual);
    }
  }
  window.display();
}

void Game::run()
{
  while (running)
  {
    entity_manager.update();
    update();
    current_frame++;
  }

  window.close();
}
