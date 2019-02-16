//Prata 3.6
#include <iostream>

using namespace std;

int main(){
	int kilometers{};
	int liters{};

	cout << "Enter the kilometers's driven: ";
	cin >> kilometers;
	cout << "\nEnter the liters's burnt: ";
	cin >> liters;

	float liters_per_100 = float(liters)/float(kilometers)*100;

	cout << "\nYour car expends " << liters_per_100 << " liters per 100 kilometers\n";

	return 0;
}