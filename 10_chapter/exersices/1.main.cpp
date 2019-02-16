#include "1.h"
#include <string>
#include <iostream>
#include <cctype>

int main() 
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	BankAccount simpleHolder;

  string name, number;
  double balance;
  cout << "Enter holder's name: ";
  getline(cin, name);
  cout << "Enter new account number: ";
  getline(cin, number);
  cout << "Enter new balance: ";
  (cin >> balance).get();
  cout << endl;
  simpleHolder = BankAccount(name, number, balance);

  simpleHolder.showHolder();

  cout << "\n------------------------------------------\n"
       << "Enter 'A' to add money, 'T' to take money,\n"
       << "'W' to watch your account, or 'Q' to quit: ";

 	char temp;

  while (cin >> temp && toupper(temp) != 'Q') {
  	while (cin.get() != '\n') {
  		continue;
  	}

    cout << endl;

    char ch = toupper(temp);

    switch (ch) {
    	case 'A' :
    	  cout << "  Enter the sum you want to add: ";
    	  cin >> balance;
        simpleHolder.addMoney(balance);
        break;
      case 'T' :
        cout << "  Enter the sum you want to take: ";
        cin >> balance;
        simpleHolder.takeMoney(balance);
        break;
      case 'W' :
        simpleHolder.showHolder();
        break;
    }

    cout << "------------------------------------------\n"
         << "Enter 'A' to add money, 'T' to take money,\n"
         << "'W' to watch your account, or 'Q' to quit: ";
  }

  cout << "Bye!\n";

	return 0;
}