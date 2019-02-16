#include "2_CD.h"
#include <iostream>

void bravo(const CD &);

int main()
{
	CD c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		                   "Alfred Brendel", "Phillips", 2, 57.17);
	CD * pcd = &c1;

	std::cout << "Using object directly:\n";
	c1.report();
	c2.report();

	std::cout << "Using type cd * pointer to objects:\n";
	pcd->report();
	pcd = &c2;
	pcd->report();

	std::cout<<"Calling a function with a Cd reference argument:\n";
	bravo(c1);
	bravo(c2);

	std::cout << "Testing assignment:\n";
	Classic copy;
	copy = c2;
	copy.report();

	return 0;
}

void bravo(const CD & disk)
{
	disk.report();
}