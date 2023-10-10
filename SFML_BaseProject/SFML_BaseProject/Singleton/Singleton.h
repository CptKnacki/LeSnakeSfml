#pragma once
#include "../Object/Object.h"

template<typename T>
class Singleton : public Object
{
	static inline T* instance = nullptr;
public:
	Singleton() = default;
	virtual ~Singleton() override
	{
		OnDestroy();
	}
public:
	static T* Instance()
	{
		if (!instance)
			instance = new T();
		return instance;
	}
	void OnDestory()
	{
		delete instance;
	}
};