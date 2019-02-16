#include "4_class_Sales.h"

namespace 
{
	const int SIZE = 4;
}

int main()
{
  Sales twoYears[2];
  for (int i = 0; i < 2; ++i) {
  	twoYears[i].show();
  }

  const double sales[SIZE] = {450.34, 534.54, 124.89, 634.43};
  Sales someYear(sales, 5);
  someYear.show();

	return 0;
}