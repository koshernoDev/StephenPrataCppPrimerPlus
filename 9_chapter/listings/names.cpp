#include <iostream>
#include "namespace.h"

namespace pers {
	using std::cout;
	using std::cin;

	void get_Person(Person& rp) {
		cout << "Enter first name: ";
		cin >> rp.fname;
		cout << "Enter last name: ";
		cin >> rp.lname;
	}

	void show_Person(const Person& rp) {
		std::cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts {
	void get_Debt(Debt& rd) {
		get_Person(rd.name);
		std::cout << "Enter debt: ";
		std::cin >> rd.amount;
	}

	void show_Debt(const Debt& rd) {
		show_Person(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}

	double sum_Debts(const Debt ar[], int n) {
		double total = 0;
		for (int i = 0; i < n; ++i) {
			total += ar[i].amount;
		}
		return total;
	}
}