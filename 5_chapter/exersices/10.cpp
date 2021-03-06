/*Напишите программу, использующую вложенные циклы, которая запрашивает
у пользователя значение количества строк для отображения. Затем она должна
отобразить указанное число строк со звездочками, с одной звездочкой в первой
строке, двумя — во второй и т.д: В каждой строке звездочкам должны 
предшествовать точки — в таком количестве, чтобы общее число символов в каждой
строке было равно количеству строк. Пример запуска программы должен 
выглядеть следующим образом:
Введите количество строк: 5*/
#include <iostream>

using namespace std;

int main(){
	int strings{0};
	cin >> strings;
	string chars[strings][strings];
	for (int s = 0; s < strings; ++s){
		for (int c = 0; c < strings - s; ++c){
			chars[s][c] = '.';
		}
		for (int c = strings; c > strings - s - 2; --c){
			chars[s][c] = '*';
		}
		for (int c = 0; c < strings; ++c){
			cout << chars[s][c];
		}
		cout << endl;
	}

	return 0;
}