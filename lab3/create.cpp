//������ ������� ����
#include<iostream>
#include "greenhouse.h"
#include "create.h"
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

Greenhouse *createGr() {

	switch (selectModel()) {
	case 1:  return new FirstGreenhouse;
		break;
	case 2:  return new SecondGreenhouse;
		break;
	case 3: return new ThirdGreenhouse;
		break;
	default: cout << "�� ������ ����� �� � �������.\n "; throw out_of_range("�������.\n");
		break;
	}
}
