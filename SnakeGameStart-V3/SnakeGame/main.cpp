/*
  Games Development with C++ GAV1031-N
  Snake ICA start project 
  
  Set up to use the SFML 2.5.1 64-bit API
    SFML documentation: https://www.sfml-dev.org/learn.php
*/

#include <iostream>
#include "SnakeHead.h"
#include "Game.h"
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>

int main()
{
    Game newGame;
    newGame.play();

    std::cout << "SnakeGame: Finished" << std::endl;

    return 0;
}
