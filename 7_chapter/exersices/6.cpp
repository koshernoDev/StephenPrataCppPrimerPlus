/*Напишите программу, использующую описанные ниже функции.
Fill_array () принимает в качестве аргумента имя массива элементов типа
double и размер этого массива. Она приглашает 
пользователя ввести значения double для помещения их в массив. Ввод
прекращается при наполнении массива либо когда 
пользователь вводит нечисловое значение и возвращает 
действительное количество элементов.
Show_array () принимает в качестве аргументов имя массива значений double,
а также его размер, и отображает содержимое массива.
Reverse_array () принимает в качестве аргумента имя массива значений
double, а также его размер, и изменяет порядок его 
элементов на противоположный.
Программа должна использовать эти функции для наполнения массива, 
обращения порядка его элементов, кроме первого и последнего, с последующим
отображением.*/
#include <iostream>

using namespace std;

short fill_array(double *, short);
void show_array(const double *, short);
void reverse_array(double *, short);

int main() {
	const short Size = 10;
	double array[Size];
	short real_size =	fill_array(array, Size);
	show_array(array, real_size);
	reverse_array(array, real_size);
	show_array(array, real_size);

	return 0;
}

short fill_array(double *arr, short n) {
	short ix = 1;
	cout << "Enter " << n << " elements in the array:\n"
			<< ix << ": ";
	for (ix = 0; ix < n; ++ix) {
		cin >> arr[ix];
		if (!cin) {
			cin.clear();
			break;
		}
		if (ix < n) {
			cout << ix + 2 << ": ";
		}
	}
	return ix;
}

void show_array(const double *arr, short n) {
	short i = 0;
	while (i < n) {
		cout << arr[i] << " ";
		++i;
	}
	cout << endl;
}

void reverse_array(double *arr, short n) {
	double tmp;
	short i = 1;
	while (i < n / 2) {
		tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
		++i;
	}
}