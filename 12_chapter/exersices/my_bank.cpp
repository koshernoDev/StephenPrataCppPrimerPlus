#include <iostream>
#include <cstdlib>
#include <ctime>
#include "5_queue.h"

const int MIN_PER_HR = 60;

bool newCustomer(double);

int main()
{
  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;

  std::srand(std::time(0));

  cout << "Case Study: Bank of Heather Automatic Teller\n"
       << "Enter maximum size of queue: ";

  int qs;
  cin >> qs;

  Queue line(qs);

  cout << "Enter the number of simulation hours: ";

  int hours;
  cin >> hours;

  long cycleLimit = MIN_PER_HR * hours;

  cout << "Enter the average number of customers per hour: ";

  double perHour;
  cin >> perHour;

  double minPerCust = MIN_PER_HR / perHour;

  int processTime = 0;
  long turnAways = 0;
  long customers = 0;
  long served = 0;
  long sumLine = 0;
  long lineWait = 0;
  Item temp;

  for (int cycle = 0; cycle < cycleLimit; ++cycle) {
    if (newCustomer(minPerCust)) {
    	if (line.isFull()) {
    		++turnAways;
    	}
    	else {
    		++customers;
    		temp.set(cycle);
    		line.enQueue(temp);
    	}
    }

    if (processTime <= 0 && !line.isEmpty()) {
    	line.deQueue(temp);
    	processTime = temp.ptime();
    	lineWait += cycle - temp.when();
    	++served;
    }

    if (processTime > 0) {
    	--processTime;
    }

    sumLine += line.size();
  }

  if (customers > 0) {
  	cout << "customers accepted: " << customers << endl
  	     << " customers served: " << served << endl
  	     << " turnaways: " << turnAways << endl
  	     << "average queue size: ";
  	cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (double) sumLine / cycleLimit << endl
         << " average wait time: "
         << (double) lineWait / served << " minutes\n";
  }
  else {
  	cout << "No customers!\n";
  }

  cout << "Done!\n";

	return 0;
}

bool newCustomer(double x) 
{
	return (std::rand() * x / RAND_MAX < 1);
}