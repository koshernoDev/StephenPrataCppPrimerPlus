//4.10
#include <iostream>
#include <array>

using namespace std;

int main(){
	array<int, 3> rases;
	int sum{0};

	cout << "Enter 3 results of rases: ";
	for(unsigned short c = 0; c < rases.size(); c++){
		cin >> rases[c];
		sum += rases[c];
	}	

	for(unsigned short c = 0; c < rases.size(); c++){
		cout << c + 1 << " rase result is: " << rases[c] << endl;
	}

	cout << "Average result is: " << sum/rases.size() << endl;

	return 0;
}