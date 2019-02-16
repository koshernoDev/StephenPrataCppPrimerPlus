//4.9
#include <iostream>
#include <string>

using namespace std;

struct candyBar{
	string name;
	float mass;
	short calories;
};

int main(){
	const short Size{3};
	candyBar * arr = new candyBar[Size]{
		{"Snickers extra", 500, 2500},
		{"Bounty", 50.5, 200},
		{"Tempo", 35.5, 100}
	};

	for(short i = 0; i < Size; i++){
		cout << arr[i].name << " " << arr[i].mass << " " << arr[i].calories << endl;
	}

	delete [] arr;

	return 0;
}