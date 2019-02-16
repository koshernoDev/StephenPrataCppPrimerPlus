/*//4.4 чтение более одного слова с помощью getline
#include <iostream>

using namespace std;

int main(){
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin.getline(name, ArSize);						// читать до символа новой строки
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << endl;

	return 0;
}*/
//4.2
#include <iostream>
#include <string>

using namespace std;

int main(){
	string name;
	string dessert;

	cout << "Enter your name:";
	getline(cin, name);
	cout << "Enter your favorite dessert:";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << endl;

	return 0;
}