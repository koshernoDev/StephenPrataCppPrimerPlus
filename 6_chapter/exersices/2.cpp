#include <iostream>
#include <array>

using namespace std;

const int SIZE = 5;

int main() {
	double donations[SIZE];
	double aver_donat = 0;
	short count = 0;


	for (double& ix : donations) {
		cin >> ix;
		if (!ix) {
			break;			
		}
		else {
			aver_donat += ix;
			++count;
		}
	}

	aver_donat /= count;
	cout << "Average donation = " << aver_donat << endl;
	count = 0;

	for (double ix : donations) {
		if (ix > aver_donat) {
			++count;
		}
	}
	
	if (count == 1) {
		cout << "There is only one donation more than average.\n";
	}
	else if (count > 1) {
		cout << "There are " << count << " donations more than average.\n";
	}
	else {
		cout << "There are no donations more than average.\n";
	}

	return 0;
}