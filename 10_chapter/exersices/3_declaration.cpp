#include "3_class_Golf.h"
#include <iostream>

Golf::Golf(const std::string& name, int hc) 
{
	fullName_ = name;
	handicap_ = hc;
}

Golf::Golf()
{
	std::cout << "Enter name: ";
  getline(std::cin, fullName_);

  std::cout << "Enter handicap: ";
  (std::cin >> handicap_).get();
}

void Golf::setHandicap(int hc)
{
	handicap_ = hc;
}

void Golf::show()
{
	std::cout << "Name: " << fullName_ << std::endl
	          << "Handicap: " << handicap_ << std::endl;
}