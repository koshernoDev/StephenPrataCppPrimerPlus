//4.20 использование указателей на строки
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char animal[20] = "bear";
	const char * bird = "wren";
	char * ps;
	cout << animal << " and ";
	cout << bird << endl;
	//cout << ps << endl; 	//может отобразить мусор, но может вызвать
							//и аварийноe завершение программы
	cout << "Enter a kind of animal: ";
	cin >> animal;
	// cin >> ps; // очень опсаная ошибка, чтобы пробовать
	// ps не указывает на выделенное пространство

	ps = animal;
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int *) animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "After using strcpy():\n";
	cout << animal << " at " << (int *) animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	delete [] ps;

	return 0;
}