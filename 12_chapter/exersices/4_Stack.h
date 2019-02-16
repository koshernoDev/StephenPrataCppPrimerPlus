#ifndef STACK_H_
#define STACK_H_

#include <iostream>

typedef unsigned long Item;

class Stack
{
public:
  Stack(int n = 10);
  Stack(const Stack&);
  ~Stack();

  bool isEmpty() const;
  bool isFull() const;
  bool push(const Item&);
  bool pop(Item&);
  int top() const {return top_;}

  Stack& operator=(const Stack&);

  enum {MAX = 10};

private:
  Item* items_;
  int size_;
  int top_;
};

#endif // STACK_H_