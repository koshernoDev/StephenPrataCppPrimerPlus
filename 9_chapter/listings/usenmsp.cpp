#include <iostream>
#include "namespace.h"

void other(void);
void another(void);

int main() {
	using debts::Debt;
	using debts::show_Debt;
	Debt golf = {{"Benny", "Goatsniff"}, 120.0};
	show_Debt(golf);
	other();
	another();

	return 0;
}

void other(void) {
	using std::cout;
	using std::endl;
	using namespace debts;

	Person dg = {"Doodles", "Glister"};

	show_Person(dg);
	cout << endl;

	Debt zippy[3];
	int i;

	for (i = 0; i < 3; ++i) {
		get_Debt(zippy[i]);
	}

	for (i = 0; i < 3; ++i) {
		show_Debt(zippy[i]);
	}

	cout << "Total debt: $" << sum_Debts(zippy, 3) << endl;
	return;
}

void another(void) {
	using pers::Person;
	Person collector = {"Milo", "Rightshift"};
	pers::show_Person(collector);
	std::cout << std::endl;
}