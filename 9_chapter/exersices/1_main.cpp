#include "1.h"

namespace {
		const int SIZE = 3;
		bool is_set[SIZE];
	}

int main() {
	using namespace golf;

	Golf ann, andy;

	set_Golf(ann, "Ann Birdfree", 25);
	bool is_andy = set_Golf(andy);

	show_Golf(ann);
	if (is_andy) {
		show_Golf(andy);
	}

	Golf players[SIZE];

	for (int ix = 0; ix < SIZE; ++ix) {
		is_set[ix] = set_Golf(players[ix]);
		if (!is_set[ix]) {
			break;
		}
	}

	set_handicap(players[1], 76);

	for (int ix = 0; ix < SIZE; ++ix) {
		if (is_set[ix]) {
			show_Golf(players[ix]);
		} else {
				break;
		}
	}

	return 0;
}