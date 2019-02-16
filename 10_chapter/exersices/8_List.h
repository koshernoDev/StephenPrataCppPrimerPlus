#ifndef LIST_H_
#define LIST_H_

typedef double Item;
typedef void (*visit)(Item&);

void resetItem(Item& item);
void squareItem(Item& item);
void showItem(Item& item);

namespace 
{
	visit reset = resetItem;
  visit square = squareItem;
  visit show = showItem;
}

class List 
{
public:
  List();
  bool addItem(const Item& item = 0.0);
  bool isEmpty() const;
  bool isFull() const;
  void visitItem(int n, visit act);

private:
	enum {LIST_SIZE = 10};
	Item items_[LIST_SIZE];
	int top_;
};

#endif