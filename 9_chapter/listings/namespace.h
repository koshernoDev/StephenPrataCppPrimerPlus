#include <string>

namespace pers {
	struct Person {
		std::string fname;
		std::string lname;
	};
	void get_Person(Person&);
	void show_Person(const Person&);
}

namespace debts {
	using namespace pers;

	struct Debt {
		Person name;
		double amount;
	};
	void get_Debt(Debt&);
	void show_Debt(const Debt& rd);
	double sum_Debts(const Debt ar[], int n);
}