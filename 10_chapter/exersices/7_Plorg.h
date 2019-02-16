#ifndef PLORG_H_
#define PLORG_H_

class Plorg 
{
public:
  Plorg(const char* name = "Plorga", int ci = 50);
  void setCI(int ci);
  void showPlorg() const;

private:
	enum {NAME_LENGHT = 19};
	char name_[NAME_LENGHT];
	int contentmentIndex_;
};

#endif