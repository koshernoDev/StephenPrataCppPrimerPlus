#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "2_Vector.h"

int main()
{
  using namespace std;
  using vector::Vector;

  // Start value for random numbers generator:
  srand(time(0));

  // File output:
  ofstream fout;
  fout.open("1_output.txt");

  double direction;
  double target;
  double stepLength;
  unsigned long steps = 0;
  Vector step;
  Vector result(0.0, 0.0);

  cout << "Enter target distance (q to quit): ";

  while (cin >> target) {
  	cout << "Enter step length: ";

  	if (!(cin >> stepLength)) {
  		break;
  	}

  	fout << "Target Distanse : " << target
  	     << ", Step Size: " << stepLength << endl;

  	while (result.moduleValue() < target) {
  		direction = rand() % 360;
  		step.reset(stepLength, direction, Vector::POL);
      result = result + step;

      fout << steps << ": " << result << endl;

  		++steps;
  	}

  	cout << "After " << steps << " steps, the subject "
  	     << "has the following location:\n" 
  	     << result << endl;
  	fout << "After " << steps << " steps, the subject "
  	     << "has the following location:\n" 
  	     << result << endl;     

  	result.polarMode();

  	cout << " or\n" << result << endl;
  	fout << " or\n" << result << endl;

  	cout << "Average outward distance per step = "
  	     << result.moduleValue() / steps << endl;
  	fout << "Average outward distance per step = "
  	     << result.moduleValue() / steps << endl;
  
    cout << "<><><><><><><><><><><><><><><><><><><><><><>\n";
    fout << "<><><><><><><><><><><><><><><><><><><><><><>\n";

  	steps = 0;
  	result.reset(0.0, 0.0);

  	cout << "Enter target distance (q to quit): ";
  }

  fout.close();

  cout << "Bye!\n";

  cin.clear();
  while (cin.get() != '\n') {
  	continue;
  }

	return 0;
}