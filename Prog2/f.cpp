//������ ������� ����
#include "greenhouse.h"
#include <iostream>

using namespace std;

int selectModel() {
	int c = 0;
	cout << "� ��� ����� �������: ���������� (��� �����������: 10-30 ������� �� ������, �������� 40-90%);\n";
	cout << "����� - ������� ��� ����������� ������ (25-38 ������� �� ������, 30-60%); ����� - ������� ��� ������������\n";
	cout << "�� ����� ������ (0-15 ������� �� ������, 55-87%). ��� �������� ������ ������ ������ �������: \n";
	cout << "�������� 1, ��� ������ ����� ������.\n";
	cout << "�������� 2, ��� ������ ����� ������.\n";
	cout << "�������� 3, ��� ������ ����� ������.\n";
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
	default: cout << "�� ������ ����� �� � �������. "; throw out_of_range("�������.\n");
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
	cout << "�������" << h - 1 << "������� ����, �� ���� �� ������� ������ � ����.";
	return 0;
}
