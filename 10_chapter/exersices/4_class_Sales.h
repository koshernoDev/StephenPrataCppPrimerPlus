#ifndef SALES_H_
#define SALES_H_

class Sales
{
public:
	Sales(const double ar[], int n);
	Sales();
	void show() const;

private:
	enum {QUARTERS_ = 4, AVERAGE_DEFAULT_ = 0};
	double sales_[QUARTERS_];
	double average_ = AVERAGE_DEFAULT_;
	double max_;
	double min_;
	bool isSet_ = true;
};

#endif