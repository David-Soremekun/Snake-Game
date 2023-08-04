#include "Snake.h"



Snake::Snake(const int sizeOfSnake)
{
	m_size = sizeOfSnake;
	m_snakeBodyShape.setRadius(m_size - 1);

	ResetSnake();
}

Snake::~Snake() {}

void Snake::CheckCollision()
{
	if (m_segmentVector.size() < 5) { return; }
	SnakeSegment& head = m_segmentVector.front();
	for (auto itr = m_segmentVector.begin() + 1;
		itr != m_segmentVector.end(); ++itr) {
		if (itr->position == head.position) {
			int segments = m_segmentVector.end() - itr;
			CutSnake(segments);
			break;
		}
	}
}



const sf::Vector2f Snake::GetPosition() const
{
	return sf::Vector2f(!m_segmentVector.empty() ? 
		m_segmentVector.front().position : sf::Vector2f(1, 1));
}

void Snake::CutSnake(int segmentNum)
{
	for (int i = 0; i < segmentNum; ++i) 
	{
		m_segmentVector.pop_back();
	}
	--m_lives;
	if (m_lives) { 
		
		Lose(); 
		return; 
	}
}

void Snake::ExtendSnake()
{
	if (m_segmentVector.empty()){ return; }

	SnakeSegment& tail_head =
		m_segmentVector[m_segmentVector.size() - 1];

	if (m_segmentVector.size() > 1) {
		SnakeSegment& tail_bone =
			m_segmentVector[m_segmentVector.size() - 2];
		if (tail_head.position.x == tail_bone.position.x){

			if (tail_head.position.y > tail_bone.position.y)
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y + 1));
			}
			else
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y - 1));
			}
		}
		else if (tail_head.position.y == tail_bone.position.y) {
			
			if (tail_head.position.x > tail_bone.position.x) 
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x + 1, tail_head.position.y));
			}
			else 
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x - 1, tail_head.position.y));
			}
		}
		else {
			
			if (m_dir == Direction::eUpward) 
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y + 1));
			}
			else if (m_dir == Direction::eDownward) 
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y - 1));
			}
			else if (m_dir == Direction::eLeft) 
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x + 1, tail_head.position.y));
			}
			else if (m_dir == Direction::eRight) 
			{
				m_segmentVector.push_back(SnakeSegment(
					tail_head.position.x - 1, tail_head.position.y));
			}
		}
	}

	
}

void Snake::ResetSnake()
{
	m_segmentVector.clear();
	m_dir = Direction::eNone;

	m_segmentVector.push_back(SnakeSegment(5, 7));
	m_segmentVector.push_back(SnakeSegment(5, 6));
	m_segmentVector.push_back(SnakeSegment(5, 5));
	m_segmentVector.push_back(SnakeSegment(5, 4));

    m_lives = 3;
	m_score = 0;
	m_speed = 7.5f;
	
	m_lost = false;
	

}

void Snake::Move()
{
	for (int i = m_segmentVector.size() - 1; i > 0; --i) {
		m_segmentVector[i].position = m_segmentVector[i - 1].position;
	}
	if (m_dir == Direction::eLeft) 
	{
		--m_segmentVector[0].position.x;
	}
	else if (m_dir == Direction::eRight) 
	{
		++m_segmentVector[0].position.x;
	}
	else if (m_dir == Direction::eUpward) 
	{
		--m_segmentVector[0].position.y;
	}
	else if (m_dir == Direction::eDownward) 
	{
		++m_segmentVector[0].position.y;
	}
}

void Snake::Tick()
{
	if (m_segmentVector.empty()) { return; }
	if (m_dir == Direction::eNone) { return; }
	Move();
	CheckCollision();
}

void Snake::Render(sf::RenderWindow& m_window)
{
	if (m_segmentVector.empty()) { return; }
	
	auto head = m_segmentVector.begin();
	
	m_snakeBodyShape.setFillColor(sf::Color::Yellow);
	m_snakeBodyShape.setPosition(head->position.x * m_size,
		head->position.y * m_size);

	m_window.draw(m_snakeBodyShape);

	m_snakeBodyShape.setFillColor(sf::Color::Green);
	
	for (auto itr = m_segmentVector.begin() + 1;
		itr != m_segmentVector.end(); ++itr)
	{
		m_snakeBodyShape.setPosition(itr->position.x * m_size,
			itr->position.y * m_size);
		m_window.draw(m_snakeBodyShape);
	}
	



}
