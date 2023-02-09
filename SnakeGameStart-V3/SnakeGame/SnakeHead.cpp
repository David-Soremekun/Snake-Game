#include "SnakeHead.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Direction.h"

void SnakeHead::Update()
{
	Move();
	segments.push_front(sf::Vector2f(snakePosition));
	if (s_growAmount > 0)
	{
		s_growAmount--;
	}
	else
	{
		segments.pop_back();
	}
}


bool SnakeHead::DoYouCoverPlace(sf::Vector2f pos) const
{
	for(const sf::Vector2f& p: segments){
		if (p==pos)
		{
			return true;
		}
	}
	return false;
}


void SnakeHead::Render(sf::RenderWindow& window)
{
	sf::CircleShape SnakeHead(headSize);
	SnakeHead.setFillColor(snakeCol);
	//SnakeHead.setRadius(rad);
	for (auto& segment: segments)
	{
		SnakeHead.setPosition(segment);
		window.draw(SnakeHead);
	}
}


void SnakeHead::addSegment()
{
	
	s_growAmount++;

}


sf::Vector2f SnakeHead::getPosition()
{
	return segments.front();
}


SnakeHead::SnakeHead(sf::Vector2f snakePosition_, sf::Color snakeCol_):
	snakePosition(snakePosition_),
	//rad(rad_),
	snakeCol(snakeCol_)
{
	

}



bool SnakeHead::CheckCollision()
{
	bool isFirst = true;
	for (auto& s : segments)
	{
		if (isFirst)
		{
			isFirst = false;
			continue;
		}
		if (s == snakePosition) {
			return true;
		}
		
	}
	return false;
}



bool SnakeHead::CheckWallCollision()
{
	return (snakePosition.x == 0 || snakePosition.x == 800 || snakePosition.y == 0
		|| snakePosition.y == 560);
}



bool SnakeHead::CheckPosition(sf::Vector2f positionComapare )
{
	for (auto& s : segments)
	{
		
		if (s == getPosition()) {
			return false;
		}
	}
	return true;
}



void SnakeHead::Move()
{
	switch (direction)
	{
	case Direction::North:
		snakePosition += sf::Vector2f(0, -2 * headSize);
		break;
	case Direction::South:
		snakePosition += sf::Vector2f(0, 2 * headSize);
		break;
	case Direction::East:
		snakePosition += sf::Vector2f(2 * headSize, 0);
		break;
	case Direction::West:
		snakePosition += sf::Vector2f(-2 * headSize, 0);
		break;
	default:
		break;
	}
}



void SnakeHead::Reset()
{
	snakePosition.x = 400;
	snakePosition.y = 400;
	for (int i = 1; i < segments.size(); i++) {
		segments.pop_back();
	}
}


