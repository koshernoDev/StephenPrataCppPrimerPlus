#ifndef GOLF_H
#define GOLF_H
#include <string>

class Golf
{
  public:
  	Golf(const std::string& name, int hc = 0);
  	Golf();
  	void setHandicap(int hc);
  	void show();

  private:
  	std::string fullName_;
  	int handicap_;
};

#endif