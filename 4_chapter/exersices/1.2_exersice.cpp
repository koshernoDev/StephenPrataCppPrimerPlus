//4.1.2 пробую указатели
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
	student * pt = new student;

	/*cout << pt << endl; 	// ......................................кратный sizeof(string)
	cout << sizeof(* pt) << endl;
	cout << sizeof(string)*2 + sizeof(char) + sizeof(short) << endl;
	cout << sizeof(student) << endl; 	//...........................https://habrahabr.ru/post/90580/*/

	cout << "What is your first name? ";
	getline(cin, pt->first_name);
	cout << "What is your last name? ";
	cin >> pt->second_name;
	cout << "What letter grade do you deserve: ";
	cin >> pt->grade;
	cout << "What is your age? ";
	cin >> pt->age;

	pt->grade += 1;

	cout << "\nName: " << pt->second_name << ", " << pt->first_name << endl;
	cout << "Grade: " << pt->grade << endl;
	cout << "Age: " << pt->age << endl;

	delete pt;

	return 0;
}