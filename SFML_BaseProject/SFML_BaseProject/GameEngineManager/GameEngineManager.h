#pragma once
#include "../Singleton/Singleton.h"


class Engine;

class GameEngineManager : public Singleton<GameEngineManager>
{

private:
	Engine* engineInstance = nullptr;

public:
	void Register(Engine* _engine);
	void UnregisterEngine();
	Engine* GetEngineInstance();
};

