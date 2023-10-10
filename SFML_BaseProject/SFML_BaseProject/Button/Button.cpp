#include "Button.h"
#include "../DataBase/DataBase.h"

Button::Button(const Vector2f& _position, const Vector2f& _size, const std::string& _label, const int& _fontSize)
{
	rect = new RectangleShape(_size);
	rect->setPosition(_position);
	label = Text(_label, DataBase::Font);
	label.setOrigin(Vector2f(-_size.x / 4, _size.y / 4));
	label.setPosition(_position + Vector2f(0, _size.y / 1.5));
	label.setCharacterSize(_fontSize);
	label.setFillColor(Color::Red);
	rect->setSize(Vector2f(label.getGlobalBounds().width + _size.x / 2, _size.y));
}

Button::~Button()
{
	delete rect;
}

void Button::Draw(RenderWindow& _window)
{
	_window.draw(*rect);
	_window.draw(label);
}

void Button::Update()
{
}

void Button::SetPosition(const Vector2f& _position)
{
	rect->setPosition(_position);
	label.setPosition(_position + Vector2f(0, rect->getSize().y /1.5));
}

Vector2f Button::GetPosition() const
{
	return rect->getPosition();
}

void Button::SetSize(const Vector2f& _size)
{
	rect->setSize(_size);
	rect->setSize(Vector2f(label.getGlobalBounds().width + _size.x / 2, _size.y));
}

Vector2f Button::GetSize() const
{
	return rect->getSize();
}
