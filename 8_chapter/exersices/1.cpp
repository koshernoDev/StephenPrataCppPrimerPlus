/*Напишите функцию, которая обычно принимает один аргумент — адрес строки
и выводит эту строку один раз. Однако если задан второй аргумент типа int, не
равный нулю, то эта функция выводит строку столько раз, сколько было 
осуществлено вызовов этой функции к моменту ее данного вызова. (Обратите внимание,
что количество выводимых строк не равно значению второго аргумента, оно
равно числу вызовов функции к моменту последнего вызова.) Действительно,
это не слишком полезная функция, но она заставит применить некоторые из
методов, рассмотренных в данной главе. Напишите простую программу для 
демонстрации этой функции.*/
#include <iostream>

void show_string(const char *, short n = 0);

int main() {
	const char* str = "Hello!";

	for (short ix = 0; ix < 5; ++ ix) {
		show_string(str);
	}

	show_string(str, 1);

	return 0;
}

void show_string(const char *p, short n) {
	using namespace std;
	static short Counter = 0;
	if (!n) {
		cout << p << endl;
		++Counter;
	}
	else {
		for (short ix = 0; ix < Counter; ++ix) {
				cout << p << endl;	
		}
	}
}