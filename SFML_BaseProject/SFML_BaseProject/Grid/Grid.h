#pragma once
#include "../GameObject/GameObject.h"
#include "../Node/Node.h"
#include <vector>

class Grid : public GameObject
{
private:
	std::vector<Node*> nodeList;
	float nodeSizeX;
	float nodeSizeY;

	bool gameIsOn = true;

public:
	Grid(sf::RenderWindow* _window, const int& _nodeDivideCount = 20);
	~Grid();
	
	void SetGameIsOn(bool _value);
	float GetNodeSizeX();
	float GetNodeSizeY();
	std::vector<Node*> GetNodeList();

	void SetGridColor();
	void CreateApple();
	bool HasApple();

	virtual void Draw(sf::RenderWindow& _window) override;
	virtual void Update() override;

	virtual void Restart() override;
};

