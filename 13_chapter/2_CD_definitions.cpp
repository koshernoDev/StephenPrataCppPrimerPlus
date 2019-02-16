#include "2_CD.h"
#include <iostream>
#include <cstring>

CD::CD()
{
	performers_ = nullptr;
	label_ = nullptr;
	selections_ = 0;
	playtime_ = 0;
}

CD::CD(const char * performers, const char * label, int selections, double playtime)
{
  performers_ = new char[strlen(performers) + 1];
  strcpy(performers_, performers);
  label_ = new char[strlen(label) + 1];
  strcpy(label_, label);
  selections_ = selections;
  playtime_ = playtime;
}

CD::CD(const CD & cd)
{
	delete [] performers_;
	performers_ = new char[strlen(cd.performers_) + 1];
	strcpy(performers_, cd.performers_);
	delete [] label_;
	label_ = new char[strlen(cd.label_) + 1];
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
  
  delete [] this->performers_;
  this->performers_ = new char[strlen(cd.performers_) + 1];
	strcpy(this->performers_, cd.performers_);
	delete [] this->label_;
	this->label_ = new char[strlen(cd.label_) + 1];
	strcpy(this->label_, cd.label_);
	this->selections_ = cd.selections_;
	this->playtime_ = cd.playtime_;

	return *this;
}

CD::~CD()
{
	delete [] performers_;
	delete [] label_;
}

Classic::Classic()
{
	name_ = nullptr;
}

Classic::Classic(const char * name, const char * performers, const char * label, 
	               int selections, double playtime) : 
                 CD(performers, label, selections, playtime)
{
	name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
}

Classic::Classic(const char * name, const CD & cd) : CD(cd)
{
	name_ = new char[strlen(name) + 1];
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
  delete [] this->name_;
  name_ = new char[strlen(classic.name_) + 1];
	strcpy(this->name_, classic.name_);

	return *this;
}

Classic::~Classic()
{
	delete [] name_;
}