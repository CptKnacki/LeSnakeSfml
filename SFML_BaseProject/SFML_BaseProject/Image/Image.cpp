#include "Image.h"

UImage::UImage(const Vector2f& _position, const Texture& _texture)
{
	image = new Sprite(_texture);
	image->setPosition(_position);
}

UImage::~UImage()
{
}

void UImage::Draw(RenderWindow& _window)
{
	_window.draw(*image);
}

void UImage::Update()
{
}

void UImage::SetPosition(const Vector2f& _position)
{
	image->setPosition(_position);
}

Vector2f UImage::GetPosition() const
{
	return image->getPosition();
}

void UImage::SetScale(const Vector2f& _scale)
{
	image->setScale(_scale);
}

Vector2f UImage::GetScale() const
{
	return image->getScale();
}
