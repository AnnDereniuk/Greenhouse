//робота Деренюк Анни
#include "f.h"
#include "copyright.h"
#include "create.h"
#include "greenhouse.h"
#include<iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "ukr");
	copyright();
	cout << "Програма моделює iнтерактивне керування теплицею.\n";
	Greenhouse* gr;
	try {
		gr = createGr();
		action(*gr);
		delete gr;
	}
	catch (const bad_alloc &ex) { cout << ex.what() << endl; }
	catch (out_of_range) { cout << "Error"; };

	system("pause");
	return 0;
}