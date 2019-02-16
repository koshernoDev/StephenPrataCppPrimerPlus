//4.3
#include <iostream>
#include <cstring>

using namespace std;

struct user{
	char first_name[20];
	char second_name[20];
};

int main(){
	user first;

	cout << "Enter your first name: ";
	cin >> first.first_name;
	cout << "Enter your last name: ";
	cin >> first.second_name;

	char first_and_second[30];

	strcat(first_and_second, first.second_name);
	strcat(first_and_second, ", ");
	strcat(first_and_second, first.first_name);

	cout << first_and_second << endl;

	return 0;
}