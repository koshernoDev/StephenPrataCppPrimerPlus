#include "8_List.h"

int main()
{
  List simple;

  simple.addItem(45.34);
  simple.visitItem(0, show);
  simple.addItem(654.4);
  simple.visitItem(1, show);
  simple.addItem();
  simple.visitItem(2, show);
  simple.visitItem(5, show);
  simple.visitItem(1, reset);
  simple.visitItem(1, show);
  simple.visitItem(0, square);
  simple.visitItem(0, show);

  List overload;

  for (int i = 0; i < 12; ++i) {
  	overload.addItem(i);
  	overload.visitItem(i, show);
  }

	return 0;
}