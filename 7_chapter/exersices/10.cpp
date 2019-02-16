/*Спроектируйте функцию calculate (), которая принимает два значения типа
double и указатель на функцию, принимающую два аргумента double и 
возвращающую значение double. Функция calculate () также должна иметь тип
double и возвращать значение, вычисленное функцией, которая задана 
указателем, используя аргумент double функции calculate (). Например, 
предположим, что имеется следующее определение функции add ():
double add(double x, double y)
{
return x + y;
}
Приведенный ниже вызов функции должен заставить calculate () передать
значения 2.5 и 10.4 функции add () и вернуть ее результат (12.9):
double q = calculate (2.5, 10.4, add);
Используйте в программе эти функции и еще хотя бы одну дополнительную, 
которая подобна add(). В программе должен быть организован цикл, 
позволяющий пользователю вводить пары чисел. Для каждой пары calculate () должна
вызвать add () и хотя бы еще одну функцию такого рода. Если вы чувствуете
себя уверенно, попробуйте создать массив указателей на функции, подобные
add (), и организуйте цикл, применяя calculate () для вызова этих функций
по их указателям. Подсказка: вот как можно объявить массив из трех таких 
указателей:
double (*pf[3])(double, double);
Инициализировать такой массив можно с помощью обычного синтаксиса 
инициализации массивов и имен функций в качестве адресов.*/
#include <iostream>

using namespace std;

typedef double (*pf_calc)(double, double);

double calculate(double, double, pf_calc);
double add(double, double);
double deduct(double, double);
double divide(double, double);
double multiple(double, double);
double surplus(double, double);

const short AMOUNT = 5;

int main() {
	double a, b;

	pf_calc pf_calc_arr[AMOUNT] = {add, deduct, divide, multiple, surplus};
	pf_calc (*p)[AMOUNT] = &pf_calc_arr;

	while (cin >> a >> b) {
	short ix = 0;
		while (ix < AMOUNT) {
			cout << calculate(a, b, (*p)[ix]) << endl;
			++ix;
		}
	}

	return 0;
}

double calculate(double a, double b, pf_calc f_calc) {
	double result = f_calc(a, b);
	return result;
}

double add(double a, double b) {
	cout << "Add = ";
	return a + b;
}

double deduct(double a, double b) {
	cout << "Deduct = ";
	return a - b;
}

double divide(double a, double b) {
	cout << "Divide = ";
	return a / b;
}

double multiple(double a, double b) {
	cout << "Multiple = ";
	return a * b;
}

double surplus(double a, double b) {
	cout << "Surplus = ";
	return (int)a % (int)b;
}