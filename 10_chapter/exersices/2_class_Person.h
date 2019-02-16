#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>

class Person 
{
  public:
  	Person() {lastName_ = ""; firstName_[0] = '\0';}
  	Person(const std::string& lastName, const char* firstName = "Heyyou");
    void showPerson() const;
    void formalShowPerson() const;

  private:
    enum {LIMIT = 25};
    std::string lastName_;
    char firstName_[LIMIT];
};

#endif