#include "Node.h"


Node::Node(const sf::Vector2f& _size, const sf::Vector2f& _position)
{

	nodeShape = new sf::RectangleShape(_size);
	nodeShape->setPosition(_position);
	nodeShape->setOutlineThickness(1.5f);
	nodeShape->setFillColor(sf::Color::Transparent);
	nodeShape->setOutlineColor(sf::Color::White);

}


Node::~Node()
{
	delete nodeShape;
	nodeShape = nullptr;
}

sf::RectangleShape* Node::GetShape()
{
	return nodeShape;
}

GameObject* Node::GetContainedObject()
{
	return containedObject;
}
