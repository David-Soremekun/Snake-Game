#include "Food.h"
#include "random"
#include <time.h>
Food::Food()
{
	score = rand()%4+1;
	orange.loadFromFile("Data/Sprites/Spr_Orange_Image.png");
	cherry.loadFromFile("Data/Sprites/Spr_Cherry_Image.png");
	banana.loadFromFile("Data/Sprites/Spr_Banana_Image.png");
	peach.loadFromFile("Data/Sprites/Spr_Peach_Image.png");
}
void Food::canSpawn()
{

}




bool Food::isPlaceTaken(sf::Vector2f pos) const
{
	return false;
}

void Food::render(sf::RenderWindow& window)
{
	
	if (f_alive)
	{
		if (score == 4) {
			
			
			sprite.setTexture(orange);
			sprite.setScale(0.18,0.18);
		}else if(score== 3){
			
			sprite.setTexture(cherry);
			sprite.setScale(0.22, 0.22);
		}else if (score == 2) {
			sprite.setTexture(cherry);
			sprite.setScale(0.2, 0.2);
		}
		else {
			sprite.setTexture(peach);
			sprite.setScale(0.2, 0.2);
		}
		
		
		sprite.setPosition(f_position);
		sprite.setOrigin(0,0);
		window.draw(sprite);
	}

}

void Food::update()
{
	

}

void Food::Spawn(sf::Vector2f pos)
{
	score = rand() % 4 + 1;
	f_position = pos;
	f_alive = false;
}

void Food::SetAlive(bool f)
{
	f_alive = f;


}



