#pragma once
#include <SFML/Graphics.hpp>
class Breathe
{
private:
	
	sf::RectangleShape BreatheBar;
	sf::RectangleShape OxiLevel;

	sf::Sprite bubbleSprite;
	sf::Texture breathBubble;
	sf::Clock waterClock;

	float currentOxygenLevel{ 0.f };
	float OxyValue=120;
	float OxyDrop{10};

public:
	Breathe();
	void CreateBar();
	void DecreaseLevel();
	void render(sf::RenderWindow& window);
	void TakeBreath();
	void Update();
};

