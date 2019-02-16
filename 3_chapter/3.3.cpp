//Prata 3.3
#include <iostream>

using namespace std;

int main(){
	const float minutes_in_arc{60};
	const float seconds_in_arc{3600};

	int degrees{},
		minutes{},
		seconds{};

	cout << "Enter a latitude in degrees, minutes, and seconds: ";
	cout << endl << "First, enter the degrees: ";
	cin >> degrees;
	cout << endl << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << endl << "Finally, enter the seconds of arc: ";
	cin >> seconds;

	float decimal_latitude = degrees + (minutes/minutes_in_arc) + (seconds/seconds_in_arc);

	cout << endl << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << decimal_latitude << " degrees\n";

	return 0;
}