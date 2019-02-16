/*Напишите программу, которая читает клавиатурный ввод до символа @ и 
повторяет его, за исключением десятичных цифр, преобразуя каждую букву верхнего
регистра в букву нижнего регистра и наоборот. (Не забудьте о семействе 
функций cctype.)*/
#include <iostream>
#include <cctype>

using namespace std;

int main(){
	char symb;
	do {
		cin >> symb;
		if (!isdigit(symb)) {
			if (isupper(symb)) {
				cout << (char)tolower(symb);
			}	else if (islower(symb)) {
					cout << (char)toupper(symb);
				}
		}		
	}	while (symb != '@');
	cout << endl;

	return 0;
}