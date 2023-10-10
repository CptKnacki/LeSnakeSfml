#include "GameEngineManager.h"
#include "../Engine/Engine.h"

void GameEngineManager::Register(Engine* _engine)
{
	engineInstance = _engine;
}

void GameEngineManager::UnregisterEngine()
{
	if (!engineInstance)
		return;

	engineInstance = nullptr;
}

Engine* GameEngineManager::GetEngineInstance()
{
	return engineInstance;
}
