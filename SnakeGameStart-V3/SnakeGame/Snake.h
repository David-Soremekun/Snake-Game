#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Direction.h"
class Snake
{
private:
	sf::CircleShape m_snakeBodyShape;
	//std::list<sf::Vector2f> m_snakeSegments;
	std::vector<int,int> m_segmentVector;
	Direction m_dir;
	bool m_lost;

	//int m_headSize;
	int m_lives;
	int m_score;

	float m_size;
	float m_speed;
	void CheckCollision();

public:
	Snake(int sizeOfSnake);
	~Snake();
	
	void SetDirection(Direction dir) { m_dir = dir; }
	const Direction GetDirection() const { return m_dir; }
	const float GetSpeed() const { return m_speed; }

	const int GetLive() const { return m_lives; }
	const int GetScore() const { return m_score; }
	const bool HasLost() const { return m_lost; }
	
	void IncrementScore() { m_score += 10; }

	void ExtendSnake();
	void ResetSnake();

	void Move();
	void Tick();
	void Render(sf::RenderWindow& m_window);
};

