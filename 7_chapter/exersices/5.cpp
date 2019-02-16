/*Определите рекурсивную функцию, принимающую целый аргумент и 
возвращающую его факториал. Вспомните, что факториал 3 записывается, как 3! и
вычисляется как 3x2! и т.д., причем 0! равно 1. В общем случае, если п больше
нуля, топ!=п* (п-1)!. Протестируйте функцию в программе, использующей
цикл, где пользователь может вводить различные значения, для которых 
программа вычисляет и отображает факториалы.*/
#include <iostream>

using namespace std;

long double factorial(int);

int main() {
	int n;
	
	while (cin >> n) {
		cout << "Factorial " << n << " = " << factorial(n) << endl;
	}

	return 0;
}

long double factorial(int n) {
	long double result = 1.0;
	if (n) {
		result = factorial(n - 1) * n;
	}
	return result;
}