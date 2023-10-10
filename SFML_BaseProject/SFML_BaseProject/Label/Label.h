#pragma once
#include "../GameObject/GameObject.h"



class Label : public GameObject
{
	Text text;

public:
	Label(const Vector2f& _position, const std::string& _text, const int& _characterSize = 18);
	~Label();

public:
	virtual void Draw(RenderWindow& _window) override;
	virtual void Update() override;

	void SetPosition(const Vector2f& _position);
	Vector2f GetPosition() const;

	void SetCharaSize(const int& _size);
	int GetCharaSize() const;
};

