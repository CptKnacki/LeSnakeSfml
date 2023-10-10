#pragma once
#include "../GameObject/GameObject.h"
#include "SFML/Graphics.hpp"

class Node : public GameObject
{
	
private:
	sf::RectangleShape* nodeShape;
	GameObject* containedObject = nullptr;

public:
	Node(const sf::Vector2f& _size, const sf::Vector2f& _position);
	~Node();
	GameObject* GetContainedObject();
	sf::RectangleShape* GetShape();
	void SetFillColor(const sf::Color& _color);
};

