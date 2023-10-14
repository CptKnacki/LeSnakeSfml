#pragma once
#include "../Singleton/Singleton.h"
#include "../Menu/BaseMenu.h"
#include <map>

enum Menu
{
	None,
	Main,
	Game,
	Over,
	Settings
};

class MenuManager : public Singleton<MenuManager>
{
	std::map<const char*, BaseMenu*> menuList = std::map<const char*, BaseMenu*>();
	Menu state = None;
public:
	MenuManager() = default;
	~MenuManager() override;
public:
	void SetState(Menu _state);
	Menu GetState() const;
	void SwitchMenu();
	void CloseAll();

	void Register(const char* _title, BaseMenu* _menu);
	void UnRegister(const char* _title);
	void UnRegisterAll();
	void DestroyAll();

	void Update();
};

