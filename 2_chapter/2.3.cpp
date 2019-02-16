//Prata 2.3
#include <iostream>

using namespace std;

void three_blind_mice();
void see_how_they_run();

int main()
{
	three_blind_mice();
	three_blind_mice();
	see_how_they_run();
	see_how_they_run();

	return 0;
}

void three_blind_mice()
{
	cout << "Three blind mice\n";
}

void see_how_they_run()
{
	cout << "See how they run\n";
}