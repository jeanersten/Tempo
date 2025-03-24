#include "Components.h"
#include "Game.h"
#include "Utils.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>
#include <string>

Game::Game(const std::string& config_path)
  : running(true)
{
  init(config_path);
}

void Game::init(const std::string& config_path)
{
  sf::VideoMode desktop_mode = sf::VideoMode::getDesktopMode();
  window.create(desktop_mode, "Tempo Engine v1.0");
  window.setFramerateLimit(60u);

  spawnPlayer();
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
  entity->cshape = std::make_shared<CShape>(25.0f, 3, sf::Color::Transparent, sf::Color::White);
  entity->ctransform = std::make_shared<CTransform>(sf::Vector2f {320.0f, 240.0f}, 3.0f, 0.0f);
  entity->cinput = std::make_shared<CInput>();
  player = entity;
}

void Game::spawnBullet(std::shared_ptr<Entity> player, sf::Vector2f mouse_pos)
{
  auto entity = entity_manager.makeEntity("Bullet");
  entity->cshape = std::make_shared<CShape>(5.0f, 20, sf::Color::Transparent, sf::Color::White);
  entity->ctransform = std::make_shared<CTransform>(player->ctransform->position, 3.0f, 0.0);
}

void Game::spawnUltimate(std::shared_ptr<Entity> player)
{}

void Game::spawnEnemy()
{

  auto entity  = entity_manager.makeEntity("Enemy");
  entity->cshape = std::make_shared<CShape>(25.0f, 4, sf::Color::Transparent, sf::Color::Red);
  entity->ctransform = std::make_shared<CTransform>(sf::Vector2f {220.0f, 140.0f}, 3.0f, 0.0f);
}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> enemy)
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
    
    if (event.type == sf::Event::KeyPressed)
    {
      switch (event.key.code)
      {
        case sf::Keyboard::A:
        case sf::Keyboard::Left:
          player->cinput->left = true;
        break;

        case sf::Keyboard::D:
        case sf::Keyboard::Right:
          player->cinput->right = true;
        break;

        case sf::Keyboard::W:
        case sf::Keyboard::Up:
          player->cinput->up = true;
        break;

        case sf::Keyboard::S:
        case sf::Keyboard::Down:
          player->cinput->down = true;
        break;

        case sf::Keyboard::Space:
          player->cinput->shoot = true;
        break;

        default:
        break;
      }
    }

    if (event.type == sf::Event::KeyReleased)
    {
      switch (event.key.code)
      {
        case sf::Keyboard::A:
        case sf::Keyboard::Left:
          player->cinput->left = false;
        break;

        case sf::Keyboard::D:
        case sf::Keyboard::Right:
          player->cinput->right = false;
        break;

        case sf::Keyboard::W:
        case sf::Keyboard::Up:
          player->cinput->up = false;
        break;

        case sf::Keyboard::S:
        case sf::Keyboard::Down:
          player->cinput->down = false;
        break;

        case sf::Keyboard::Space:
          player->cinput->shoot = false;
        break;

        default:
        break;
      }
    }
  }
}

void Game::handleMovement()
{
  sf::Vector2f move {(float)player->cinput->right - (float)player->cinput->left,
                     (float)player->cinput->down - (float)player->cinput->up};
  player->ctransform->position += Utils::vecNormalizef(move) * player->ctransform->speed;

  if (player->cinput->shoot)
  {
    spawnBullet(player, sf::Vector2f{});
  }

  for (auto bullet : entity_manager.getEntities("Bullet"))
  {
    bullet->ctransform->position += sf::Vector2f{bullet->ctransform->speed, bullet->ctransform->speed};
  }
}

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
