#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <string>

struct WindowConfig
{
  int width {}, height {};
  int fps {};
  bool full_screen {};
};

struct FontConfig
{
  const char* font_path {};
  int size {};
  int red {}, green {}, blue {}; 
};

struct PlayerConfig
{
  int shape_radius {};
  int collision_radius {};
  int fill_red {}, fill_green {}, fill_blue {};
  int outline_red {}, outline_green {}, outline_blue {};
  int points {};
  float speed {};
};

struct EnemyConfig
{
  int shape_radius {};
  int collision_radius {};
  int fill_red {}, fill_green {}, fill_blue {};
  int outline_red {}, outline_green {}, outline_blue {};
  int min_points, max_points {};
  float min_speed {}, max_speed {};

  int small_enemies_life_span;
  int spawn_interval;
};

struct BulletConfig
{
  int shape_radius {};
  int collision_radius {};
  int fill_red {}, fill_green {}, fill_blue {};
  int outline_red {}, outline_green {}, outline_blue {};
  int points {};
  int life_span {};
  float speed {};
};

class Game
{
private:
  sf::RenderWindow window {};

  EntityManager entity_manager {};

  WindowConfig window_config {};
  FontConfig font_config {};
  PlayerConfig player_config {};
  EnemyConfig enemy_config {};
  BulletConfig bullet_config {};

  int score {};
  sf::Font score_font {};
  sf::Text score_text {};

  int current_frame {};

  int last_enemy_spawn_time {};

  bool running {};
  bool paused {};

  std::shared_ptr<Entity> player {};

  void init(const std::string& config_path);
  void update();

  void setPaused(bool paused);

  void spawnPlayer();
  void spawnBullet(std::shared_ptr<Entity> player, sf::Vector2f mouse_pos);
  void spawnUltimate(std::shared_ptr<Entity> player);
  void spawnEnemy();
  void spawnSmallEnemies(std::shared_ptr<Entity> enemy);

  void handleUserInput();
  void handleMovement();
  void handleLifeSpan();
  void handleEnemySpawner();
  void handleCollision();
  void handleRendering();

public:
  Game(const std::string& config_path);

  void run();
};
