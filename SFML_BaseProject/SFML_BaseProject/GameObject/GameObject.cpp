#include "GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"

GameObject::GameObject()
{
	GameObjectManager::Instance()->Register(this);
}

GameObject::~GameObject()
{
	GameObjectManager::Instance()->UnRegister(this);
}
