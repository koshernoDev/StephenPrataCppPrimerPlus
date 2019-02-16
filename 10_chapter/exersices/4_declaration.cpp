#include "4_class_Sales.h"
#include <iostream>

Sales::Sales(const double ar[], int n)
{
	if (n > QUARTERS_) {
		std::cout << ".........................\n"
		          << "Wrong amount of quarters.\n"
		          << "Shall be less than 4\n";
		isSet_ = false;
		return;
	}

	int ix;
	sales_[0] = min_ = max_ = average_ = ar[0];

	for (ix = 1; ix < n; ++ix)
	{
		sales_[ix] = ar[ix];
		average_ += ar[ix];
		if (ar[ix] > max_) {
			max_ = ar[ix];
		}
		if (ar[ix] < min_) {
			min_ = ar[ix];
		}
	}

	average_ /= ix;

	while (ix < QUARTERS_) {
		sales_[ix] = 0;
		++ix;
	}
}

Sales::Sales() 
{
	std::cout  << "..........................\n"; 

	int ix;

	for (ix = 0; ix < QUARTERS_; ++ix) {
		std::cout << "Enter sales for " << ix + 1 << " quarter: ";
		std::cin >> sales_[ix];

		if (ix == 0) {
			max_ = min_ = sales_[ix];
		}

    if (sales_[ix] != 0) {
		  average_ += sales_[ix];
    }

		if (sales_[ix] > max_) {
			max_ = sales_[ix];
		}
		if (sales_[ix] < min_) {
			min_ = sales_[ix];
		}

	}
	
	average_ /= ix;
}

void Sales::show() const
{ 
	if(isSet_ == false) {
		return;
	}

	using std::cout;
	using std::endl;

	cout << ".................\n";

	for (int i = 0; i < QUARTERS_; ++i) {
		if (sales_[i] != 0) {
			cout << "Sales for " << i + 1 << " quarter: "
			     << sales_[i] << endl;
		}
		else {
			cout << "There are no sales in " << i + 1 << " quarter\n";
		}
	}

	cout << "\nMinimal sales = " << min_ << endl
	     << "Maximal sales = " << max_ << endl
	     << "Average sales = " << average_ << endl;
}