/*Структура CandyBar содержит три члена. Первый член хранит название коробки
конфет. Второй — ее вес (который может иметь дробную часть), а третий — 
количество калорий (целое значение). Напишите программу, использующую 
функцию, которая принимает в качестве аргументов ссылку на CandyBar, указатель
на char, значение double и значение int. Функция использует три последних
значения для установки соответствующих членов структуры. Три последних 
аргумента должны иметь значения по умолчанию: "Millennium Munch", 2 . 85 и 350.
Кроме того, программа должна использовать функцию, которая принимает в 
качестве аргумента ссылку на CandyBar и отображает содержимое этой структуры.
Где необходимо, используйте const.*/
#include <iostream>

struct candy_bar {
	char name[30];
	float mass;
	short ccal;
};

void fill_bar(candy_bar&, const char* n = "Millennium Munch", float m = 2.85, short c = 350);
void show_bar(const candy_bar&);

int main() {
	candy_bar mouse, def;
	fill_bar(mouse, "Mouse", 30.5, 200);
	fill_bar(def);
	show_bar(mouse);
	show_bar(def);

	return 0;
}

void fill_bar(candy_bar& b, const char* n, float m, short c) {
	short ix;
	for (ix = 0; ix < 30 && n[ix] != '\0'; ++ix) {
		b.name[ix] = n[ix];
	}
	b.name[ix] = '\0';
	b.mass = m;
	b.ccal = c;
}

void show_bar(const candy_bar& b) {
	using std::cout;
	using std::endl;
	cout 	<< "\nName is " << b.name << endl
				<< "Mass = " << b.mass << endl
				<< "Calories = " << b.ccal << endl;
}