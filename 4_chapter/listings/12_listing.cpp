//4.12 присваивание структур
#include <iostream>

using namespace std;

struct inflatable{
	char name[20];
	float volume;
	double price;
};

int main(){
	inflatable bouqet = {
		"sunglowers",
		0.20,
		12.49
	};
	inflatable choise;
	cout << "bouqet: " << bouqet.name << " for $ ";
	cout << bouqet.price << endl;
	choise = bouqet;
	cout << "choise: " <<choise.name << " for $ ";
	cout << choise.price << endl;

	return 0;
}