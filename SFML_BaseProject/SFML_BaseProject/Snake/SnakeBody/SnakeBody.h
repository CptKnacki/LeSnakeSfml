#pragma once
#include "../../GameObject/GameObject.h"

class SnakeBody : public GameObject
{
private:
	sf::RectangleShape* bodyShape = nullptr;

public:
	SnakeBody(const sf::Vector2f& _size, const sf::Vector2f& _position);
	~SnakeBody();

	sf::RectangleShape* GetShape();
	virtual void Draw(sf::RenderWindow& _window) override;
	virtual void Update() override;
};

