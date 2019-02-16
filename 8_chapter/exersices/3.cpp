/*Напишите функцию, которая принимает ссылку на объект string в качестве
параметра и преобразует содержимое string в символы верхнего регистра.
Используйте функцию toupper (), описанную в табл. 6.4 (см. главу 6). Напишите
программу, использующую цикл, которая позволяет проверить работу функции
для разного ввода. Пример вывода может выглядеть следующим образом:
Enter a string (q to quit) : go away
GO AWAY
Next string (q to quit) : good grief!
GOOD GRIEF!
Next string (q to quit) : q
Bye.*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void to_upper(string&);

int main() {
	string str;
	cout << "Enter a string (q to quit): ";
	for (getline(cin, str); str != "q"; getline(cin, str)) {
		to_upper(str);
		cout << str << endl	<< "Next string (q to quit): ";
	}

	return 0;
}

void to_upper(string& s) {
	for (size_t ix = 0; ix < s.size(); ++ix) {
			s[ix] = toupper(s[ix]);
	}
}