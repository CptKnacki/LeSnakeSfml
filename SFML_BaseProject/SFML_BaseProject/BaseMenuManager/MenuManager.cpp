#include "MenuManager.h"

MenuManager::~MenuManager()
{
	DestroyAll();
}

void MenuManager::SetState(Menu _state)
{
	state = _state;
	SwitchMenu();
}

Menu MenuManager::GetState() const
{
	return state;
}

void MenuManager::SwitchMenu()
{
	CloseAll();
	switch (state)
	{
	case Menu::Main:
		if (menuList["Main"])
			menuList["Main"]->Open();
		break;
	case Menu::Game:
		if (menuList["Game"])
			menuList["Game"]->Open();
		break;
	case Menu::Over:
		if (menuList["Over"])
			menuList["Over"]->Open();
		break;
	case None:
		return;
	}
}

void MenuManager::CloseAll()
{
	for (std::pair<const char*, BaseMenu*> _pair : menuList)
	{
		if (_pair.second)
			_pair.second->Close();
	}
}

void MenuManager::Register(const char* _title, BaseMenu* _menu)
{
	menuList.insert(std::pair<const char*, BaseMenu*>(_title, _menu));
}

void MenuManager::UnRegister(const char* _title)
{
	menuList.erase(_title);
}

void MenuManager::UnRegisterAll()
{
	menuList.clear();
}

void MenuManager::DestroyAll()
{
	for (std::pair<const char*, BaseMenu*> _pair : menuList)
		delete _pair.second;
	menuList.clear();
}

void MenuManager::Update()
{
	for (std::pair<const char*, BaseMenu*> _pair : menuList)
	{
		if (_pair.second)
			_pair.second->Update();
	}
}
