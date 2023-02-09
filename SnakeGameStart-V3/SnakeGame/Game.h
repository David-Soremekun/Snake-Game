#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Food.h"
#include "SnakeHead.h"
#include "Breathe.h"
class SnakeHead;

class Game
{
private:
	
	int ScreenHeight = 800;
	int ScreenWidth = 600;
	sf::Vector2f m_waterDimension;
	std::vector<SnakeHead*> m_snakeVector;

	Food foodItems[6];
	sf::RectangleShape WallLeft;
	sf::RectangleShape WallRight;
	sf::RectangleShape WallBottom;
	


	void RandomlyAddFood();
	




public:
	
	bool isPlaceTaken(sf::Vector2f pos) const;
	sf::Vector2f findFreeSpace();
	void play();
	void render(sf::RenderWindow& window);
	void CreateWalls();
	Game();
	/*void gameFinish();*/
	
};

