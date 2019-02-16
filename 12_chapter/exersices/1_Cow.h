#ifndef COW_H_
#define COW_H_

class Cow
{
public:
  Cow();
  Cow(const char*, const char*, double);
  Cow(const Cow&);
  ~Cow();

  Cow& operator=(const Cow&);
  void showCow() const;

private:
  char name_[20];
  char* hobby_;
  double weight_;
};

#endif // COW_H_