#include "SnakeBody.h"

SnakeBody::SnakeBody(const sf::Vector2f& _size, const sf::Vector2f& _position)
{
	bodyShape = new RectangleShape(_size);
	bodyShape->setPosition(_position);

	bodyShape->setOutlineThickness(1.0f);
	bodyShape->setOutlineColor(sf::Color::Black);
	bodyShape->setFillColor(sf::Color(15, 80, 0));
}

SnakeBody::~SnakeBody()
{
	delete bodyShape;
	bodyShape = nullptr;
}

sf::RectangleShape* SnakeBody::GetShape()
{
	return bodyShape;
}

void SnakeBody::Draw(sf::RenderWindow& _window)
{
	_window.draw(*bodyShape);
}

void SnakeBody::Update()
{
}
