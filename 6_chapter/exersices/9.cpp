/*Выполните упражнение 6, но измените его так, чтобы данные можно было 
получать из файла. Первым элементом файла должно быть количество меценатов,
а остальная часть состоять из пар строк, в которых первая строка содержит
имя, а вторая — сумму пожертвования. То есть файл должен выглядеть 
примерно так:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000*/
#include <fstream>
#include <string>
#include <cstdlib>
//#include <iostream>
#include <vector>

using namespace std;

struct patron {
	string name;
	int donation;	
};

const short LIMIT = 10000;

int main(){
	ifstream input_file;
	input_file.open("9_input.txt");

	if (!input_file.is_open()) {
		exit(EXIT_FAILURE);
	}

	short amount;
	(input_file >> amount).get();
	patron* patrons = new patron[amount];

	short ix = 0;

	vector<bool> is_more(amount, false);
	short is_more_count = 0;

	while (input_file.good()) {
		getline(input_file, patrons[ix].name);
		(input_file >> patrons[ix].donation).get();
		if (patrons[ix].donation > LIMIT) {
			is_more[ix] = true;
			++is_more_count;
		}
		++ix;
	}

	/*if (input_file.eof()) {
		cout << "EOF " << ix << endl;
	}
	else if (input_file.fail()) {
		cout << "FAIL " << ix << endl;
	} else {
		cout << "ANOTHER " << ix << endl;
	}*/

	input_file.close();

	ofstream output_file;
	output_file.open("9_output.txt");

	if (!output_file.is_open()) {
		exit(EXIT_FAILURE);
	}

	if (is_more_count > 0) {
	output_file << "Grand Patrons:\n";
		for (short ix = 0; ix < amount; ++ix) {
			if (is_more[ix]) {
				output_file << patrons[ix].name << " " << patrons[ix].donation << endl;
			}
		}
	}

	if (ix > 0) {
		output_file << "Patrons:\n";
		for (short ix = 0; ix < amount; ++ix) {
			if (!is_more[ix]) {
				output_file << patrons[ix].name << " " << patrons[ix].donation << endl;
			}
		}
	}

	output_file.close();

 	delete [] patrons;

	return 0;
}