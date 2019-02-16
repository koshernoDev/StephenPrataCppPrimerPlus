/*Постройте программу, которая отслеживает пожертвования в Общество
Защиты Влиятельных Лиц. Она должна запрашивать у пользователя 
количество меценатов, а затем приглашать вводить их имена и суммы пожертвований от
каждого. Информация должна сохраняться в динамически выделяемом массиве
структур. Каждая структура должна иметь два члена: символьный массив (или
объект string) для хранения имени и переменную-член типа double — для
хранения суммы пожертвования. После чтения всех данных программа должна
отображать имена и суммы пожертвований тех, кто не пожалел $10 000 и 
более. Этот список должен быть озаглавлен меткой "Grand Patrons". После этого
программа должна выдать список остальных жертвователей. Он должен быть
озаглавлен "Patrons". Если в одной из двух категорий не окажется никого, 
программа должна напечатать "попе". Помимо отображения двух категорий, 
никакой другой сортировки делать не нужно.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct members {
	string name;
	float donation;
};

const short TOP = 10000;

int main() {	
	cout << "Enter amount of patrons: ";
	short am;
	cin >> am;
	
	members* arr = new members[am];
	vector<bool> is_more(am, false);

	for (int ix = 0; ix < am; ++ix) {
		cin >> arr[ix].name >> arr[ix].donation;
		if (arr[ix].donation > TOP) {
			is_more[ix] = true;
		}
	}

	cout << "\nGrand Patrons:\n";
	for (int ix = 0; ix < am; ++ix) {
		if (is_more[ix]) {
			cout << arr[ix].name << " " << arr[ix].donation << endl;
		}
	}

	cout << "\nPatrons:\n";
	for (int ix = 0; ix < am; ++ix) {
		if (!is_more[ix]) {
			cout << arr[ix].name << " " << arr[ix].donation << endl;
		}
	}

	delete [] arr;

	return 0;
}