#include "4_Stack.h"

Stack::Stack(int n)
{
	if (n <= MAX) {
	  size_ = n;
	  items_ = new Item[size_];
	  top_ = 0;
	}
	else {
		std::cout << "Wrong stack size!\n";
	}
}

Stack::Stack(const Stack& stack)
{
  size_ = stack.top_;
  items_ = new Item[size_];
  
  for (top_ = 0; top_ < size_; ++top_) {
  	items_[top_] = stack.items_[top_];
  }
}

Stack::~Stack()
{
	delete [] items_;
}

bool Stack::isEmpty() const
{
	return top_ == 0;
}

bool Stack::isFull() const
{
	return top_ == size_;
}

bool Stack::push(const Item& item)
{
  if (top_ < size_) {
  	items_[top_++] = item;
  	return true;
  }
  else {
  	return false;
  }
}

bool Stack::pop(Item& item)
{
  if (top_ > 0) {
  	item = items_[--top_];
  	return true;
  }
  else {
  	return false;
  }
}

Stack& Stack::operator=(const Stack& stack)
{ 
  size_ = stack.top_;
  items_ = new Item[size_];
  
  for (top_ = 0; top_ < size_; ++top_) {
  	items_[top_] = stack.items_[top_];
  }

  return *this;  
}