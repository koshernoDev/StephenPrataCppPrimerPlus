//4.5
#include <iostream>
#include <string>

using namespace std;

struct candyBar{
	string name;
	float mass;
	short calories;	
};

int main(){
	candyBar snack {"Mocha Munch", 2.3, 350};

	cout << snack.name << " " << snack.mass << " " << snack.calories << endl;

	return 0;
}