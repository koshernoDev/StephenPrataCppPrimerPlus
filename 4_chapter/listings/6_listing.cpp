// строковый ввод после числового
#include <iostream>

using namespace std;

int main(){
	cout << "What year was your house buils?\n";
	int year;
	//cin >> year;
	//cin.get(); // или cin.get(ch);
	(cin >> year).get();							// или (cin >> year).get(ch);
	cout << "What is its street address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";

	return 0;
}