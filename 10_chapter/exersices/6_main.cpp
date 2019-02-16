#include "6_Move.h"

int main() 
{
  Move first;

  first.reset(4.0, 5.0);
  first.showMove();

  Move second(1.4, 2.3);

  second = second.add(first);
  second.showMove();

  second.reset();
  second.showMove();

	return 0;
}