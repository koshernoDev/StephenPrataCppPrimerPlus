/*Напишите программу, которая приглашает пользователя вводить числа. После
каждого введенного значения программа должна выдавать накопленную сумму
введенных значений. Программа должна завершаться при вводе 0.*/
#include <iostream>

using namespace std;

int main(){
	int users_numer{};
	int sum{};
	for(cin >> users_numer; users_numer; cin >> users_numer){
		sum += users_numer;
		cout << sum << endl;
	}

	return 0;
}