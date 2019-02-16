#include "3_class_Golf.h"

namespace
{
	const int SIZE = 3;
}

int main()
{
	Golf user;
	Golf dandelion("Dandelion", 31);

	dandelion.show();
	user.show();

	Golf players[SIZE];

	players[1] = Golf("Priscilla", 33);

	for (int i = 0; i < SIZE; ++i)
	{
		players[i].show();
	}

	return 0;
}