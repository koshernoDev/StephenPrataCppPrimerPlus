#include "4.h"
#include <iostream>

namespace sales {
	void setSales(Sales& sales, const double ar[], int n) {
		if (n > QUARTERS) {
			std::cout << "Wrong amount of quarters." 
								<< "Shall be less than 4\n";
			return;
		}

		int ix;
		sales.sales[0] = sales.min = sales.max = sales.average = ar[0];

		for (ix = 1; ix < n; ++ix)
		{
			sales.sales[ix]	= ar[ix];
			sales.average += ar[ix];
			if (ar[ix] > sales.max) {
				sales.max = ar[ix];
			}
			if (ar[ix] < sales.min) {
				sales.min = ar[ix];
			}
		}

		sales.average /= ix;

		for (; ix < QUARTERS; ++ix) {
			sales.sales[ix] = 0;
		}
	}

	void setSales(Sales& sales) {
		int ix;
		for (ix = 0; ix < QUARTERS; ++ix) {
			std::cout << "Enter sales for " << ix + 1 << " quarter: ";
			std::cin >> sales.sales[ix];
			if (!ix) {
				sales.max = sales.sales[ix];
				sales.min = sales.sales[ix];
			}
			sales.average += sales.sales[ix];
			if (sales.sales[ix] > sales.max) {
				sales.max = sales.sales[ix];
			}
			if (sales.sales[ix] < sales.min) {
				sales.min = sales.sales[ix];
			}
		}

		sales.average /= ix;
	}

	void showSales(const Sales& sales) {
		for (int i = 0; i < QUARTERS; ++i) {
			if (sales.sales[i] != 0) {
				std::cout << "Sales for " << i + 1 << " quarter: "	
									<< sales.sales[i] << std::endl;
			}
			else {
				std::cout << "There are no sales in " << i + 1 << " quarter\n";
			}
		}
		std::cout << "Minimal sales = " << sales.min << std::endl
							<< "Maximal sales = " << sales.max << std::endl
							<< "Average sales = " << sales.average << std::endl;
	}
}