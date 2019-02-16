/*Напишите программу, которая открывает текстовый файл, читает его символ
за символом до самого конца и сообщает количество символов в файле.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main(){
	ifstream file;
	char tmp;
	short count = 0;

	file.open("8_input.txt");

	if (!file.is_open()) {
		cout << "Program terminated.\n";
		exit(EXIT_FAILURE);
	}

	while (file >> tmp) {
		if (!isspace(tmp)) {
			++count;
		}
	}

	file.close();

	cout << count << endl;

	return 0;
}