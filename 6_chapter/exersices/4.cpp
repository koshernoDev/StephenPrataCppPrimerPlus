/*Когда вы вступите в Благотворительный Орден Программистов (БОП), к вам
могут обращаться на заседаниях БОП по вашему реальному имени, по 
должности либо секретному имени БОП. Напишите программу, которая может 
выводить списки членов по реальным именам, должностям, секретным именам либо
по предпочтению самого члена. В основу положите следующую структуру:
// Структура имен Благотворительного Ордена Программистов (БОП)
struct bop {
char fullname[strsize]; // реальное имя
char title[strsize]; // должность
char bopname[strsize]; // секретное имя БОП
int preference; // 0 = полное имя, 1 = титул, 2 = имя БОП
};
В этой программе создайте небольшой массив таких структур и 
инициализируйте его соответствующими значениями. Пусть программа запустит цикл, 
который даст возможность пользователю выбирать разные альтернативы:
a. display by name b. display by title
c. display by bopname d. display by preference
q. quit
Обратите внимание, что "display by preference" (отображать по предпочтениям)
не означает, что нужно отобразить член preference; это значит, что 
необходимо отобразить член структуры, который соответствует значению preference.
Например, если preference равно 1, то выбор d должен вызвать отображение
должности данного программиста. Пример запуска этой программы может 
выглядеть следующим образом:
Benevolent Order of Programmers Report
a. display by name b. display by title
c. display by bopname d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!*/
#include <iostream>
#include <string>

using namespace std;

struct bop {
	string fullname;
	string title;
	string bopname;
	short preference;
};

const short SIZE = 3;

int main() {
	bop members[SIZE] {
		{"Dimka", "Major", "Gwent", 0},
		{"Antosha", "Junior", "Helowold", 2},
		{"Abama", "Sanitar Padika", "Monkey", 1}
	};

	cout << "Benevolent Order of Programmers Report\n";
	cout << "a) display by name. b) display by title.\n"
				<< "c) display by bop name. d) display by preference.\n"
				<< "q) quit.\n";

	for (int ix = 0; ix < SIZE; ++ix) {		
		char choice;
		cin >> choice;
		switch (choice) {
			case 'a' : 	cout << members[ix].fullname << endl;
									if (ix < SIZE - 1) {
										cout << "Next choce: ";
									}	
									break;
			case 'b' :		cout << members[ix].title << endl;
									if (ix < SIZE - 1) {
										cout << "Next choce: ";
									}	
									break;
			case 'c' :	cout << members[ix].bopname << endl;
									if (ix < SIZE - 1) {
										cout << "Next choce: ";
									}	
									break;
			case 'd' :	if (members[ix].preference == 0) {
										cout << members[ix].fullname;
									}
									else if (members[ix].preference == 1) {
										cout << members[ix].title;
									}
									else {
										cout << members[ix].bopname;
									}
									cout << "\nNext choce: ";
									break;
			case 'q' :  ix = SIZE;
									cout << "Bye!\n";
									break;
			default :		--ix;
									break;
		}		
	}
	
	return 0;
}