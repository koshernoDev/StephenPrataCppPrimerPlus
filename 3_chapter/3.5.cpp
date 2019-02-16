//Prata 3.5
#include <iostream>

using namespace std;

int main(){
	long long worlds_popularion{7554435699};
	long long russia_population{146804372};

	cout << "Enter the world's population: ";
	cin >> worlds_popularion;
	cout << "\nEnter the population of Russia: ";
	cin >> russia_population;

	double russias_of_worlds = double(russia_population)/double(worlds_popularion)*100;

	cout << "\nThe population of the Russia is " << russias_of_worlds << " of the world popularion\n";

	return 0;
}