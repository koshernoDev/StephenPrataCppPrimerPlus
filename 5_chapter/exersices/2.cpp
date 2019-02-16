//2 переписать код из листинга 5.4 с использованием объекта array 
//вместо встроенного массива и типа Long double вместо long long. 
//найдите значение 100!
#include <iostream>
#include <array>

using namespace std;

int main(){
	array<long double, 2001> factorials;
	factorials[1] = factorials[0] = 1;
	for(size_t c = 2; c < factorials.size(); ++c){
		factorials[c] = c * factorials[c-1];
	}
	for(size_t c = 0; c < factorials.size(); ++c){
		cout << c << "! = " << factorials[c] << endl;
	}
	return 0;
}