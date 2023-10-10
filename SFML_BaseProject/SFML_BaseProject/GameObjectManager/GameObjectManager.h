#pragma once
#include "../Singleton/Singleton.h"
#include "../GameObject/GameObject.h"
#include <vector>

class GameObjectManager : public Singleton<GameObjectManager>
{
	std::vector<GameObject*> GO_List = std::vector<GameObject*>();

public:
	GameObjectManager() = default;
	~GameObjectManager();

	void Register(GameObject* _object);
	void UnRegister(GameObject* _object);
	void UnRegisterAll();

	void Draw(sf::RenderWindow& _window);
	void Update();

	void DestroyAll();

	size_t Count() const;
};

