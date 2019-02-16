//5.14 использование clock() в цикле временной задержки
#include <iostream>
#include <ctime>

using namespace std;

int main(){
	cout << "Enter the delay time, in seconds: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << "starting\n";
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "done" << endl;
	return 0;
}