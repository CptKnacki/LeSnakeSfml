#pragma once
#include "../GameObject/GameObject.h"

class Apple : public GameObject
{

private:
	sf::CircleShape* appleShape = nullptr;

public:
	Apple(const sf::Vector2f& _position, const float& _size);
	~Apple();

	virtual void Draw(sf::RenderWindow& _window) override;
	virtual void Update() override;


};

