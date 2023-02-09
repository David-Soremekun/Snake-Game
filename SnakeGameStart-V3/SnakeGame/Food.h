#pragma once
//#include "Game.h"  
#include <SFML/Graphics.hpp>

class Food
{
private:
	
	bool f_alive{ false };
	sf::Sprite sprite;
	sf::Texture orange;
	sf::Texture cherry;
	sf::Texture banana;
	sf::Texture peach;
	sf::Vector2f f_position;
	int score;
	

public:
	Food();
	void canSpawn();
	
	bool isPlaceTaken(sf::Vector2f pos) const;
	void render(sf::RenderWindow& window);
	void update();
	void Spawn(sf::Vector2f pos);
	bool GetAlive() const { return f_alive; }
	void SetAlive(bool f);
	sf::Vector2f GetPosition()const { return f_position; }
	

};

