#include "Case.h"



Case::Case(const Vector2f& _position, const int& _size, RenderWindow* _window, const bool& _state)
{
	render = _window;

	ext_Rect = new RectangleShape(Vector2f(_size, _size));
	int_Rect = new RectangleShape(Vector2f(_size / 1.4, _size / 1.4));

	ext_Rect->setFillColor(Color(128, 128, 128));


	ext_Rect->setPosition(_position);
	int_Rect->setPosition(_position + Vector2f(_size / 2, _size / 2));
	int_Rect->setPosition(int_Rect->getPosition() - Vector2f(int_Rect->getSize().x / 2, int_Rect->getSize().y / 2));

	SetState(_state);
}

bool Case::Contains(const Vector2i& _mousePosition)
{
	const bool _isValid = (_mousePosition.x > ext_Rect->getPosition().x &&
		_mousePosition.x < ext_Rect->getPosition().x + ext_Rect->getSize().x &&
		_mousePosition.y > ext_Rect->getPosition().y &&
		_mousePosition.y < ext_Rect->getPosition().y + ext_Rect->getSize().y);
	return _isValid;
}

void Case::SetState(bool _state)
{
	state = _state;
	if (state)
		int_Rect->setFillColor(Color::White);
	else
		int_Rect->setFillColor(Color::Black);
}

bool Case::GetState() const
{
	return state;
}



bool Case::IsClicked()
{
	bool _canClick = Contains(Mouse::getPosition(*render)),
		_hit = Mouse::isButtonPressed(Mouse::Left);
	if (_canClick && _hit && !isClicked && canDraw)
	{
		isClicked = true;
		return true;
	}
	else if (!_hit && isClicked)
		isClicked = false;
	return false;
}



void Case::Draw(RenderWindow& _window)
{
	if (!canDraw)
		return;
	_window.draw(*ext_Rect);
	_window.draw(*int_Rect);
}

void Case::Update()
{
	if (IsClicked())
		SetState(!state);
}
