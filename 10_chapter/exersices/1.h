#ifndef BANK_H_
#define	BANK_H_
#include <string>

class BankAccount 
{
  public: 
  	BankAccount(std::string holderName,
  	            std::string accountNumber, 
  	            double balance = 0);
  	BankAccount();
  	~BankAccount() {};
  	void showHolder() const;
  	void addMoney(double sum);
  	void takeMoney(double sum);

  private:
  	std::string holderName_;
  	std::string accountNumber_;
    double balance_;
};

#endif