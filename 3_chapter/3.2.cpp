//Prata 3.2
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int feets_in_inches{12};
	const float inches_to_meters{0.0254};
	const float pounds_to_kilograms{2.2};

	int growth_in_feets{},
		growth_in_inches{},
		mass_in_pounds;

	cout << "Enter your growth in feets and inches and your mass in pounds: _ __ __\b\b\b\b\b\b\b";
	cin >> growth_in_feets >> growth_in_inches >> mass_in_pounds;

	float body_mass_index{(mass_in_pounds/pounds_to_kilograms)/pow(((growth_in_inches + growth_in_feets*feets_in_inches)*inches_to_meters), 2)};

	cout << endl << "Your BMI is " << body_mass_index << endl;

	return 0;
}