#include "Node.h"


Node::Node(const sf::Vector2f& _size, const sf::Vector2f& _position)
{

	nodeShape = new sf::RectangleShape(_size);
	nodeShape->setPosition(_position);
	nodeShape->setOutlineThickness(0.0f);
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
	if (!containedObject)
		return nullptr;

	return containedObject;
}

void Node::DestroyContainedObject()
{
	if (containedObject)
	{
		delete containedObject;
		containedObject = nullptr;
	}

}

void Node::SetFillColor(const sf::Color& _color)
{
	nodeShape->setFillColor(_color);
}

void Node::SetContainedObject(GameObject* _object)
{
	containedObject = _object;
}
