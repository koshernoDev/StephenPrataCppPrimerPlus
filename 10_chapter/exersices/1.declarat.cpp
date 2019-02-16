#include "1.h"
#include <string>
#include <iostream>

BankAccount::BankAccount(std::string holderName,
	                       std::string accountNumber,
	                       double balance) 
{
	holderName_ = holderName;
	accountNumber_ = accountNumber;
	balance_ = balance;
}	                   

BankAccount::BankAccount() 
{
	holderName_ = "No name";
	accountNumber_ = "No account number";
	balance_ = 0.0;
}

void BankAccount::showHolder() const
{
	using std::cout;
	using std::endl;

	cout << "  Holder's name: " << holderName_ << endl
       << "  Holder's account number: " << accountNumber_ << endl
       << "  Holder's balance = " << balance_ << endl;
}

void BankAccount::addMoney(double sum)
{
	balance_ += sum;
}

void BankAccount::takeMoney(double sum)
{
  using std::cout;
  using std::endl;

	if (sum > balance_) {
		cout << "\nYou can't take more than you have!\n"
         << "Your current balance = $" << balance_ << endl;
    return;
	}

	balance_ -= sum;
}