#include "GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"

void GameObject::SetCanDraw(bool _state)
{
	canDraw = _state;
}

GameObject::GameObject()
{
	GameObjectManager::Instance()->Register(this);
}

GameObject::~GameObject()
{
	GameObjectManager::Instance()->UnRegister(this);
}
