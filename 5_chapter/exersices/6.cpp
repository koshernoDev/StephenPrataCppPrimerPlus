/*Выполните упражнение 5, но используя двумерный массив для сохранения 
данных о месячных продажах за 3 года. Выдайте общую сумму продаж за каждый
год и за все годы вместе.*/
#include <iostream>

using namespace std;

int YEARS{3};
int MONTHS{12};

int main(){
	int sales[YEARS][MONTHS];
	int amount[YEARS];
	int sum{0};
	for (int y = 0; y < YEARS; ++y){
		for (int m = 0; m < MONTHS; ++m){
			cout << "Enter amount of books saled in " << y + 1 
					<< " year and " << m + 1 << " month\n";
			cin >> sales[y][m];
			sum += sales[y][m];
		}
		amount[y] = sum;
		sum = 0;
	}
	for (int c = 0; c < YEARS; ++c){
		cout << "Amount of books saled in " << c + 1
				<< " year = " << amount[c] << endl;
		sum += amount[c];
	}
	cout << "Amount of books saled in 3 years = " << sum << endl;

	return 0;
}
/*2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 */