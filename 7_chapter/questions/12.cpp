/*Предположим, что есть следующее объявление структуры:
struct applicant {
char name[3 0] ;
int credit_ratings[3];
};
а. Напишите функцию, которая принимает структуру applicant в качестве 
аргумента и отображает ее содержимое.
б. Напишите функцию, которая принимает адрес структуры applicant в 
качестве аргумента и отображает содержимое структуры, на которую он указывает.*/
#include <iostream>

using std::cout;
using std::endl;

struct applicant {
	char name [30];
	int credit_ratings[3];
};

void show_applicant (const applicant);
void p_show_applicant (const applicant *);

int main(){
	applicant member = {
		"Dima",
		{3, 4, 2}
	};

	show_applicant(member);
	p_show_applicant(&member);

	return 0;
}

void show_applicant(const applicant app) {
	cout << app.name << ":\n";
	for (int ix = 0; ix < 3; ++ix) {
		cout << app.credit_ratings[ix] << " ";
	}
	cout << endl;
}

void p_show_applicant(const applicant * app) {
	cout << app->name << ":\n";
	for (int ix = 0; ix < 3; ++ix) {
		cout << app->credit_ratings[ix] << " ";
	}
	cout << endl;
}