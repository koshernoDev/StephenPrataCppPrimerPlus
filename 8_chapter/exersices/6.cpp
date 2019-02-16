/*Напишите шаблонную функцию maxn (), которая принимает в качестве 
аргумента массив элементов типа т и целое число, представляющее количество 
элементов в массиве, а возвращает элемент с наибольшим значением. Протестируйте
ее работу в программе, которая использует этот шаблон с массивом из шести
значений int и массивом из четырех значений double. Программа также 
должна включать специализацию, которая использует массив указателей на char в 
качестве первого аргумента и количество указателей — в качестве второго, а затем
возвращает адрес самой длинной строки. Если имеется более одной строки 
наибольшей длины, функция должна вернуть адрес первой из них. Протестируйте
специализацию на массиве из пяти указателей на строки.*/
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T* maxn(T*, short);
template <> const char* maxn(const char*, short);

int main() {
	int array_int[6] = {4, 3, 4, 6, 34, 2};
	double array_double[4] = {3.4, 5.3, 5.1, 9.3};

	cout << *maxn(array_double, 4) << ' ' << *maxn(array_int, 6) << endl;

	const char* array_char[3] = {"Dimka", "Get out of here", "Fasdfhgfdelicia"};

	cout << maxn(*array_char, 3) << endl;

	return 0;
}

template <typename T>
T* maxn(T* a, short n) {
	T* max = &a[0];

	for (int ix = 1; ix < n; ++ix) {
		if (a[ix] > *max) {
			*max = a[ix];
		}
	}

	return max;
}

template <> const char* maxn(const char* a, short n) { 
	const char* max = a; // max указатель на массив типа const char* инициализирован адресом начала массива
	short length;	// длина текущей строковой константы

	for (int ix = 0; ix < n; ++ix, a += length) { // 
		length = strlen(a) + 1;
		if (strlen(max) < strlen(a + length)) {
			max = a + length;
		}
	}

	return max;
}