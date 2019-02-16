//4.8
#include <iostream>
#include <string>

using namespace std;

struct pizza{
	string name;
	short diameter;
	short mass;
}; 

int main(){
	pizza * first = new pizza;

	cout << "Enter diameter of pizza: ";
	(cin >> first->diameter).get();
	cout << "Enter its name: ";
	getline(cin, first->name);
	cout << "Enter its mass: ";
	cin >> first->mass;

	cout << "Name of pizza is " << first->name << "\nDiameter is " 
		<< first->diameter << "\nMass is " << first->mass << endl;

	delete first;

	return 0;
}