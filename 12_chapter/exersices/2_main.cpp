#include <iostream>
#include "2_String.h"

int main()
{
  String s1(" and I am a C++ student");
  String s2 = "Please enter your name: ";
  String s3;

  std::cout << s2;
  std::cin >> s3;

  s2 = "My name is " + s3;
  std::cout << s2 << std::endl;

  s2 = s2 + s1;
  s2.stringUp();
  std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
            << " 'A' chracters in it.\n";

  s1 = "red";

  String rgb[3] = {String(s1), String("green"), String("blue")};

  std::cout << "Enter the name of a primary color for mixing light: ";
  String answer;
  bool succes = false;

  while (std::cin >> answer) {
  	answer.stringLow();

  	for (int i = 0; i < 3; ++i) {
  		if (answer == rgb[i]) {
  			std::cout << "That's right!\n";
  			succes = true;
  			break;
  		}
  	}

    if (succes) {
    	break;
    }
    else {
    	std::cout << "Try again!\n";
    }
  }

  std::cout << "Bye!\n";

	return 0;
}