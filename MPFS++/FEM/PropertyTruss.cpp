#include "PropertyTruss.h"
#include <iostream>

PropertyTruss::PropertyTruss()
	:Property{-1}, A{0.0}
{
}

void PropertyTruss::SetId(int id)
{
	id = id;
}

void PropertyTruss::SetA(double A)
{
	A = A;
}

void PropertyTruss::Display()
{
	std::cout << "Property #" << id << ", Type: " << type << std::endl;
}
