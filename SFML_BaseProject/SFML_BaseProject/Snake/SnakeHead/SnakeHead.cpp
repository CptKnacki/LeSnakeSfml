#include "SnakeHead.h"
#include "../../Utils.h"
#include "../../BaseMenuManager/MenuManager.h"
#include <iostream>


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

int SnakeHead::GetScore()
{
	return bodyList.size();
}

sf::RectangleShape* SnakeHead::GetHeadShape()
{
	return headShape;
}

std::vector<SnakeBody*> SnakeHead::GetBodyList()
{
	return bodyList;
}

void SnakeHead::AddBodyAndRelocate(Node* _node)
{
	for (size_t i = 0; i < GET_VIEWPORT->GetGrid()->GetNodeList().size(); i++)
	{
		if (GET_VIEWPORT->GetGrid()->GetNodeList()[i]->GetContainedObject() && GET_VIEWPORT->GetGrid()->GetNodeList()[i] != _node)
		{
			headShape->setPosition(GET_VIEWPORT->GetGrid()->GetNodeList()[i]->GetShape()->getPosition());
			GET_VIEWPORT->GetGrid()->GetNodeList()[i]->DestroyContainedObject();
		}
	}

	AddBody();
}

void SnakeHead::AddBody()
{

	sf::Vector2f _positionOffset;

	switch (direction)
	{
	case UP:
	{
		_positionOffset = sf::Vector2f(0, rightMovementRange * bodyList.size());
		break;
	}
	case DOWN:
	{

		_positionOffset = sf::Vector2f(0, -rightMovementRange * bodyList.size());
		break;
	}
	case LEFT:
	{

		_positionOffset = sf::Vector2f(leftMovementRange * bodyList.size(), 0);

		break;
	}
	case RIGHT:
	{

		_positionOffset = sf::Vector2f(-leftMovementRange * bodyList.size(), 0);
		break;
	}
	default:
		break;
	}

	bodyList.push_back(new SnakeBody(sf::Vector2f(leftMovementRange, rightMovementRange), (sf::Vector2f)GET_VIEWPORT->GetWindow()->getSize()));

}




void SnakeHead::DetermineDeath()
{
	for (size_t i = 0; i < bodyList.size(); i++)
	{
		if (bodyList[i]->GetShape()->getPosition() == headShape->getPosition())
		{
		onDie.Invoke();
			headShape->setFillColor(sf::Color::Transparent);
			headShape->setOutlineColor(sf::Color::Transparent);

			for (size_t i = 0; i < bodyList.size(); i++)
			{
				bodyList[i]->GetShape()->setFillColor(sf::Color::Transparent);
				bodyList[i]->GetShape()->setOutlineColor(sf::Color::Transparent);
			}

			gameIsOn = false;
			MenuManager::Instance()->SetState(Menu::Over);

			for (size_t i = 0; i < GET_VIEWPORT->GetGrid()->GetNodeList().size(); i++)
			{
				GET_VIEWPORT->GetGrid()->GetNodeList()[i]->DestroyContainedObject();
			}

			GET_VIEWPORT->GetGrid()->SetGameIsOn(false);
			
			return;
		}
	}
}

void SnakeHead::Kill()
{
	headShape->setFillColor(sf::Color::Transparent);
	headShape->setOutlineColor(sf::Color::Transparent);

	for (size_t i = 0; i < bodyList.size(); i++)
	{
		delete bodyList[i];
		bodyList[i] = nullptr;
	}

	gameIsOn = false;

}

void SnakeHead::Draw(sf::RenderWindow& _window)
{
	_window.draw(*headShape);
}

void SnakeHead::Update()
{

	if (!gameIsOn)
		return;

	sf::Vector2f _headPosition = headShape->getPosition();

	switch (direction)
	{
	case UP:
	{
		headShape->setPosition(headShape->getPosition() - sf::Vector2f(0, rightMovementRange));
		if (headShape->getPosition().y < 0)
			headShape->setPosition(sf::Vector2f(headShape->getPosition().x, GET_WINDOW->getSize().y - rightMovementRange));
		if (bodyList.size() == 0)
			break;
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
		if(bodyList.size() == 0)
			break;
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
		if(bodyList.size() == 0)
			break;
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
		if(bodyList.size() == 0)
			break;
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

	DetermineDeath();


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if(direction == MoveDirection::LEFT || direction == MoveDirection::RIGHT)
		{
			direction = MoveDirection::UP;
			return;
		}
	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (direction == MoveDirection::UP || direction == MoveDirection::DOWN)
		{
			direction = MoveDirection::LEFT;
			return;
		}
	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (direction == MoveDirection::LEFT || direction == MoveDirection::RIGHT)
		{
			direction = MoveDirection::DOWN;
			return;
		}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (direction == MoveDirection::UP || direction == MoveDirection::DOWN)
		{
			direction = MoveDirection::RIGHT;
			return;
		}
	
	
	
}

void SnakeHead::Restart()
{
	gameIsOn = true;
	headShape->setPosition(GET_VIEWPORT->GetGrid()->GetNodeList()[165]->GetShape()->getPosition());
	headShape->setFillColor(sf::Color(225, 210, 0));
	headShape->setOutlineColor(sf::Color::Black);

	for (size_t i = 0; i < bodyList.size(); i++)
	{
		delete bodyList[i];
		bodyList[i] = nullptr;
	}
	bodyList.clear();

}
