#pragma once
#include "Engine/Engine.h"
#include "Viewport/Viewport.h"
#include "GameEngineManager/GameEngineManager.h"



#define GET_WINDOW GameEngineManager::Instance()->GetEngineInstance()->GetViewport()->GetWindow()
#define GET_VIEWPORT GameEngineManager::Instance()->GetEngineInstance()->GetViewport()
#define GET_ENGINE GameEngineManager::Instance()->GetEngineInstance()