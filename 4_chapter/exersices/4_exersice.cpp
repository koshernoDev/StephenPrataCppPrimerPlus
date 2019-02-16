//4.4
#include <iostream>
#include <string>

using namespace std;

struct user{
	string first_name;
	string second_name;	
};

int main(){
	user first;

	cout << "Enter your first name: ";
	cin >> first.first_name;
	cout << "Enter youe second name: ";
	cin >> first.second_name;

	cout << first.second_name + ", " + first.first_name << endl;

	return 0;
}