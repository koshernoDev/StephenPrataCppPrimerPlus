#include <iostream>
#include "5_Stonewt.h"

int main()
{
  using std::cout;
  using std::endl;

  Stonewt first;
  cout << first;
  first.reset(7, 16.5);
  cout << first;

  Stonewt second(5, 12.3);
  cout << second;
  second.setForm(Stonewt::FLOAT_POUND);
  cout << second;
  second.setForm(Stonewt::POUND);
  cout << second;

  Stonewt third = first + second;
  cout << third;
  cout << first - second;
  cout << third * 2 << 3 * third;
  
	return 0;
}