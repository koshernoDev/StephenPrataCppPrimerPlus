//Prata 3.7
#include <iostream>

using namespace std;

int main(){
	const float kilometers_in_mile{1.609};
	const float gallons_in_liter{3.875};

	float liters_per_100{};
	float miles_per_gallon{};

	cout << "Enter liters per 100 km: ";
	cin >> liters_per_100;

	miles_per_gallon = 100*gallons_in_liter/liters_per_100/kilometers_in_mile;

	cout << "\nMiles per gallon is " << miles_per_gallon << endl;

	return 0;
}