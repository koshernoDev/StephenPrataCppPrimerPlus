namespace sales {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales& sales, const double ar[], int n);
	void setSales(Sales& sales);
	void showSales(const Sales& sales);
}