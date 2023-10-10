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
	if (!Font.loadFromFile(""))
		std::cout << "la font ne charge pas !";
}
