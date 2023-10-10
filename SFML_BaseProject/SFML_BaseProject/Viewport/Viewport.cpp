#include "Viewport.h"
#include "../GameObjectManager/GameObjectManager.h"

Viewport::Viewport(const int& _width, const int& _height, const std::string& _title)
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(_width, _height), _title);

    newGrid = new Grid(gameWindow, 20);
}

Viewport::~Viewport()
{
    delete gameWindow;
    gameWindow = nullptr;

    delete newGrid;
    newGrid = nullptr;
}

sf::RenderWindow* Viewport::GetWindow()
{
    return gameWindow;
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
        GameObjectManager::Instance()->Update();
        gameWindow->display();
    }
}

void Viewport::DrawAllObjects()
{
    GameObjectManager::Instance()->Draw(*gameWindow);
}
