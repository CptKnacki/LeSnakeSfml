#pragma once
#include "../GameObject/GameObject.h"

class UImage : public GameObject
{
	Sprite* image = nullptr;

public:
	UImage(const Vector2f& _position, const Texture& _texture);
	~UImage();
public:
	virtual void Draw(RenderWindow& _window) override;
	virtual void Update() override;

	void SetPosition(const Vector2f& _position);
	Vector2f GetPosition() const;

	void SetScale(const Vector2f& _scale);
	Vector2f GetScale() const;
};

