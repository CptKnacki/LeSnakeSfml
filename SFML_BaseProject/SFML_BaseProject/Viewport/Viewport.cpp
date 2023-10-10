#include "Viewport.h"

Viewport::Viewport(const int& _width, const int& _height, const std::string& _title)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(_width, _height), _title);
}

Viewport::~Viewport()
{
    delete gameWindow;
    gameWindow = nullptr;
}

void Viewport::OpenWindow()
{
    while (gameWindow->isOpen())
    {
        sf::Event event;
        while (gameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow->close();
        }

        gameWindow->clear();
        DrawAllObjects();
        gameWindow->display();
    }
}

void Viewport::DrawAllObjects()
{
}
