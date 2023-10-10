#pragma once
#include "../Object/Object.h"
#include "SFML/Graphics.hpp"

class GameObject : public Object
{
	bool canDraw = false;
public:
	GameObject();
	virtual ~GameObject() override;

	virtual void Draw(sf::RenderWindow& _window) {}
	virtual void Update() {}
};

