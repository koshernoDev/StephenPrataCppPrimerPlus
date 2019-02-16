/*Многие лотереи в США организованы подобно той, что была смоделирована
в листинге 7.4. Во всех их вариациях вы должны выбрать несколько чисел из
одного набора, называемого полем номеров. (Например, вы можете выбрать 5
чисел из поля 1-47.) Вы также указываете один номер (называемый меганоме-
ром) из второго диапазона, такого как 1-27. Чтобы выиграть главный приз, вы
должны правильно угадать все номера. Шанс выиграть вычисляется как 
вероятность угадывания всех номеров в поле, умноженная на вероятность 
угадывания меганомера. Например, вероятность выигрыша в описанном здесь 
примере вычисляется как вероятность угадывания 5 номеров из 47, умноженная на
вероятность угадывания одного номера из 27. Модифицируйте листинг 7.4 для
вычисления вероятности выигрыша в такой лотерее.*/
#include <iostream>

using namespace std;

long double probability(short, short);

int main() {
	short total, choices,
			mega_total, mega_choices;
	cout << "Enter the total number of choices\n"
			<< "and the number of picks allowed,\n";
	cout << "enter total meganumber and megapicks next:\n";
	while ((cin >> total >> choices >> mega_total >> mega_choices) && (choices < total) && (mega_choices < mega_total)) {
		cout << "You have one chance in "
				<< probability(total, choices) * probability(mega_total, mega_choices)
				<< " of winning\n"
				<< "Next four numbers (any character to quit)\n";
	}

	return 0;
}

long double probability(short numbers, short picks) {
	long double result = 1.0;
	while (picks) {
		result *= numbers / picks;
		--numbers;
		--picks;
	}
	return result;
}