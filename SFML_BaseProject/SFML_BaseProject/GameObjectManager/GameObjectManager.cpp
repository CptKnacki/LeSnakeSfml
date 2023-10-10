#include "GameObjectManager.h"

GameObjectManager::~GameObjectManager()
{
	DestroyAll();
}

void GameObjectManager::Register(GameObject* _object)
{
	GO_List.push_back(_object);
}

void GameObjectManager::UnRegister(GameObject* _object)
{
	for (size_t i = 0; i < GO_List.size(); i++)
	{
		if (GO_List[i] == _object)
			GO_List.erase(GO_List.begin() + i);
	}
}

void GameObjectManager::UnRegisterAll()
{
	GO_List.clear();
}

void GameObjectManager::Draw(sf::RenderWindow& _window)
{
	for (GameObject* _object : GO_List)
	{
		if (_object)
			_object->Draw(_window);
	}
}

void GameObjectManager::Update()
{
	for (GameObject* _object : GO_List)
	{
		if (_object)
			_object->Update();
	}
}

void GameObjectManager::DestroyAll()
{
	for (GameObject* _object : GO_List)
		delete _object;
	GO_List.clear();
}

size_t GameObjectManager::Count() const
{
	return GO_List.size();
}
