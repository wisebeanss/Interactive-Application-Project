#pragma once
class InteractiveObject
{
public:
	InteractiveObject();
	~InteractiveObject();
	virtual void use() = 0;
};

