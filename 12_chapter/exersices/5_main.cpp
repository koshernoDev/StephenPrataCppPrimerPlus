#include <iostream>
#include <cstdlib>
#include <ctime>
#include "5_queue.h"

const int MIN_PER_HR = 60; // Minutes in hour

bool newCustomer(double);  // Is there a new customer?

int main()
{
  using std::cin;
  using std::cout;
  using std::endl;

  std::srand(std::time(0)); // Set random number with system time

  // Modeling time input
  cout << "Case Study: Bank of Heather Automatic Teller\n"
       << "Enter the number of sumulation hours: ";
  int hours;
  cin >> hours; 

  long perHour = 0;           // Customers per hour
  double averageWaitTime = 0; // An average wait time if there are perHour 
                              // customers in the queue

  // Searching amount of customers per hour resulting to average
  // wait time equal or less 1 minute loop
  for (perHour = 1; averageWaitTime <= 1; ++perHour) {

    Item temp;            // A customer
    Queue line;           // A queue to ATM by default = 10
    long served = 0;      // Served customers
    long lineWait = 0;    // Whole time of waiting
 	  long customers = 0;   // Whole amount of customers
    long processTime = 0; // Customer working time with ATM = 1 - 3 minutes
    long cycleLimit = MIN_PER_HR * hours;     // Modeling time in minutes
    double custPerMin = MIN_PER_HR / perHour; // Customers per minute

    // Modeling work with ATM loop
    for (long cycle = 0; cycle < cycleLimit; ++cycle) {

      // If there is a new customer and the queue isn't full,
      // add the new customer to rear, set his prosecc time
      if (newCustomer(custPerMin) && !line.isFull()) {
          ++customers;
          temp.set(cycle);
          line.enQueue(temp);
      }
      
      // If ATM isn't busy, begin its work with a customer,
      // get customer's process time, increase lineWait with
      // wait time of the customer in the queue, increase served counter
      if (processTime <= 0 && !line.isEmpty()) {
      	line.deQueue(temp);
      	processTime = temp.ptime();
      	lineWait += cycle - temp.when();
      	++served;
      }
      
      // If ATM is busy, decrease customers process time
      if (processTime > 0) {
      	--processTime;
      }       
    }
    
    // If were some customers, calculate average wait time of each of them
    if (customers > 0) {
    	averageWaitTime = (double) lineWait / served;
    }
  }
  
  // Result output. Shows a limit of customers waited less or equal
  // 1 minute per modeling time
  cout << " \nAmount of clients per hour resulting to average wait\n"
       << "time equal or less 1 minute = " << perHour << endl;

	return 0;
}

bool newCustomer(double x) 
{
	return (std::rand() * x / RAND_MAX < 1);
}