#include "4.h"

int main() {
	using namespace sales;

	Sales first, second;
	const double sales[QUARTERS] = {440.34, 109.22, 800.00, 450.34};

	setSales(first, sales, 3);
	setSales(second);
	showSales(first);
	showSales(second);

	return 0;
}