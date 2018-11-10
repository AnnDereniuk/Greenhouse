//робота Деренюк Анни
#include "greenhouse.h"
#include <iostream>

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

Greenhouse  *createGr(Greenhouse *gr) {

	switch (selectModel()) {
	case 1:  return gr = new FirstGreenhouse;
		break;
	case 2:  return gr = new SecondGreenhouse;
		break;
	case 3: return gr = new ThirdGreenhouse;
		break;
	default: cout << "Ви обрали цифру не з переліку. "; throw out_of_range("Помилка.\n");
		break;
	}
}


int procces() {
	int h = 0;
	Greenhouse* gr;

	try {
		gr = createGr(gr);
		cout << (*gr).info();

		while ((*gr).isValid()) {
			(*gr).time();
			h++;
			cout << (*gr).info();
		}
		delete gr;
	}
	catch (const bad_alloc &ex) { cout << ex.what() << endl; }
	catch (out_of_range) { cout << "Error"; };
	cout << "Пройшло" << h - 1 << "одиниць часу, до того як теплиця вийшла з ладу.";
	return 0;
}
