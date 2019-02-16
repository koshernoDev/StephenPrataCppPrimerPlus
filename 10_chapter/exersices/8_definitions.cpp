#include "8_List.h"
#include <iostream>

List::List()
{
	std::cout << "Here is a list for " << LIST_SIZE << " items.\n";
	for (int i = 0; i < LIST_SIZE; ++i) {
	  items_[i] = 0;
	}

	top_ = 0;
}

bool List::addItem(const Item& item)
{
  if (top_ < LIST_SIZE) {
    items_[top_++] = item;
    return true;
  }
  else {
  	std::cout << "List already full.\n";
  	return false;
  }
}

bool List::isEmpty() const
{
	return top_ == 0;
}

bool List::isFull() const
{
  return top_ == LIST_SIZE;
}

void List::visitItem(int n, visit act)
{
  act(items_[n]);
}

void resetItem(Item& item)
{
  item = 0;
}

void squareItem(Item& item)
{
  item *= item;
}

void showItem(Item& item)
{
	std::cout << "Item value = " << item << std::endl;
}