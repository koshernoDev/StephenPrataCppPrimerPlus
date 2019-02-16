/*Напишите программу, которая использует массив char и цикл для чтения но
одному слову за раз до тех пор, пока не будет введено слово done. Затем 
программа должна сообщить количество введенных слов (исключая done). Пример
запуска должен быть таким:
Вводите слова (для завершения введите слово done):
anteater birthday category dumpsteг
envy finagle geometry done for sure
Вы ввели 7 слов .
Вы должны включить заголовочный файл cstring и применять функцию
strcmp () для выполнения проверки.*/
#include <iostream>
#include <cstring>

using namespace std;

const int AM{100};

int main(){
	char target[5] = "done";
	char words[AM][20];
	cout << "Enter your words (for terminate enter word 'done')\n";
	int c{0};
	for (cin >> words[c]; strcmp(words[c], target); cin >> words[c]){
		++c;
	}
	cout << "You've entered " << c << " words" << endl;

	return 0;
}