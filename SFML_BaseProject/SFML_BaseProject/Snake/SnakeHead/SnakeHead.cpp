#include "SnakeHead.h"
#include "../../Utils.h"


SnakeHead::SnakeHead(const sf::Vector2f& _size, const sf::Vector2f& _position)
{

	leftMovementRange = _size.x;
	rightMovementRange = _size.y;

	headShape = new RectangleShape(_size);
	headShape->setPosition(_position);

	headShape->setOutlineThickness(1.0f);
	headShape->setOutlineColor(sf::Color::Black);
	headShape->setFillColor(sf::Color(225, 210, 0));
}

SnakeHead::~SnakeHead()
{
	delete headShape;
	headShape = nullptr;
}

void SnakeHead::AddBody(SnakeBody* _bodyPart)
{
	bodyList.push_back(_bodyPart);
}

void SnakeHead::Draw(sf::RenderWindow& _window)
{
	_window.draw(*headShape);
}

void SnakeHead::Update()
{
	GET_WINDOW->getSize().x;

	sf::Vector2f _headPosition = headShape->getPosition();

	switch (direction)
	{
	case UP:
	{
		headShape->setPosition(headShape->getPosition() - sf::Vector2f(0, rightMovementRange));
		if (headShape->getPosition().y < 0)
			headShape->setPosition(sf::Vector2f(headShape->getPosition().x, GET_WINDOW->getSize().y - rightMovementRange));

		for (size_t i = bodyList.size() - 1; i > 0; i--)
		{
			bodyList[i]->GetShape()->setPosition(bodyList[i - 1]->GetShape()->getPosition());

			if (bodyList[i]->GetShape()->getPosition().y < 0)
				bodyList[i]->GetShape()->setPosition(sf::Vector2f(bodyList[i]->GetShape()->getPosition().x, GET_WINDOW->getSize().y - rightMovementRange));
		}

		if (bodyList.size() != 0)
			bodyList[0]->GetShape()->setPosition(_headPosition);

		break;
	}
	case DOWN:
	{
		headShape->setPosition(headShape->getPosition() + sf::Vector2f(0, rightMovementRange));
		if (headShape->getPosition().y >= GET_WINDOW->getSize().y)
			headShape->setPosition(sf::Vector2f(headShape->getPosition().x, 0));

		for (size_t i = bodyList.size() - 1; i > 0; i--)
		{
			bodyList[i]->GetShape()->setPosition(bodyList[i - 1]->GetShape()->getPosition());

			if (bodyList[i]->GetShape()->getPosition().y >= GET_WINDOW->getSize().y)
				bodyList[i]->GetShape()->setPosition(sf::Vector2f(bodyList[i]->GetShape()->getPosition().x, 0));
		}

		if (bodyList.size() != 0)
			bodyList[0]->GetShape()->setPosition(_headPosition);


		break;
	}
	case LEFT:
	{
		headShape->setPosition(headShape->getPosition() - sf::Vector2f(leftMovementRange, 0));
		if (headShape->getPosition().x < 0)
			headShape->setPosition(sf::Vector2f(GET_WINDOW->getSize().x - leftMovementRange, headShape->getPosition().y));

		for (size_t i = bodyList.size() - 1; i > 0; i--)
		{
			bodyList[i]->GetShape()->setPosition(bodyList[i - 1]->GetShape()->getPosition());

			if (bodyList[i]->GetShape()->getPosition().x < 0)
				bodyList[i]->GetShape()->setPosition(sf::Vector2f(GET_WINDOW->getSize().x - leftMovementRange, bodyList[i]->GetShape()->getPosition().y));
		}

		if (bodyList.size() != 0)
			bodyList[0]->GetShape()->setPosition(_headPosition);

		break;
	}
	case RIGHT:
	{
		headShape->setPosition(headShape->getPosition() + sf::Vector2f(leftMovementRange, 0));
		if (headShape->getPosition().x >= GET_WINDOW->getSize().x)
			headShape->setPosition(sf::Vector2f(0, headShape->getPosition().y));

		for (size_t i = bodyList.size() - 1; i > 0; i--)
		{
			bodyList[i]->GetShape()->setPosition(bodyList[i - 1]->GetShape()->getPosition());

			if (bodyList[i]->GetShape()->getPosition().x >= GET_WINDOW->getSize().x)
				bodyList[i]->GetShape()->setPosition(sf::Vector2f(0, bodyList[i]->GetShape()->getPosition().y));
		}

		if (bodyList.size() != 0)
			bodyList[0]->GetShape()->setPosition(_headPosition);

		break;
	}
	default:
		break;
	}


	// IF INPUT Z Q S D CHANGER LA DIRECTION //

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		if(direction == MoveDirection::LEFT || direction == MoveDirection::RIGHT)
			direction = MoveDirection::UP;
	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		if(direction == MoveDirection::UP || direction == MoveDirection::DOWN)
			direction = MoveDirection::LEFT;
	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if(direction == MoveDirection::LEFT || direction == MoveDirection::RIGHT)
		direction = MoveDirection::DOWN;
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if(direction == MoveDirection::UP || direction == MoveDirection::DOWN)
			direction = MoveDirection::RIGHT;
	
	
	
	
}
