//4.7
#include <iostream>
#include <string>

using namespace std;

struct pizza{
	string name;
	short diameter;
	short mass;
}; 

int main(){
	pizza first;

	cout << "Enter the name of pizza: ";
	getline(cin, first.name);
	cout << "Enter its diameter: ";
	cin >> first.diameter;
	cout << "Enter its mass: ";
	cin >> first.mass;

	cout << "Name of pizza is " << first.name << "\nDiameter is " 
		<< first.diameter << "\nMass is " << first.mass << endl;

	return 0;
}