#include "1_Cow.h"

int main()
{
  Cow simple("Murka", "Loto", 550.24);
  simple.showCow();

  Cow other(simple);
  other.showCow();

  Cow another;
  another.showCow();
  Cow temp("Winner", "Gwent", 234.34);
  another = temp;
  another.showCow();

  another = Cow("Hello", "C++", 111.11);
  another.showCow();

	return 0;
}