/*Напишите программу, соответствующую описанию программы из упражнения 8,
но с использованием объекта string вместо символьного массива. Включите
заголовочный файл string и применяйте операции отношений для 
выполнения проверки.*/
#include <iostream>
#include <string>

using namespace std;

int main(){
	string target = "done";
	string words[100];
	cout << "Enter your words (for terminate enter word 'done')\n";
	int c{0};
	for (cin >> words[c]; words[c] != target; cin >> words[c]){
		++c;
	}
	cout << "You've entered " << c << " words" << endl;
	//cout << sizeof words << endl;

	return 0;
}