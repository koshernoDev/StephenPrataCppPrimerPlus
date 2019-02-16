/*Напишите шаблонную функцию max5 (), которая принимает в качестве 
аргумента массив из пяти элементов типа т и возвращает наибольший элемент в 
массиве. (Поскольку размер массива фиксирован, его можно жестко закодировать в
цикле, а не передавать в виде аргумента.) Протестируйте функцию в 
программе с использованием массива из пяти значений int и массива из пяти значений
double.*/
#include <iostream>

using namespace std;

template <typename T>
T max_5(T*);
	
const short SIZE = 5;

int main() {
	int array_int[SIZE] = {3, 4, 12, 45, 2};
	double array_double[SIZE] = {22.8, 3.3, 1.2, 3.5, 4.4};
	cout << max_5(array_int) << endl
			<< max_5(array_double) << endl;

	return 0;
}

template <typename T> 
T max_5(T* a) {
	T m = a[0];
	for (int ix = 1; ix < SIZE; ++ix) {
		if (a[ix] > m) {
			m = a[ix];
		}
	}
	return m;
}