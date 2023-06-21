#include "Food.h"

Food::Food()
{
	orange.loadFromFile("Data/Sprites/Spr_Orange_Image.png");
	cherry.loadFromFile("Data/Sprites/Spr_Cherry_Image.png");
	banana.loadFromFile("Data/Sprites/Spr_Banana_Image.png");
	peach.loadFromFile("Data/Sprites/Spr_Peach_Image.png");
}

Food::~Food() {}

void Food::Render(sf::RenderWindow& m_window)
{
	if (f_alive)
	{

		switch (randNum) {
		case 1:
			foodSprite.setTexture(orange);
			foodSprite.setScale(0.18, 0.18);

		case 2:
			foodSprite.setTexture(cherry);
			foodSprite.setScale(0.22, 0.22);

		case 3:
			foodSprite.setTexture(cherry);
			foodSprite.setScale(0.2, 0.2);

		case 4:
			foodSprite.setTexture(peach);
			foodSprite.setScale(0.2, 0.2);
		default:
			break;
		}


		//foodSprite.setPosition(f_position);
		foodSprite.setOrigin(0, 0);
		m_window.draw(foodSprite);
	}
}

void Food::SpawnFruit(int width, int height, int blockSize,Food foodItems)
{
	int maxX = (width / blockSize) -2;
	int maxY = (height / blockSize) - 2;

	foodItems.f_position =
		sf::Vector2f(rand() % maxX + 1, rand() % maxY + 1);
	foodSprite.setPosition(f_position.x * blockSize,
		f_position.y * blockSize);

}

void Food::SetAlive(bool alive)
{
	f_alive = alive;
}

