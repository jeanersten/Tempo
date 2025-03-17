#include "Game.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

Game::Game()
{
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
  sf::Event event {};
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      running = false;
    }
  }
}

void Game::render()
{
  window.clear();
  window.display();
}

void Game::run()
{
  while (running)
  {
    update();
    render();
  }

  window.close();
}
