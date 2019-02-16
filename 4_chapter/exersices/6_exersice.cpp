//4.6
#include <iostream>
#include <string>

using namespace std;

struct candyBar{
	string name;
	float mass;
	short calories;	
};

int main(){
	candyBar arr[3]{
		{"Snickers", 100, 500},
		{"Bounty", 50.5, 200},
		{"Tempo", 35.5, 100}
	};

	for(short i = 0; i < 3; i++){
		cout << arr[i].name << " " << arr[i].mass << " " << arr[i].calories << endl;
	}

	return 0;
}