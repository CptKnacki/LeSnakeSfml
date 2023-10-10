#include "BaseMenu.h"
#include "../BaseMenuManager/MenuManager.h"

BaseMenu::BaseMenu(const char* _title)
{
	title = _title;
	MenuManager::Instance()->Register(_title, this);
}

BaseMenu::~BaseMenu()
{
	MenuManager::Instance()->UnRegister(title);
}

void BaseMenu::Open()
{
	if (isOpen)
		return;
	isOpen = true;
	for (GameObject* _object : elements)
		_object->SetCanDraw(true);
}

void BaseMenu::Close()
{
	if (!isOpen)
		return;
	isOpen = false;
	for (GameObject* _object : elements)
		_object->SetCanDraw(false);
}
