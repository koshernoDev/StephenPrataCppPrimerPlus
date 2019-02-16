#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <cmath>
#include "1_Vector.h"

int main()
{
  using vector::Vector;
  using namespace std;

  srand(time(0));

  Vector step(0.0, 0.0);
  Vector result(0.0, 0.0);

  double direction;
  double target;
  double stepLength;
  double distance;

  cout << "Enter target distance (q to quit): ";

  while (cin >> target) {
  	cout << "Enter step length: ";

  	if (!(cin >> stepLength)) {
  		break;
  	}

    while (result.moduleValue() < target) {
    	direction = rand() % 360;
    	step.reset(stepLength, direction, Vector::POL);
    	result = result + step;
    	distance += step.moduleValue();

   		for (int i = 0; i < abs(result.yValue()); ++i) {
    		cout << endl;
    	}
    	for (int i = 0; i < abs(result.xValue()); ++i) {
    		cout << ' ';
    	}
      
      if ((step.xValue() > 0) && (step.yValue() > 0)) {
    	  cout << '>';
      }
      else if ((step.xValue() < 0) && (step.yValue() < 0)) {
        cout << 'v';
      }
      else if ((step.xValue() > 0) && (step.yValue() < 0)) {
      	cout << 'v';
      }
      else if ((step.xValue() < 0) && (step.yValue() > 0)) {
      	cout << '<';
      }

    	usleep(100000);
    	cout << "\033[1;1H";
    	cout << string(50, '\n');
    }

  	result.reset(0.0, 0.0);

  	cout << "Character have walked " << distance << " meters!\n"
  	     << "Enter target distance (q to quit): ";
  }

  cin.clear();
  while (cin.get() != '\n') {
  	continue;
  }

	return 0;
}