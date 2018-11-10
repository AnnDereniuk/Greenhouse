//������ ������� ����
#include "greenhouse.h"
#include"create.h"
#include <iostream>
using namespace std;

int menu() {
	int c = 0;
	//��������� ������ �������� ��
	cout << "������i�� 1, ��� �i������� �i���" << "\n";
	cout << "������i�� 2, ��� �������� �i���" << "\n";
	cout << "������i�� 3, ��� ��i������ ��i��i���" << "\n";
	cout << "������i�� 4, ��� �������� ��i��i���" << "\n";
	cout << "������i�� 5, ��� ��������� ���������" << "\n";
	cout << "������i�� 6, ��� ������� ������� ����" << "\n";
	cin >> c; //��������� 䳿 �� �����������

	if (cin.fail()) {//������� �������
		cin.clear(); cin.sync(); cin.ignore(5, '\n');
		return -1;
	}

	return c;
}


void action(Greenhouse*gr) {
		cout << (*gr).info();
		int c = 0;
		while (c != 5) {
			c = menu();
			switch (c) {
			case 1: if ((*gr).isValid() && !(*gr).isWindowOpened()) {
				(*gr).toOpenWindow();
			}
					else cout << "��������� �������� �i�.\n";
					break;
			case 2: if ((*gr).isValid() && (*gr).isWindowOpened()) {
				(*gr).toCloseWindow();
			}
					else cout << "��������� �������� �i�.\n";
					break;
			case 3: if ((*gr).isValid() && !(*gr).isHeaterOn()) {
				(*gr).toOnHeater();
			}
					else cout << "��������� �������� �i�.\n";
					break;
			case 4:if ((*gr).isValid() && (*gr).isHeaterOn()) {
				(*gr).toOfHeater();
			}
				   else cout << "��������� �������� �i�.\n";
				   break;
			case 5: cout << "I����������� ��������� �������� ���������.";
				break;
			case 6: (*gr).time();
				break;
			default: cout << "�������: �� ������ ����� �� � �����i��.\n";
				break;
			}
			cout << (*gr).info();
		}
}