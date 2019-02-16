/*Напишите программу, которая многократно запрашивает у пользователя пару
чисел до тех пор, пока хотя бы одно из этой пары не будет равно 0. С 
каждой парой программа должна использовать функцию для вычисления среднего
гармонического этих чисел. Функция должна возвращать ответ main () для 
отображения результата. Среднее гармоническое чисел — это инверсия среднего
значения их инверсий; она вычисляется следующим образом:
среднее гармоническое = 2.0 х х к у / (х + у)*/
#include <iostream>

using namespace std;

struct couple {
	double first;
	double second;
};

double harmonic(double, double);

int main(){
	double a, b;

	cout << "Enter couple of numbers (0 to terminate): ";
	cin >> a >> b;

	while (a != 0 && b != 0) {
		cout << "Harmonic average = " << harmonic(a, b) << endl;
		cout << "Enter another couple of numbers (0 to terminate): ";
		cin >> a >> b;
	}

	return 0;
}

double harmonic(double x, double y) {
	return 2.0 * x * y / (x + y);
}