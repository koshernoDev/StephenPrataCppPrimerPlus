/*Вернитесь к программе из листинга 7.7 и замените три функции обработки 
массивов версиями, которые работают с диапазонами значений, заданными парой
указателей. Функция f ill_array () вместо возврата действительного 
количества прочитанных значений должна возвращать указатель на место, следующее за
последним введенным элементом; прочие функции должны использовать его в
качестве второго аргумента для идентификации конца диапазона данных.*/
#include <iostream>

using namespace std;

const short SIZE = 5;

double * fill_array(double*, double*);
void show_array(double*, double*);
void revalue_array(double, double*, double*);

int main() {
	double array[SIZE];

	double* p_real_end = fill_array(array, array + SIZE);
	show_array(array, p_real_end);

	double revalue = 2.28;
	cout << "Enter the revalue: ";
	cin >> revalue;

	revalue_array(revalue, array, p_real_end);
	show_array(array, p_real_end);

	return 0;
}

double * fill_array(double* begin, double* end) {
	cout << "Enter " << SIZE << " elements in the array:\n";
	double* pt;
	for (pt = begin; pt != end; ++pt) {
		if (!(cin >> *pt)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Input process terminated.\n";
			break;
		}
	}
	return pt;
}

void show_array(double* begin, double* end) {
	for (double* pt = begin; pt != end; ++pt) {
		cout << *pt << " ";
	}
	cout << endl;
}

void revalue_array(double revalue, double* begin, double* end) {
	for (double* pt = begin; pt != end; ++pt) {
		*pt = revalue;
	}
}