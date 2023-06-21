#pragma once
class World;
class Snake;
#include <SFML/Graphics.hpp>
class Game
{
private:
	int m_screenHeight = 600, m_screenWidth=600;
	float m_elapsed;
	Snake &m_snake;
	World *m_world;
	sf::RenderWindow m_window;
public:
	Game();
	void Update();
};

