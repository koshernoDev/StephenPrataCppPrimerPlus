#include <iostream>
#include <cstdlib>
#include <ctime>
#include "5_queue.h"

const int MIN_PER_HR = 60; // Minutes per hour

// Is there a new customer?
bool newCustomer(const double);
// Adds the new customer in the rare of queue
void addCustomer(Queue&, Item&, long&, const long&);
// Customer works with ATM
void workWithATM(Queue&, Item&, long&, long&, long&, const long&);

int main()
{
  using std::cin;
  using std::cout;
  using std::endl;

  std::srand(std::time(0)); // Set random number with system time

  // Modeling time input
  cout << "Case Study: Bank of Heather Automatic Teller\n"
       << "Enter the number of simulation hours: ";
  int hours;
  cin >> hours;

  long perHour = 0;           // Customers per hour, we are looking for it
  double averageWaitTime = 0; // An average wait time if there are perHour
                              // customers int the queue
  
  // Searching amount of customers per hour resulting to average
  // wait time equal or less 1 minute loop
  for (perHour = 1; averageWaitTime <= 1; ++perHour) {
  	Item client;                     // Customer
  	Queue firstQueue, secondQueue; // Twice ATM
  	long served = 0;               // Total served customers
  	long queuesWait = 0;           // Total waiting time to both ATM
  	long customers = 0;            // Total customers came to queue
  	long firstPrTime = 0;          // Customer's working time with first ATM
  	long secondPrTime = 0;         // Customer's working time with second ATM
  	long cycleLimit = MIN_PER_HR * hours;     // Modeling time
  	double custPerMin = MIN_PER_HR / perHour; // Customers per minute

    // Modeling with 2 ATM's loop
  	for (long cycle = 0; cycle < cycleLimit; ++cycle) {

      // Is there a new customer?
  		bool isNewCustomer = newCustomer(custPerMin);
  		// Is there a free queue?
  		bool isThereEmptyQueue = (!firstQueue.isFull() or !secondQueue.isFull());
  		if (isNewCustomer and isThereEmptyQueue) {
  			// If the first queue is less than second the customer goes here
  			// and we increase an counter of cliens and set client's arrival and
  			// working with ATM time
        if (firstQueue.size() < secondQueue.size()) {
        		addCustomer(firstQueue, client, customers, cycle);
        }
        // If first is more customer goes there and does the same
        else {
        	// If first is less doesn't means that second isn't full
        	if (!secondQueue.isFull()) {
        		addCustomer(secondQueue, client, customers, cycle);
        	}
        }
  		}

      // If the first ATM isn't busy and its queue isn't empty
      // we get client's working with ATM time, increase total wait time
      // in booth queues by his waiting time and working time and
      // increase counter of served clients
  		if (firstPrTime <= 0 && !firstQueue.isEmpty()) {
  			workWithATM(firstQueue, client, firstPrTime, queuesWait,
  				               served, cycle);
  		}

      // If the second ATM isn't busy and its queue isn's empty do same 
  		if (secondPrTime <= 0 && !secondQueue.isEmpty()) {
  			workWithATM(secondQueue, client, secondPrTime, queuesWait,
  				               served, cycle);
  		}

      // If the first ATM is busy, decrease its working time with client
  		if (firstPrTime > 0) {
  			--firstPrTime;
  		}

      // If the second ATM is busy, decrease its working time with client
  		if (secondPrTime > 0) {
  			--secondPrTime;
  		}
  	}

    // If there were any clients calculate condition of main loop
  	if (customers > 0) {
  		averageWaitTime = (double) queuesWait / served;
  	}
  }

  // Result output
  cout << "\nAmount of clients per hour resulting to average wait\n"
       << "time equal or less 1 minute = " << perHour << endl;

	return 0;
}

bool newCustomer(const double x)                 
{
	return (std::rand() * x / RAND_MAX < 1);
}

void addCustomer(Queue& queue, Item& client, long& amount, const long& i)
{
  ++amount;
  client.set(i);
  queue.enQueue(client);
}

void workWithATM(Queue& queue, Item& client, long& prTime, 
	                    long& lWait, long& amount, const long& i)
{
	queue.deQueue(client);
	prTime = client.ptime();
	lWait += i - client.when();
	++amount;
}	   
