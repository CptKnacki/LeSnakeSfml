#pragma once
#include "../GameObject/GameObject.h"

class Case : public GameObject
{
	RectangleShape* ext_Rect = nullptr;
	RectangleShape* int_Rect = nullptr;

	bool state = false;
	bool isClicked = false;
	
	RenderWindow* render = nullptr;

	bool Contains(const Vector2i& _mousePosition);
public:
	Case(const Vector2f& _position, const int& _size, RenderWindow* _window, const bool& _state = false);

	void SetState(bool _state);
	bool GetState() const;

	bool IsClicked();

public:
	virtual void Draw(RenderWindow& _window) override;
	virtual void Update() override;
};


