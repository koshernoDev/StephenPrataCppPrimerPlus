//Prata 2.6
#include <iostream>

float light_to_astronomical(float light);

int main()
{
	using namespace std;

	float light_years{};

	cout << "Enter the number of light years: ";
	cin >> light_years;
	cout << endl << light_years << " light years = " << light_to_astronomical(light_years) << " astronomical units\n";

	return 0;
}

float light_to_astronomical(float light)
{
	return light*63240;
}