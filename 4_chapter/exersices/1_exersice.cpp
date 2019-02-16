//4.1 
#include <iostream>
#include <string>

using namespace std;

struct student{
	string first_name;
	string second_name;
	char grade;
	short age;
};

int main(){
	student first;

	cout << "What is your first name? ";
	getline(cin, first.first_name);
	cout << "What is your last name? ";
	cin >> first.second_name;
	cout << "What letter grade do you deserve: ";
	cin >> first.grade;
	cout << "What is your age? ";
	cin >> first.age;

	first.grade += 1;

	cout << "\nName: " << first.second_name << ", " << first.first_name << endl;
	cout << "Grade: " << first.grade << endl;
	cout << "Age: " << first.age << endl;

	return 0;
}