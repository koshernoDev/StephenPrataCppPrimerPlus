//Prata 2.5
#include <iostream>

float celsius_to_fahrenheits(float celsius);

int main()
{
	using namespace std;

	float celsius{};

	cout << "Please enter a Celsius value: ";
	cin >> celsius;
	cout << endl << celsius << " degrees Celsius is " << celsius_to_fahrenheits(celsius) << " degrees Fahrenheit\n";

	return 0;
}

float celsius_to_fahrenheits(float celsius)
{
	return celsius*1.8 + 32;
}