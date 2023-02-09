#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Direction.h"

class SnakeHead
{
private:

	sf::Vector2f snakePosition;
	sf::Color snakeCol;
	std::list<sf::Vector2f> segments;
	int s_growAmount{ 4 };
	float headSize{ 20.f };

	/*int x, y;
	int breathLevel;
	int score;*/

public:
	SnakeHead(sf::Vector2f snakePosition, sf::Color snakeCol);
	sf::Vector2f getPosition();

	void Update();
	void Move();
	void Reset();
	void Render(sf::RenderWindow& window);
	void addSegment();

	

	Direction direction = Direction::East;
	bool CheckCollision();
	bool CheckWallCollision();
	bool CheckPosition(sf::Vector2f positionComapare);
	bool DoYouCoverPlace(sf::Vector2f pos) const;


};