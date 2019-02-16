#ifndef STACK_H_
#define STACK_H_
#include <string>

struct Customer
{
	std::string fullName;
	double payment;
};

typedef Customer Item;

class Stack 
{
public:
  Stack();
  bool isEmpty() const;
  bool isFull() const;
  bool push(const Item&);
  bool pop(Item&);

private:
	enum {MAX = 3};
	Item items_[MAX];
	int top_;

};

#endif