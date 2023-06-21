#include "World.h"
#include "Snake.h"

World::World(sf::Vector2u l_windSize) {
	m_blockSize = 20;
	m_windowSize = l_windSize;

	m_length = sizeof(fruitArr) / sizeof(int);

	for (size_t i = 0; i < m_length; i++) {
		fruitArr->SpawnFruit(m_windowSize.x, m_windowSize.y, m_blockSize, fruitArr[i]);
	}
	
	for (int i = 0; i < 4; ++i) {
		m_bounds[i].setFillColor(sf::Color(sf::Color::White));
		if (!((i + 1) % 2)) {
			m_bounds[i].setSize(sf::Vector2f(m_windowSize.x,
				m_blockSize));
		}
		else {
			m_bounds[i].setSize(sf::Vector2f(m_blockSize,
				m_windowSize.y));
		}
		if (i < 2) {
			m_bounds[i].setPosition(0, 0);
		}
		else {
			m_bounds[i].setOrigin(m_bounds[i].getSize());
			m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
		}

	}
}

World::~World() {}

void World::Update(Snake& l_player)
{
	if (l_player.GetPosition() == fruitArr->GetPosition()) 
	{
		l_player.ExtendSnake();
		l_player.IncrementScore();

		for (size_t i = 0; i < m_length; i++) 
		{
			fruitArr->SpawnFruit(m_windowSize.x, m_windowSize.y, m_blockSize, fruitArr[i]);
		}

		int gridSixeX = m_windowSize.x / m_blockSize;
		int gridSixeY = m_windowSize.y / m_blockSize;

		if (l_player.GetPosition().x <= 0 ||
			l_player.GetPosition().y <= 0 ||
			l_player.GetPosition().x >=gridSixeX-1 ||
			l_player.GetPosition().y >= gridSixeY -1) 
		{
			l_player.Lose();
		}

	}
}

void World::Render(sf::RenderWindow& l_window)
{
	for (int i = 0; i < 4; ++i) {
		l_window.draw(m_bounds[i]);
	}
	//l_window.draw(m_appleShape);
}
