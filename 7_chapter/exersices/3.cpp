/*Пусть имеется следующее объявление структуры:
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
а. Напишите функцию, принимающую структуру box по значению и 
отображающую все ее члены.
б. Напишите функцию, принимающую адрес структуры box и устанавливающую
значение члена volume равным произведению остальных трех членов.
в. Напишите простую программу, которая использует эти две функции.*/
#include <iostream>

using namespace std;

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(box);
void set_volume(box*);

int main() {
	box simple {
		"Red", 24, 4, 30
	};

	set_volume(&simple);
	show_box(simple);

	return 0;
}

void set_volume(box* s) {
	s->volume = s->height * s->width * s->length;
}

void show_box(box s) {
	cout << "Name: " << s.maker << endl
			<< "Height = " << s.height << endl
			<< "Width = " << s.width << endl
			<< "Length = " << s.length << endl
			<< "Volume = " << s.volume << endl;
}