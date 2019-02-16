/*Измените программу из листинга 8.14 так, чтобы использовать две шаблонных
функции по имени SumArray (), возвращающие сумму содержимого массива 
вместо его отображения. Программа должна сообщать общее количество предметов
и сумму всех задолженностей (debts).*/
#include <iostream>
using namespace std;

template <typename T>
T sum_array(T*, short);
template <typename T>
T sum_array(T*[], short);

struct debts {
	char name[50];
	double amount;
};

int main() {
	int things[6] = {3, 6, 3, 5, 2, 1};
	debts mr_e[3] = {
		{"Ima Wolfe", 5300.40},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];

	for (short ix = 0; ix < 3; ++ix) {
		pd[ix] = &mr_e[ix].amount;
	}

	cout << "Mr. E's sum of things: "
			<< sum_array(things, 6) << endl; 
	cout << "Mr. E's sum of debts: "
			<< sum_array(pd, 3) << endl; 

	return 0;
}

template <typename T>
T sum_array(T* a, short n) {
	T sum = 0;
	for (short ix = 0; ix < n; ++ix) {
		sum += a[ix];
	}
	return sum;
}

template <typename T>
T sum_array(T* a[], short n) {
	T sum;
	for (short ix = 0; ix < n; ++ ix) {
		sum += *a[ix];
	}
	return sum;
}