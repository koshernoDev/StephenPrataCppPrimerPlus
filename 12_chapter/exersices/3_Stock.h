#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>

class Stock
{
public:
  Stock();
  Stock(const char*, long n = 0, double pr = 0.0);
  ~Stock();

  void buy(long, double);
  void sell(long, double);
  void update(double);
  const Stock& topVal(const Stock&) const;

  friend std::ostream& operator<<(std::ostream&, const Stock&);

private:
  char* companyName_;
  int shares_;
  double shareVal_;
  double totalVal_;

  void setTotal() {totalVal_ = shares_ * shareVal_;}	
};

#endif // STOCK_H_