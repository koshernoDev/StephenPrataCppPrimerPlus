#include "7_Plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg(const char* name, int ci)
{
  strcpy(name_, name);
  contentmentIndex_ = ci;
}

void Plorg::setCI(int ci)
{
	contentmentIndex_ = ci;
}

void Plorg::showPlorg() const
{
	std::cout << "Name of plorg is " << name_ << std::endl
	          << "Its contentment index = " << contentmentIndex_ << std::endl;
}