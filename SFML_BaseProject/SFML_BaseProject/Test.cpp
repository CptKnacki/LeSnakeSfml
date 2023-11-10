#include "Test.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <random>   




Test::Test()
{

	std::ifstream stream("level0.txt");
	if (!stream.is_open())
	{
		std::cout << "Ca marche pas ! " << std::endl;
	}
	std::string _str = "";
	std::string _result = "";
	while (std::getline(stream, _str))
	{
		_result += _str + "\n";
	}

	streamString.push_back(_result);

}

void Test::DisplayStrings()
{
	for (size_t i = 0; i < streamString.size(); i++)
	{
		std::cout << streamString[i] << std::endl;
	}
}

void Test::TestRandom()
{
	std::random_device _rd;
	std::mt19937 _gen(_rd());
	std::uniform_int_distribution<> _distrib(0, 100);

	int _result = _distrib(_gen);
	int _result2 = _distrib(_gen);


	std::cout << _result << " | " << _result2 << std::endl;

	_result = _distrib(_gen);
	_result2 = _distrib(_gen);

	std::cout << _result << " | " << _result2 << std::endl;
}


