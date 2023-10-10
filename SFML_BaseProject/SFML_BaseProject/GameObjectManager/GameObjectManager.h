<<<<<<< Updated upstream
#pragma once
class GameObjectManager
{
};

=======
#pragma once 
#include "../Singleton/Singleton.h"
#include "../GameObject/GameObject.h"
#include <vector>

class GameObjectManager : public Singleton<GameObjectManager>
{
	std::vector<GameObject*>
};
>>>>>>> Stashed changes
