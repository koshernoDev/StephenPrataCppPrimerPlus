#include "1.h"

namespace {
		const int SIZE = 3;
	}

int main() {
	using namespace golf;

	Golf ann, andy;

	set_Golf(ann, "Ann Birdfree", 24);
	set_Golf(andy);

	show_Golf(ann);
	show_Golf(andy);

	Golf players[SIZE];

	for (int ix = 0; ix < SIZE; ++ix) {
		set_Golf(players[ix]);
	}

	set_handicap(players[1], 43);

	for (int ix = 0; ix < SIZE; ++ix) {
		show_Golf(players[ix]);
	}

	return 0;
}