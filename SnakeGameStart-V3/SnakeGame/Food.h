#pragma once
#include <SFML/Graphics.hpp>

class Food
{
private:

	bool f_alive{ false };
	sf::Sprite foodSprite;
	sf::Texture orange;
	sf::Texture cherry;
	sf::Texture banana;
	sf::Texture peach;
	sf::Vector2f f_position;
	int randNum;


public:
	Food();
	~Food();
	//void canSpawn();
	//bool IsPlaceTaken(sf::Vector2f pos);
	void Render(sf::RenderWindow& m_window);
	//void Update();
	void SpawnFruit(int width, int height, int blockSize,Food foodItem);
	const bool GetAlive() const { return f_alive; }
	void SetAlive(bool alive);
	const sf::Vector2f GetPosition() const { return f_position; }


};

