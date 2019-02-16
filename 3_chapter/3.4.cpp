//Prata 3.4
#include <iostream>

using namespace std;

int main(){
	const int seconds_in_day{86400};
	const int seconds_in_hour{3600};
	const int seconds_in_minute{60};
	
	long seconds{};

	cout << "Enter the number of seconds: ";
	cin >> seconds;

	int days = seconds/seconds_in_day;
	int hours = seconds % seconds_in_day/seconds_in_hour;
	int minutes = seconds % seconds_in_hour/seconds_in_minute;
	int seconds_in_user_seconds = seconds % seconds_in_minute;

	cout << endl << seconds << " seconds = " << days << " days, ";
	cout << hours << " hours " << minutes << " minutes " << seconds_in_user_seconds << " seconds\n";

	return 0;
}