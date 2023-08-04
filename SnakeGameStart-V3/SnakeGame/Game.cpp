#include "Game.h"
#include "Snake.h"
#include "World.h"
#include "Direction.h"
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

Game::Game()
{
	m_window.create(sf::VideoMode(m_screenWidth, m_screenHeight), "SFML Snake Game");
	m_world = new World(sf::Vector2u(m_screenWidth, m_screenHeight));
	m_snake = (m_world->GetBlockSize());
}

void Game::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.GetDirection() != Direction::eDownward)
	{
		m_snake.SetDirection(Direction::eUpward);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.GetDirection() != Direction::eUpward)
	{
		m_snake.SetDirection(Direction::eDownward);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.GetDirection() != Direction::eRight)
	{
		m_snake.SetDirection(Direction::eLeft);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.GetDirection() != Direction::eLeft)
	{
		m_snake.SetDirection(Direction::eRight);
	}
	float timestep = 1.0f / m_snake.GetSpeed();
	
	if (m_elapsed >= timestep) {
		m_snake.Tick();
		m_world->Update(m_snake);
		m_elapsed -= timestep;
		if (m_snake.HasLost()) {
			m_snake.ResetSnake();
		}
	}


}
