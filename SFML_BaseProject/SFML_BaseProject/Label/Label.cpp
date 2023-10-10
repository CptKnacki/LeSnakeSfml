#include "Label.h"
#include "../DataBase/DataBase.h"

Label::Label(const Vector2f& _position, const std::string& _text, const int& _characterSize)
{
    text = Text(_text, DataBase::Font, _characterSize);
    text.setPosition(_position);
}

Label::~Label()
{
}

void Label::Draw(RenderWindow& _window)
{
    if (canDraw)
        _window.draw(text);
}

void Label::Update()
{
}

void Label::SetPosition(const Vector2f& _position)
{
    text.setPosition(_position);
}

Vector2f Label::GetPosition() const
{
    return text.getPosition();
}

void Label::SetCharaSize(const int& _size)
{
    text.setCharacterSize(_size);
}

int Label::GetCharaSize() const
{
    return text.getCharacterSize();
}
