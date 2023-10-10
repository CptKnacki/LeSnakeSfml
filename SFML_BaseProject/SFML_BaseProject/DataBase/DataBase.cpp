#include "DataBase.h"
#include <iostream>

DataBase::DataBase()
{
	LoadFont();
}

DataBase::~DataBase()
{
}

void DataBase::LoadFont()
{
	if (!Font.loadFromFile("../Font/Minecraftia-Regular.ttf"))
		std::cout << "la font ne charge pas !";
}
