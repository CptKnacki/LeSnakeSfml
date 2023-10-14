#pragma once
#include "../../GameObject/GameObject.h"
#include "../SnakeBody/SnakeBody.h"
#include <vector>
#include "../../Action/Action.h"

class Node;

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
	bool gameIsOn = true;

	Action onDie;

public:
	Action& OnDie() { return onDie; }
	SnakeHead(const sf::Vector2f& _size, const sf::Vector2f& _position);
	~SnakeHead();

	int GetScore();
	sf::RectangleShape* GetHeadShape();
	std::vector<SnakeBody*> GetBodyList();
	void AddBodyAndRelocate(Node* _node);
	void AddBody();
	void DetermineDeath();
	void Kill();
	virtual void Draw(sf::RenderWindow& _window) override;
	virtual void Update() override;
	virtual void Restart() override;
};

