#pragma once
#include "../GameObject/GameObject.h"


class Button : public GameObject
{
	RectangleShape* rect = nullptr;
	Text label;

public:
	Button(const Vector2f& _position, const Vector2f& _size, const std::string& _label, const int& _fontSize = 12);
	~Button();

public:
	virtual void Draw(RenderWindow& _window) override;
	virtual void Update() override;

	void SetPosition(const Vector2f& _position);
	Vector2f GetPosition() const;

	void SetSize(const Vector2f& _size);
	Vector2f GetSize() const;
};

