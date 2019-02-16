/*Следующее упражнение позволит попрактиковаться в написании функций, 
работающих с массивами и структурами. Ниже представлен каркас программы.
Дополните его функциями, описанными в комментариях.
#include <iostream>
using namespace std;
const int SLEN = 30;
struct student {
char fullname[SLEN];
char hobby[SLEN];
int ooplevel;
};
// getinfo() принимает два аргумента: указатель на первый элемент
// массива структур student и значение int, представляющее
// количество элементов в массиве. Функция запрашивает и
// сохраняет данные о студентах. Ввод прекращается либо после
// наполнения массива, либо при вводе пустой строки в качестве
// имени студента. Функция возвращает действительное количество
//введенных элементов.
int getinfо(student pa[], int n) ;
// display]. () принимает в качестве аргумента структуру student
// и отображает ее содержимое.
void displayl(student st);
// display2() принимает адрес структуры student в качестве аргумента
// и отображает ее содержимое,
void display2(const student * ps) ;
// display3() принимает указатель на первый элемента массива
// структур student и количество элементов в этом массиве и
// отображает содержимое всех структур в массиве,
void display3(const student pa[], int n) ;
int main ()
{
cout « "Enter class size: ";
int class_size;
cin >> class_size;
while (cin.getO != '\n')
continue;
student * ptr_stu = new student[class_size];
int entered = getinfо (ptr_stu, class_size);
for (int i = 0; i < entered; i + + )
{
displayl (ptr_stu [i] ) ;
display2(&ptr_stu[i]);
}
display3(ptr_stu, entered);
delete [] ptr_stu;
cout << "Done\n";
return 0;
}*/
#include <iostream>

using namespace std;

const short SLEN = 30;

struct student {
	char full_name[SLEN];
	char hobby[SLEN];
	short oop_level;
};

short get_info(student*, short n);
void display_1(student);
void display_2(const student*);
void display_3(const student*, short);
void clear_input();

int main() {
	cout << "Enter class size: ";
	short class_size;
	cin >> class_size;
	while(cin.get() != '\n') {
		continue;
	}

	student* ptr_stu = new student[class_size];
	short entered = get_info(ptr_stu, class_size);

	for (short ix = 0; ix < entered; ++ix) {
		cout << ix + 1 << " student:\n";
		display_1(ptr_stu[ix]);
		display_2(&ptr_stu[ix]);
	}
	cout << "\n3 display:\n";
	display_3(ptr_stu, entered);

	delete [] ptr_stu;

	cout << "Done\n";

	return 0;
}

void clear_input() {
	cout << "Wrong input\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}

short get_info(student* s, short n) {
	short ix = 0;
	for (student* ps = s; ix < n; ++ps, ++ix) {
		cout << "Enter some information about " << ix + 1 << " student:\n";
		cout << "Full name: ";
		cin.getline(ps->full_name, SLEN);
		if (!cin) {
			clear_input();
		}
		cout << "Hobby: ";
		cin.getline(ps->hobby, SLEN);
		if (!cin) {
			clear_input();
		}
		cout << "OOP level: ";
		(cin >> ps->oop_level).get();
		if (!cin) {
			clear_input();
			ps->oop_level = false;
		}
	}
	return ix;
}

void display_1(student s) {
	cout << "Name: " << s.full_name << endl
			<< "Hobby: " << s.hobby << endl
			<< "OOP level: " << s.oop_level << endl;
}

void display_2(const student* s) {
	cout << "Name: " << s->full_name << endl
			<< "Hobby: " << s->hobby << endl
			<< "OOP level: " << s->oop_level << endl;
}

void display_3(const student* s, short n) {
	short ix = 0;
	for (const student* ps = s; ix < n; ++ps, ++ix) {
		cout << ix + 1 << " student:\n";
		cout << "Name: " << ps->full_name << endl
				<< "Hobby: " << ps->hobby << endl
				<< "OOP level: " << ps->oop_level << endl;
	}
}