#pragma once

template<typename T>
class Singleton
{
	static inline T* instance = nullptr;
public:
	Singleton() = default;
	virtual ~Singleton()
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
	void OnDestroy()
	{
		delete instance;
	}
};