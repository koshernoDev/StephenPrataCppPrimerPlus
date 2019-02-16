/*Напишите программу, которая читает слова по одному за раз, пока не будет 
введена отдельная буква q. После этого программа должна сообщить количество
слов, начинающихся с гласных, количество слов, начинающихся с согласных,
а также количество слов, не попадающих ни в одну из этих категорий. Одним
из возможных подходов может быть применение isalpha () для различения
слов, начинающихся с букв, и остальных, с последующим применением if или
switch для идентификации тех слов, прошедших проверку isalpha (), 
которые начинаются с гласных. Пример запуска может выглядеть так:
Enter words (q to quit) :
the 12 awesome oxen ambled
quietly across 15 meters of lawn, q
5 words beginning with vowels
4 words beginning with consonants
2 others*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
	string hello;
	string tmp;

	for (cin >> tmp; tmp != "q"; cin >> tmp) {
		hello += tmp + " ";
	}

	short others = 0;
	short vowels = 0;
	short consonants = 0;

	for (size_t ix = 0; ix < hello.size(); ++ix) {
		if (isalpha(hello[ix])) {
			switch (hello[ix]) {
				case 'a' : ++vowels;
					break;
				case 'e' : ++vowels;
					break;
				case 'i' : ++vowels;
					break;
				case 'j' : ++vowels;
					break;
				case 'o' : ++vowels;
					break;
				case 'u' : ++vowels;
					break;
				case 'y' : ++vowels;
					break;
				case 'b' : ++consonants;
					break;
				case 'c' : ++consonants;
					break;
				case 'd' : ++consonants;
					break;
				case 'f' : ++consonants;
					break;
				case 'g' : ++consonants;
					break;
				case 'h' : ++consonants;
					break;
				case 'k' : ++consonants;
					break;
				case 'l' : ++consonants;
					break;
				case 'm' : ++consonants;
					break;
				case 'n' : ++consonants;
					break;
				case 'p' : ++consonants;
					break;
				case 'q' : ++consonants;
					break;
				case 'r' : ++consonants;
					break;
				case 's' : ++consonants;
					break;
				case 't' : ++consonants;
					break;
				case 'v' : ++consonants;
					break;
				case 'w' : ++consonants;
					break;
				case 'x' : ++consonants;
					break;	
				case 'z' : ++consonants;
					break;																		
			}
			while (!isspace(hello[ix])) {
				++ix;
			}
		}
		else if (!isalpha(hello[ix]) && !isspace(hello[ix])) {
			++others;
			while (!isspace(hello[ix])) {
				++ix;
			}
		}
	}

	cout << endl << vowels << " words begins with vowel\n"
			<< consonants << " words begins with consonant\n"
			<< others << " other\n";

	return 0;
}