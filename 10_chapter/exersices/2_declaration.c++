#include "2_class_Person.h"
#include <cstring>

Person::Person(const std::string& lastName, const char* firstName) 
{
	lastName_ = lastName;
	std::strcpy(firstName_, firstName);
}

void Person::showPerson() const 
{
  std::cout << firstName_ << ' ' << lastName_ << std::endl;
}

void Person::formalShowPerson() const
{
	std::cout << lastName_ << ", " << firstName_ << std::endl;
}