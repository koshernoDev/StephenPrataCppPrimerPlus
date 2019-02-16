#include <iostream>
#include <cstring>
#include "1.h"

namespace golf {
	void set_Golf(Golf& g, const char* name, int hc) {
		strcpy(g.fullname, name);
		g.handicap = hc;
	}

	int set_Golf(Golf& g) {
		std::cout << "Enter name: ";
		char next;
		std::cin.get(g.fullname, LEN);
		if (!std::cin) {
			return 0;
		} else {
			while (cin) {
				std::cin.get(next);
				while (next != '\n') {
					std::cin.get(next);
				}
			}
		}
		std::cout << "Enter handicap: ";
		(std::cin >> g.handicap).get();
		return 1;
	}

	void set_handicap(Golf& g, int hc) {
		g.handicap = hc;
	}

	void show_Golf(const Golf& g) {
		std::cout << "Name: " << g.fullname << std::endl
							<< "Handicap: " << g.handicap << std::endl;
	}
}