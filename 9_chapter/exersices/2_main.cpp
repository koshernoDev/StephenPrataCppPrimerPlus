#include <iostream>
#include <string>

void str_count(const std::string& str);

int main() {
	std::string input;
	std::cout << "Enter a line: ";
	for (getline(std::cin, input); input != "" && input != " "; getline(std::cin, input))	{
		str_count(input);
		std::cout << "Enter other line: (empty to quit)";
	}

	return 0;
}

void str_count(const std::string& str) {
	static int total = 0;
	
	total += str.size();
	std::cout << "\"" << str << "\"" << " contains " << str.size()
						<< " characters." << std::endl << total 
						<< " characters total.\n";
}