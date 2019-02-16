//4.10 ввод строки с пробелами
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
	char charr1[20];
	string str;

	cout << "Length of string in charr before input: "
		<< strlen(charr1) << endl;
	cout << "Length of string in str before input: "
		<< str.size() << endl;
	cout << "Enter a line of text:\n";
	cin.getline(charr1, 20);
	cout << "You entered: " << charr1 << endl;
	cout << "Enter another line of text:\n";
	getline(cin, str);
	cout << "You entered: " << str << endl;
	cout << "Length of string in charr after input: "
		<< strlen(charr1) << endl;
	cout << "Length of string in str after input: "
		<< str.size() << endl;

	return 0;
}