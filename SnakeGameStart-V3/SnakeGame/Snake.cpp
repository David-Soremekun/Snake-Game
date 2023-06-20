#include "Snake.h"

Snake::Snake(int sizeOfSnake)
{
	m_size = sizeOfSnake;
	m_snakeBodyShape.setRadius(m_size - 1);

	ResetSnake();
}

Snake::~Snake()
{
	
}

void Snake::ExtendSnake()
{
	if (m_segmentVector.empty())
	{
		return;
	}
	std::vector<int, int> &tail=m_segmentVector[m_segmentVector.size()-1];
}

void Snake::ResetSnake()
{
	m_segmentVector.clear();
	m_dir = Direction::eNone;

    m_lives = 3;
	m_score = 0;
	m_speed = 7.5f;
	
	m_lost = false;
	

}

void Snake::Render(sf::RenderWindow& m_window)
{
	m_snakeBodyShape.setFillColor(sf::Color::Blue);


}
