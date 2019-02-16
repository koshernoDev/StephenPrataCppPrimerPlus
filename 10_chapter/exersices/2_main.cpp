#include "2_class_Person.h"

int main() 
{
	Person one;
	Person two("Keiran");
	Person three("Merigold", "Triss");
	one.showPerson();
	two.showPerson();
	three.formalShowPerson();
	three = Person("John", "Calveit");
	three.showPerson();

	return 0;
}