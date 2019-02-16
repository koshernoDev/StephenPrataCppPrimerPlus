#include <iostream>
#include <cstring>
		
struct chaff {
char dross [20];
int slag;
};

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	chaff* buffer = new chaff[2];
	chaff* arr = new(buffer) chaff[2];

	cin >> arr->dross >> arr->slag;
	cin >> (arr + 1)->dross >> (arr + 1)->slag;

	for (int ix = 0; ix < 2; ++ix) {
		cout << (arr + ix)->dross << " " << (arr + ix)->slag << endl;
	}

	delete [] buffer;
	delete [] arr;

	return 0;
}