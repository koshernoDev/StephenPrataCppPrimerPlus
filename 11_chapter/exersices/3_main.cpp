#include <iostream>
#include <cstdlib>
#include <ctime>
#include "2_Vector.h"

int main()
{
  using namespace vector;
  using namespace std;

  srand(time(0));

  cout << "Enter amount of repeats (q to quit): ";
  int repeats;

  while (cin >> repeats) {
    cout << "Enter target distance: ";
    double target;
    cin >> target;

    cout << "Enter step length: ";
    double stepLenght;
    if (!(cin >> stepLenght)) {
      break;
    }

    unsigned long* stepsAmount = new unsigned long[repeats];
    Vector step;
    Vector result(0.0, 0.0);

    unsigned long min = 0;
    unsigned long max = 0;
    unsigned long average = 0;

    for (int i = 0; i < repeats; ++i) {
    unsigned long steps = 0;

      while (result.moduleValue() < target) {
        double direction;
        direction = rand() % 360;
        step.reset(stepLenght, direction, Vector::POL);
        result = result + step;
        ++steps;
      }

      result.reset(0.0, 0.0);

      stepsAmount[i] = steps;

      if (i == 0) {
        min = max = average = steps;
      }

      if (min > stepsAmount[i]) {
        min = stepsAmount[i];
      }
      if (max < stepsAmount[i]) {
        max = stepsAmount[i];
      }
      average += stepsAmount[i];
    }

    delete [] stepsAmount;

    average /= repeats;

    cout << "Minimal steps = " << min << ", "
         << "maximal steps = " << max << ", "
         << "average steps = " << average << ".\n"
         << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";

    cout << "Enter amount of repeats (q to quit): ";
  }

  return 0;
}