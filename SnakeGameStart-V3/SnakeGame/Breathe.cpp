#include "Breathe.h"
#include <iostream>

Breathe::Breathe()
{
	waterClock.restart();
	currentOxygenLevel = 120.f;
	waterClock.getElapsedTime().asSeconds();
	breathBubble.loadFromFile("Data/Sprites/Bubble_Image.png");
	OxyValue = OxyValue/10.f;
}

void Breathe::CreateBar()
{
	
	bubbleSprite.setTexture(breathBubble);
	bubbleSprite.setScale(0.15f, 0.15f);
	bubbleSprite.setOrigin(sf::Vector2f(0.f, 0.f));
	bubbleSprite.setPosition(sf::Vector2f(2.f,218.f));
	
	

	BreatheBar.setSize(sf::Vector2f(34.f, 124.f));
	OxiLevel.setSize(sf::Vector2f(25.f, 120.f));

	BreatheBar.setOrigin(sf::Vector2f(0.f,0.f));
	OxiLevel.setOrigin(sf::Vector2f(0.f, 0.f));

	BreatheBar.setFillColor(sf::Color::White);
	OxiLevel.setFillColor(sf::Color::Green);

	BreatheBar.setPosition(sf:: Vector2f(3.f,250.f));
	OxiLevel.setPosition(sf::Vector2f(8.f, 250.f));
}

void Breathe::DecreaseLevel()
{
	currentOxygenLevel -= OxyValue;
	OxiLevel.setSize(OxiLevel.getSize() - sf::Vector2f(0, OxyValue));
	OxiLevel.setRotation(180.f);
	OxiLevel.setPosition(34, 240 + 124);
	
	

}

void Breathe::render(sf::RenderWindow& window)
{
	
	window.draw(BreatheBar);
	window.draw(OxiLevel);
	window.draw(bubbleSprite);

}

void Breathe::TakeBreath()
{
	OxiLevel.setSize(sf::Vector2f(25.f, 120.f));
	waterClock.restart();
	

}

void Breathe::Update()
{

}
