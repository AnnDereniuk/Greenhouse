//робота Деренюк Анни
#include "f.h"
#include "copyright.h"
#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	copyright();
	cout << "Програма моделює роботу теплицi без втручання власника.";
	procces();
	system("pause");
	return 0;
}