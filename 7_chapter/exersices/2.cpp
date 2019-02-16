/*Напишите программу, которая запрашивает у пользователя 10 результатов игры
в гольф, сохраняя их в массиве. При этом необходимо обеспечить возможность
прекращения ввода до ввода всех 10 результатов. Программа должна отобразить
все результаты в одной строке и сообщить их среднее значение. Реализуйте
ввод, отображение и вычисление среднего в трех отдельных функциях, 
работающих с массивами.*/
#include <iostream>

using namespace std;

void show_all_results(const int*, short);
short enter_results(int*, short);
void show_average_result(const int*, short);

const short SIZE = 5;

int main(){
	int results[SIZE];
	short real_size =	enter_results(results, SIZE);
	show_all_results(results, real_size);
	show_average_result(results, real_size);

	return 0;
}

void show_all_results(const int* arr, short n){
	for (short ix = 0; ix < n; ++ix) {
		cout << arr[ix] << " ";
	}
	cout << endl;
}

short enter_results(int * arr, short n) {
	cout << "Enter 10 results of the game (any character to stop)\n";
	short ix;
	for (ix = 0; ix < n; ++ix) {
		cout << ix + 1 << ": ";
		cin >> arr[ix];
	}
	return ix;
}

void show_average_result (const int * arr, short n) {
	double sum = 0;
	for (int ix = 0; ix < n; ++ix) {
		sum += arr[ix];
		if (ix + 1 == n) {
			sum /= ++ix;
		}
	}
	cout << "Average result = " << sum << endl;
}