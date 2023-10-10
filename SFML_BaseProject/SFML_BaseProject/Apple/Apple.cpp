#include "Apple.h"

Apple::Apple(const sf::Vector2f& _position, const float& _size)
{
	appleShape = new sf::CircleShape(_size / 2, 80);
	appleShape->setFillColor(sf::Color::Red);
	appleShape->setOrigin(appleShape->getRadius(), appleShape->getRadius());
	appleShape->setPosition(_position);
}

Apple::~Apple()
{
	delete appleShape;
	appleShape = nullptr;
}

void Apple::Draw(sf::RenderWindow& _window)
{
	_window.draw(*appleShape);
}

void Apple::Update()
{
}
