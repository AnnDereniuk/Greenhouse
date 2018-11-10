//робота Деренюк Анни
#include<iostream>
#include "greenhouse.h"
#include "create.h"
using namespace std;
int selectModel() {
	int c = 0;
	cout << "Є три моделі теплиць: стандартна (межі температури: 10-30 градусів за Цельсієм, вологості 40-90%);\n";
	cout << "друга - теплиця для теплолюбних рослин (25-38 градусів за Цельсієм, 30-60%); третя - теплиця для невибагливих\n";
	cout << "до тепла рослин (0-15 градусів за Цельсієм, 55-87%). Для подальшої роботи оберіть модель теплиці: \n";
	cout << "Натисніть 1, щоб обрати першу модель.\n";
	cout << "Натисніть 2, щоб обрати другу модель.\n";
	cout << "Натисніть 3, щоб обрати третю модель.\n";
	cin >> c;
	if (cin.fail()) {
		cin.clear(); cin.sync(); cin.ignore(1, '\n');
		return -1;
	}
	return c;
}

Greenhouse *createGr() {

	switch (selectModel()) {
	case 1:  return new FirstGreenhouse;
		break;
	case 2:  return new SecondGreenhouse;
		break;
	case 3: return new ThirdGreenhouse;
		break;
	default: cout << "Ви обрали цифру не з переліку.\n "; throw out_of_range("Помилка.\n");
		break;
	}
}
