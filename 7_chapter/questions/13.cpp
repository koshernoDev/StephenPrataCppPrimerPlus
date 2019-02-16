/*Предположим, что функции fl () и f2 () имеют следующие прототипы:
void f1(applicant * а) ;
const char * f2(const applicant * al, const applicant * a2);
Объявите pi как указатель на функцию f 1, а р2 — как указатель на f 2. Объявите
ар как массив из пяти указателей того же типа, что и рі, и объявите ра как 
указатель на массив из десяти указателей того же типа, что и р2. Воспользуйтесь
typedef.*/
#include <iostream>

using std::cout;
using std::endl;

struct applicant {
	char name[30];
};

typedef const char *(*t_f2)(const applicant*, const applicant*); // t_f2 имя типя указателя на f2

void f1(applicant * a);
const char * f2(const applicant * a1, const applicant * a2);

int main(){
	applicant member1 {
		"Dima"
	};
	applicant member2 {
		"Abama"
	};

	/*void (*pf1)(applicant *) = f1; // указатель на функцию f1
	const char *(*pf2) (const applicant*, const applicant*) = f2; // указатель на функцию f2
	void (*apf1[5]) (applicant *) = {f1, f1, f1, f1, f1}; // массив из 5 указателей типа p1
	const char *(*apf2[5]) (const applicant*, const applicant*) = {f2, f2, f2, f2, f2}; // массив из 5 указателей типа p2
	const char *(*(*papf2)[5]) (const applicant*, const applicant*) = &apf2; // указатель на массив из 5 указателей типа p2*/

	// через typedef удобнее:
	t_f2 ptr_f2 = f2; // указатель на f2
	t_f2 apf2[5] = {f2, f2, f2, f2, f2}; // массив 5 указателей на f2
	t_f2 (*pa2)[5] = &apf2; // указатель на массив из 5 указателей f2

	(*ptr_f2)(&member1, &member2);
	apf2[1](&member2, &member1);
	(*pa2)[2](&member1, &member2);

	return 0;
}

void f1(applicant * a) {
	cout << a->name << endl;
}

const char * f2(const applicant * a1, const applicant * a2) {
	cout << a1->name << " " << a2->name << endl;
	return a2->name;
}