#pragma once
#include "Property.h"

class PropertyTruss : public Property
{
protected:
	double A;

public:
	PropertyTruss();
	
	void SetId(int id);
	void SetA(double A);
	void Display();
};

