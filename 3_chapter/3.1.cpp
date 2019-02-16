//Prata 3.1
#include <iostream>

using namespace std;

int main(){
	const int feets_in_inches{12};
	int growth{};

	cout << "Enter your growth in inches: __\b\b";
	cin >> growth;

	int growth_in_feets = growth / feets_in_inches;
	int growth_in_inches = growth % feets_in_inches;

	cout << endl << "Your growth in feets is " << growth_in_feets;
	cout << " feets and " << growth_in_inches << " inches\n";

	return 0;
}