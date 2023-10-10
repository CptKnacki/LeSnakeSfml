#pragma once
#include "../../GameObject/GameObject.h"
#include "../SnakeBody/SnakeBody.h"
#include <vector>

enum MoveDirection
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};


class SnakeHead : public GameObject
{
private:
	sf::RectangleShape* headShape = nullptr;
	std::vector<SnakeBody*> bodyList;

	float leftMovementRange = 0.0f;
	float rightMovementRange = 0.0f;

	MoveDirection direction = MoveDirection::RIGHT;

public:
	SnakeHead(const sf::Vector2f& _size, const sf::Vector2f& _position);
	~SnakeHead();
	
	void AddBody(SnakeBody* _bodyPart);
	virtual void Draw(sf::RenderWindow& _window) override;
	virtual void Update() override;
};

