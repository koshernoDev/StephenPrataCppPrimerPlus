/*Вернитесь к программе из листинга 7.15, не использующей класс array. 
Напишите следующие две версии.
а. Используйте обычный массив из const char * для строковых представлений
времен года и обычный массив из double для расходов.
б. Используйте обычный массив из const char * для строковых 
представлений времен года и структуру, единственный член которой является обычным
массивом из double для расходов. (Это очень похоже на базовое проектное
решение для класса array.)*/
#include <iostream>

using namespace std;

const short SEASONS = 4;
const char* SNAMES[SEASONS] = {
	"Spring", "Summer", "Fall", "Winter"
};

struct expence {
	double value[SEASONS];
	double total;
};

void fIll_struct(expence*);
void show_struct(expence*);

int main() {
	expence expences;
	fIll_struct(&expences);
	show_struct(&expences);

	return 0;
}

void fIll_struct(expence* exp) {
	for (int ix = 0; ix < SEASONS; ++ix) {
		cout << "Enter " << SNAMES[ix] << " expences:";
		cin >> exp->value[ix];
	}
}

void show_struct(expence* exp) {
	for (int ix = 0; ix < SEASONS; ++ix) {
		cout << SNAMES[ix] << " expences = " << exp->value[ix] << endl;
		exp->total += exp->value[ix];
	}
	cout << "Total expences = " << exp->total << endl;
}