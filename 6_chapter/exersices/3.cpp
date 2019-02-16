/*Напишите предшественник программы, управляемой меню. Она должна
отображать меню из четырех пунктов, каждый из них помечен буквой. Если
пользователь вводит букву, отличающуюся от четырех допустимых, программа
должна повторно приглашать его ввести правильное значение до тех пор, пока
он этого не сделает. Затем она должна выполнить некоторое простое действие
на основе пользовательского выбора. Работа программы должна выглядеть 
примерно так:
Please enter one of the following choices:
c) carnivore p) pianist
t) tree g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.*/
#include <iostream>

using namespace std;

int main(){
	char choise;
	cout << "Please enter one of the following choises: " << endl;
	cout << "c) carnivore p) pianist" << endl
			<< "t) tree g) game" << endl;
			
	do {	
		cin >> choise;
		switch (choise){
			case 'c' :
				cout << "carnivore" << endl;
				break;
			case 'p' :
				cout << "pianist" << endl;
				break;		
			case 't' :
				cout << "A maple is a tree" << endl;
				break;		
			case 'g' :
				cout << "game" << endl;
				break;		
			default :
				cout << "Please enter a c, p, t, or g: ";	
		}
	} while ((choise != 'c' && choise != 'p' && choise != 't' && choise != 'g'));

	return 0;
}