#pragma once
#include "../GameObject/GameObject.h"
#include "../Action/Action.h"

class Button : public GameObject
{
	RectangleShape* rect = nullptr;
	RenderWindow* render = nullptr;
	Text label;
	bool isClicked = false;
	Action onClicked;

	bool Contains(const Vector2i& _input) const;
public:
	Button(const Vector2f& _position, const Vector2f& _size, const std::string& _label, RenderWindow* _render, const int& _fontSize = 12);
	~Button();

public:
	virtual void Draw(RenderWindow& _window) override;
	virtual void Update() override;

	bool IsClicked();

	void SetPosition(const Vector2f& _position);
	Vector2f GetPosition() const;

	void SetSize(const Vector2f& _size);
	Vector2f GetSize() const;
};

