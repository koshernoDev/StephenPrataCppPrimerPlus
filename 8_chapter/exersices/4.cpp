/*Ниже представлена общая структура программы:
#include <iostream>
using namespace std;
#include <cstring> // для strlen(), strcpyO
struct stringy {
char * str; // указывает на строку
(int ct; // длина строки (не считая символа '\0')
};
// Здесь размещаются прототипы функций set() и show()
int main ()
{
stringy beany;
char testing [] = "Reality isn't what it used to be.";
set(beany, testing); // первым аргументом является ссылка,
// Выделяет пространство для хранения копии testing,
// использует элемент типа str структуры beany как указатель
// на новый блок, копирует testing в новый блок и
// создает элемент ct структуры beany
show(beany); // выводит строковый член структуры один раз
show (beany, 2); // выводит строковый член структуры два раза
testing[0] = 'D';
testing[1] = ' u';
show(testing); // выводит сроку testing один раз
show(testing, 3); // выводит строку testing три раза
show("Done!");
return 0;
}
Завершите программу, создав соответствующие функции и прототипы. Обратите
внимание, что в программе должны быть две функции show (), и каждая из
них использует аргументы по умолчанию. Где необходимо, используйте const.
Функция set () должна использовать операцию new для выделения 
достаточного пространства памяти под хранение заданной строки. Используемые здесь
методы аналогичны методам, применяемым при проектировании и реализации
классов. (В зависимости от используемого компилятора, может понадобиться 
изменить имена заголовочных файлов и удалить директиву using.)*/
#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char* str;
	int ct;
};

char* set(stringy&, const char*);
void show(const stringy&, short n = 1);
void show(const char*, short n = 1);

int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	char* n = set(beany, testing);
	show(beany);
	delete n;
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show("Done!", 3);

	return 0;
}

char* set(stringy& sy, const char* str) {
	sy.ct = strlen(str);

	char* ptr = new char[sy.ct];
	sy.str = ptr;

	strcpy(sy.str, str);

	return ptr;
}

void show(const stringy& sy, short n) {
	for (int ix = 0; ix < n; ++ix) {
		cout << sy.str << "\nhas " << sy.ct << " characters.\n";
	}
}

void show(const char* s, short n) {
	for (int ix = 0; ix < n; ++ix) {
		cout << s << endl;
	}
}