#include "4_Stack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Stack stack;
	unsigned long numbers[Stack::MAX];

  srand(time(0));

	for (int i = 0; !stack.isFull(); ++i) {
		if (!stack.isFull()) {
      numbers[i] = rand() % 50;
	    stack.push(numbers[i]);
	    std::cout << numbers[i] << ", ";
	  }
	  else {
	  	std::cout << "Stack overflow!\n";
	  	break;
	  }
	}

	std::cout << std::endl;

  Stack otherStack(stack);
	unsigned long otherNumbers[Stack::MAX];

	for (int i = 0; !otherStack.isEmpty(); ++i) {
    if (!otherStack.isEmpty()) {
	    otherStack.pop(otherNumbers[i]);
	    std::cout << otherNumbers[i] << ", ";
	  }
	  else {
	  	std::cout << "Stack already empty!\n";
	  	break;
	  }
	}

	std::cout << std::endl;

	for (int i = 0; !otherStack.isFull(); ++i) {
		if (!otherStack.isFull()) {
      otherStack.push(rand() % 100);
	  }
	  else {
	  	std::cout << "Stack overflow!\n";
	  	break;
	  }
	}

	Stack anoterStack = otherStack;

	for (int i = 0; !anoterStack.isEmpty(); ++i) {
    if (!anoterStack.isEmpty()) {
	    anoterStack.pop(otherNumbers[i]);
	    std::cout << otherNumbers[i] << ", ";
	  }
	  else {
	  	std::cout << "Stack already empty!\n";
	  	break;
	  }
	}

	std::cout << std::endl;

	return 0;
}