#pragma once
#include "../Object/Object.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class GameObject : public Object
{
protected:
	bool canDraw = false;
public:
	void SetCanDraw(bool _state);
	GameObject();
	virtual ~GameObject() override;

	virtual void Draw(sf::RenderWindow& _window) {}
	virtual void Update() {}
	virtual void Restart() {}
};

