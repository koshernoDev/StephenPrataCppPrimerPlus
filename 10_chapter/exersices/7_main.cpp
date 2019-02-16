#include "7_Plorg.h"

int main()
{
  Plorg simple;

  simple.showPlorg();
  simple.setCI(34);
  simple.showPlorg();
  simple = Plorg("Altair", 54);
  simple.showPlorg();

	return 0;
}