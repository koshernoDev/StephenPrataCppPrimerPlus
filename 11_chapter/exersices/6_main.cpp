#include <iostream>
#include "6_Stonewt.h"

int main()
{
  Stonewt masses[6] = {
  	100, 150, 85
  };

  for (int i = 3; i < 6; ++i) {
  	double value;
  	std::cin >> value;
    masses[i] = value;
  }


  Stonewt min, max;
  min = max = masses[0];
  int count = 0;

  for (int i = 1; i < 6; ++i) {
  	if (min > masses[i]) {
  		min = masses[i];
  	}
  	if (max < masses[i]) {
  		max = masses[i];
  	}
    Stonewt compare(11, 0.0);
    if (masses[i] >= compare) {
    	++count;
    }
  }

  std::cout << "Minimal: " << min << "Maximal: " << max 
       << "More or equal 11 stones: " << count << std::endl;

	return 0;
}