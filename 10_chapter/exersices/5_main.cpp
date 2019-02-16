#include <iostream>
#include <cctype>
#include "5_Stack.h"

namespace 
{
	enum {MIN = 0, MAX = 3};
}

void showDialogue(int n);

int main()
{
  using std::cout;
  using std::cin;
  using std::endl;

  Stack stack;
  Customer customer;

  int ix = 0;
  char enter;
  double totalPayment = 0;

  showDialogue(ix);

  while (cin >> enter && toupper(enter) != 'Q') {
  	while (cin.get() != '\n') {
  		continue;
  	}

  	enter = toupper(enter);  	

  	bool isAorP = (enter == 'A') || (enter == 'P');
  	bool isOther = !isalpha(enter);

  	if (!isAorP || isOther) {
  		cout << "\n          <Wrong enter!>\n";
  		showDialogue(ix); 

  		continue;
  	}


    switch (enter) {
    	case 'A' :
        if (stack.isFull() == true) {
    	  	cout << "\n    <Stack overflowed.>\n";
    	  	showDialogue(ix);    	
          
          if (ix > MAX) {
    	  	  --ix;
          }
    	  	continue;
    	  }

    	  cout << "\n Enter customer's name: ";
    	  getline(cin, customer.fullName);
    	  cout << " Enter his payment: ";
    	  cin >> customer.payment;
    	  
    	  stack.push(customer);
    	 
    	  ++ix;

    	  break;

    	case 'P' :
    	  if (stack.isEmpty() == true) {
    	  	cout << "\n    <Stack already empty.>\n";
    	  	showDialogue(ix);    	

          if (ix < MIN) {
    	      ++ix;
          }
    	  	continue;
    	  }
    	  else {
    	  	stack.pop(customer);
          --ix;
    	  	cout << "\n Customer #" << ix + 1 << " popped.\n"
    	  	     << " His name is: " << customer.fullName << endl
    	  	     << " His payment was = " << customer.payment << endl;

          totalPayment += customer.payment;

          cout << "\n Total payment = " << totalPayment << endl;
    	  }

    	  break;
    }

    showDialogue(ix); 
  }

  cout << "\n            <Bye!>\n"
       << "<><><><><><><><><><><><><><><><><><><><>\n";

	return 0;
}

void showDialogue(int n)
{
	std::cout << "<><><><><><><><><><><><><><><><><><><><>\n"
	          << "Amount of customers in stack = " << n << std::endl;
	std::cout << "Please enter A to add a customer,\n"
            << "P to process a customer, or Q to quit: ";
}