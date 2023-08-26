#pragma once
#include <string>
class Property
{
protected:
	int id;
	std::string type;

public:
	Property();
	Property(int id);
	~Property();
	virtual void Display() = 0;
};

