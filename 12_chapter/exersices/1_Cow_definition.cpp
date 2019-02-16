#include "1_Cow.h"
#include <iostream>
#include <cstring>

Cow::Cow()
{
	name_[0] = '\0';
	hobby_ = nullptr;
	weight_ = 0;
}

Cow::Cow(const char* name, const char* hobby, double weight)
{
  strcpy(name_, name);

  hobby_ = new char[strlen(hobby) + 1];
  strcpy(hobby_, hobby);

  weight_ = weight;
}

Cow::Cow(const Cow& cow)
{
	strcpy(name_, cow.name_);

	hobby_ = new char[strlen(cow.hobby_) + 1];
	strcpy(hobby_, cow.hobby_);

	weight_ = cow.weight_;
}

Cow::~Cow()
{
	delete [] hobby_;
}

Cow& Cow::operator=(const Cow& cow)
{
  strcpy(this->name_, cow.name_);

	this->hobby_ = new char[strlen(cow.hobby_) + 1];
	strcpy(this->hobby_, cow.hobby_);

	this->weight_ = cow.weight_;

	return *this;
}

void Cow::showCow() const
{
  if (this->hobby_ != nullptr) {
	  std::cout << "Cow's name is " << name_ << ", "
	            << "hobby is " << hobby_ << ", "
	            << "weight is " << weight_ << std::endl;
  }
  else {
  	std::cout << "Empty object.\n";
  }
}