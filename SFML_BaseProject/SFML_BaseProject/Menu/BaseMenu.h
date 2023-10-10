#pragma once
#include <vector>
#include "../GameObject//GameObject.h"


class BaseMenu
{
	std::vector<GameObject*> elements = std::vector<GameObject*>();
	bool isOpen = false;
	const char* title = "";
public:
	BaseMenu(const char* _title);
	~BaseMenu();

public:
	void Open();
	void Close();


	virtual void Update() {}
};

