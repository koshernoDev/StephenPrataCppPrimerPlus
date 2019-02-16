#include "1_CD.h"
#include <iostream>
#include <cstring>

CD::CD()
{
	performers_[0] = '\0';
	label_[0] = '\0';
	selections_ = 0;
	playtime_ = 0;
}

CD::CD(const char * performers,const char * label, int selections, double playtime)
{
  strcpy(performers_, performers);
  strcpy(label_, label);
  selections_ = selections;
  playtime_ = playtime;
}

CD::CD(const CD & cd)
{
	strcpy(performers_, cd.performers_);
  strcpy(label_, cd.label_);
  selections_ = cd.selections_;
  playtime_ = cd.playtime_;
}

void CD::report() const
{
	std::cout << "Performers is " << performers_ << std::endl
	          << "Label is " << label_ << std::endl
	          << "Selections = " << selections_ << std::endl
	          << "Playtime = " << playtime_ << std::endl;
}

CD & CD::operator=(const CD & cd)
{
	if (this == &cd) {
		return *this;
	}

	strcpy(this->performers_, cd.performers_);
	strcpy(this->label_, cd.label_);
	this->selections_ = cd.selections_;
	this->playtime_ = cd.playtime_;

	return *this;
}

CD::~CD(){}

Classic::Classic()
{
	name_[0] = '\0';
}

Classic::Classic(const char * name,const char * performers,const char * label, 
	               int selections, double playtime) : 
                 CD(performers, label, selections, playtime)
{
  strcpy(name_, name);
}

Classic::Classic(const char * name, const CD & cd) : CD(cd)
{
	strcpy(name_, name);
}

void Classic::report() const
{
	std::cout << "Name is " << name_ << std::endl;
	CD::report();
}

Classic & Classic::operator=(const Classic & classic)
{
	if (this == &classic) {
		return *this;
	}
  
  CD::operator=(classic);
	strcpy(this->name_, classic.name_);

	return *this;
}

Classic::~Classic(){}