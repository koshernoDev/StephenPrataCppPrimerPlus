#include <iostream>
#include "7_Complex.h"

int main()
{
  using std::cout;
  using std::endl;
  using std::cin;

  Complex a(3.0, 4.0);
  Complex c;

  cout << "Enter a complex number (q to quit):\n";

  while (cin >> c) {
  	cout << "c is " << c
  	     << "complex conjugate is " << ~c
  	     << "a is  " << a
  	     << "a + c is " << a + c
  	     << "a - c is " << a - c
  	     << "a * c is " << a * c
  	     << "2 * c is " << 2 * c
  	     << "Enter a complex number (q to quit):\n";
  }

  cout << "Done!\n";

  return 0;
}