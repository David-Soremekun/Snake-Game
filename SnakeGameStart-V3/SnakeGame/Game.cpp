#include "Game.h"
#include "SnakeHead.h"
#include <iostream>
#include "Direction.h"
SnakeHead snake(sf::Vector2f(200, 200), sf::Color::Yellow);



void Game::RandomlyAddFood()
{
    
    if (rand() %5 == 0) {
        for (int i = 0; i <= 6; i++) {
            if (!foodItems[i].GetAlive()) {

                sf::Vector2f pos;

                do {
                    pos.x = (rand() % (ScreenWidth / (int)40.f) * 40.f);
                    pos.y = (rand() % (ScreenHeight / (int)40.f) * 40.f);
                } while (isPlaceTaken(pos));
                
                foodItems[i].Spawn(pos);
                foodItems[i].SetAlive(true);

                break;
            }
        }
    }
    

}



bool Game::isPlaceTaken(sf::Vector2f pos) const
{
    for (int i = 0; i < 5; i++)
    {
        if (!foodItems[i].GetAlive() && foodItems[i].GetPosition()==pos)
            return true;
        
    }
    for (SnakeHead* snake: m_snakeVector)
    {
        if (snake->DoYouCoverPlace(pos))
        {
            return true;
        }
    }
    if (pos.y> m_waterDimension.y)
    {
        return true;
    }



    return false;
}

sf::Vector2f Game::findFreeSpace()
{
    int alongX= (rand() % (ScreenWidth / (int)40.f) * 40.f);
    int alongY = (rand() % (ScreenHeight / (int)40.f) * 40.f);



    return sf::Vector2f();
}

void Game::play()
{
    // All SFML types and functions are contained in the sf namespace
    
    int score=0;
    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text
    sf::RenderWindow window(sf::VideoMode(ScreenHeight, ScreenWidth), "C++ Snake ICA : b1053474");
    window.setFramerateLimit(60);
    
    // Create an instance of the SFML CircleShape and initialise it so radius is 100
    
    CreateWalls();
    Breathe bar;
    bar.CreateBar();
    
    m_waterDimension=sf::Vector2f(sf::Vector2f(ScreenHeight-40.f*2.0f, 
        ScreenWidth-40.f*2.0f));

    sf::RectangleShape rect(m_waterDimension);


    rect.setPosition(sf::Vector2f(0.0f,40.f));
    rect.setFillColor(sf::Color::Blue);



    float startWaterHeight =ScreenHeight - 40.f * 2.0f;
    float waterDropAmount=startWaterHeight/150.0f;
    float currentWaterDrop=0;

    sf::Font font;
    if (!font.loadFromFile("Data/Fonts/ARCADECLASSIC.ttf")) {
        std::cout << "Font Could not be loaded" << std::endl;
        return;
    }
    sf::Text scoreHud;
    scoreHud.setFont(font);
    scoreHud.setCharacterSize(35);
    scoreHud.setFillColor(sf::Color::Red);
    scoreHud.setPosition(sf::Vector2f(600.f,550.f));



    sf::Clock timeElapsedClock;
    timeElapsedClock.restart();
    timeElapsedClock.getElapsedTime().asSeconds();

    // We can still output to the console window
    std::cout << "SnakeGame: Starting" << std::endl;
    sf::Clock clock;
    clock.restart();
    clock.getElapsedTime().asSeconds();

   
    
    
    // Main loop that continues until we call window.close()
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            snake.direction = Direction::North;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            snake.direction = Direction::South;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            snake.direction = Direction::West;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            snake.direction = Direction::East;
        }

        // We must clear the window each time around the loop
        window.clear();
        if (timeElapsedClock.getElapsedTime().asSeconds()>=1.0f) {

            currentWaterDrop+=waterDropAmount;
            m_waterDimension.y-= waterDropAmount;
            rect.setPosition(m_waterDimension);

            timeElapsedClock.restart();
        }
        window.draw(rect);

        if (clock.getElapsedTime().asSeconds() >= 0.25f) {
            
            RandomlyAddFood();

            if (snake.CheckCollision()) {
                std::cout << "Collision with self\n";
                snake.Reset();
            }
            if (snake.CheckWallCollision()) {
                std::cout << "Collision with wall\n";
                score -= 5;
                snake.Reset();
            }
            snake.Update();
            for (size_t i = 0; i < 6; i++)
            {

                if (snake.getPosition() == foodItems[i].GetPosition())
                {
                    score += 5;
                    
                    snake.addSegment();
                    scoreHud.setString("Score  " + std::to_string(score));
                    foodItems[i].SetAlive(false);
                   
                }
            }
            
            clock.restart();
        }


        // draw our circle shape to the window
        snake.Render(window);
        for (size_t i = 0; i < 6; i++)
        {
            if(foodItems[i].GetAlive())
                foodItems[i].render(window);
            
        }
        // Get the window to display its contents
        
        //std::stringstream streamScore();
        //streamScore << "Score: " << score;

        
        
        window.draw(WallLeft);
        window.draw(WallRight);
        window.draw(WallBottom);


        bar.render(window);
        window.draw(scoreHud);
        window.display();
        
       
    }
}

void Game::render(sf::RenderWindow& window)
{
}



void Game::CreateWalls()
{
    WallLeft.setSize(sf::Vector2f(40.f,600.f));
    WallRight.setSize(sf::Vector2f(40.f, 600.f));
   
    WallBottom.setSize(sf::Vector2f(800.f, 40.f));

    WallLeft.setFillColor(sf::Color::White);
    WallRight.setFillColor(sf::Color::White);
   
    WallBottom.setFillColor(sf::Color::White);
    
    WallLeft.setPosition(sf::Vector2f(0.f,0.f));
    WallRight.setPosition(sf::Vector2f(760.f, 0.f));
    
    WallBottom.setPosition(sf::Vector2f(0.f, 560.f));
}

Game::Game()
{


}




