#include "5_Stack.h"
#include <iostream>

Stack::Stack()
{
	std::cout << "Here is a stack is for " << MAX << " customers.\n";
	top_ = 0;
}

bool Stack::isEmpty() const
{
	return top_ == 0;
}

bool Stack::isFull() const
{
	return top_ == MAX;
}

bool Stack::push(const Item& item) 
{
	if (top_ < MAX) {
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