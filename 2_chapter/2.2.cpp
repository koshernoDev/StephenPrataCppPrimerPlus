//Prata 2.2
#include <iostream>

int main()
{
	using namespace std;

	int distance_furlongs{};

	cout << "Please, enter the distance in furlongs: ";
	cin >> distance_furlongs;
	cout << endl << "The distance in yards: " << distance_furlongs*220 << " yards" << endl;

	return 0;
}