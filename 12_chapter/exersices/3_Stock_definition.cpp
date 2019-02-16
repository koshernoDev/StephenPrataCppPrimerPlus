#include "3_Stock.h"
#include <cstring>

Stock::Stock()
{
	companyName_ = new char[8];
	strcpy(companyName_, "no name");
  shares_ = 0;
  shareVal_ = 0.0;
  totalVal_ = 0.0;
}

Stock::Stock(const char* string, long n, double pr)
{
	companyName_ = new char[strlen(string) + 1];
	strcpy(companyName_, string);

	if (n < 0) {
		std::cout << "Number of shares can't be negative; "
		          << companyName_ << " shres set to 0.\n";
		shares_ = 0;
	}
	else {
		shares_ = n;
	}

  shareVal_ = pr;

  setTotal();
}

Stock::~Stock()
{
	delete [] companyName_;
}

void Stock::buy(long num, double price)
{
	if (num < 0) {
		std::cout << "Number of shares purchased can't be negative. "
		          << "Transaction is aborted.\n";
	}
	else {
		shares_ += num;
		shareVal_ = price;
		setTotal();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0) {
		std::cout << "Number of shares sold can't be negative. "
		          << "Transaction is aborted.\n";
	}
	else if (num > shares_) {
		std::cout << "You can't sell more than you have! "
		          << "Transaction is aborted.\n";
	}
	else {
		shares_ -= num;
		shareVal_ = price;
		setTotal();
	}
}

void Stock::update(double price)
{
	shareVal_ = price;
	setTotal();
}

const Stock& Stock::topVal(const Stock& stock) const
{
	if (stock.totalVal_ > totalVal_) {
		return stock;
	}
	else {
		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const Stock& stock)
{
	using std::ios_base;

	ios_base::fmtflags orig = 
	     os.setf(ios_base::fixed, ios_base::floatfield);

  std::streamsize prec = os.precision(3);

  os << "Company: " << stock.companyName_
     << " Shares: " << stock.shares_ << std::endl
     << " Share price: $" << stock.shareVal_;

  os.precision(2);

  os << " Total Worth: $" << stock.totalVal_ << std::endl;

  os.setf(orig, ios_base::floatfield);
  os.precision(prec);

  return os;
}