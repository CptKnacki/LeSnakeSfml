#pragma once

struct Base
{
	virtual void Invoke() {};
	virtual void Remove() {};
};

template<class TCast, class TOwner >
class ActionEvent : public Base
{
	typedef TCast(TOwner::* Method)(); 
	Method action = nullptr; 
	TOwner* owner = nullptr;
public :
	void Bind(TOwner* _owner, TCast(TOwner::* _action)()) //&Owner::Method
	{
		owner = _owner; 
		action = _action; 
	}
	void Invoke()
	{
		if (!owner || !action)
			return;
		(owner->*action)();
	}
	void Remove()
	{
		owner = nullptr; 
		action = nullptr; 
		delete owner; 
	}
};

struct Action
{
	Base* actionEvent;
public :
	template<class TCast, class TOwner>
	void Bind(TOwner* _owner, TCast(TOwner::* _action)()) //&Owner::Method
	{
		ActionEvent<TCast, TOwner>* _actionEvent = new ActionEvent<TCast, TOwner>();
		_actionEvent->Bind(_owner, _action);
		actionEvent = _actionEvent; 
	}
	void Invoke()
	{
		if (!actionEvent)
			return;
		actionEvent->Invoke();
	}
	void Remove()
	{
		actionEvent->Remove();
		delete actionEvent; 
	}
};

