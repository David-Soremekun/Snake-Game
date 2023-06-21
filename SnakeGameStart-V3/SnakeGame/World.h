#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"
class Snake;

class World
{
private:
	sf::Vector2u m_windowSize;
	sf::Vector2i m_item;
	int m_blockSize;
	
	sf::RectangleShape m_bounds[4];
	Food fruitArr[6];
	size_t m_length;
public:
	World(sf::Vector2u l_windSize);
	~World();
	const int GetBlockSize() const { return m_blockSize; }
	
	void Update(Snake& l_player);
	void Render(sf::RenderWindow& l_window);



};

