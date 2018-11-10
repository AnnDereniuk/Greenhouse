//робота Деренюк Анни
#include "greenhouse.h"
#include"create.h"
#include <iostream>
using namespace std;

int menu() {
	int c = 0;
	//виведення списку можливих дій
	cout << "Натиснiть 1, щоб вiдчинити вiкно" << "\n";
	cout << "Натиснiть 2, щоб зачинити вiкно" << "\n";
	cout << "Натиснiть 3, щоб увiмкнути обiгрiвач" << "\n";
	cout << "Натиснiть 4, щоб вимкнути обiгрiвач" << "\n";
	cout << "Натиснiть 5, щоб припинити керування" << "\n";
	cout << "Натиснiть 6, щоб пройшла одиниця часу" << "\n";
	cin >> c; //отримання дії від користувача

	if (cin.fail()) {//обробка помилок
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
					else cout << "Неможливо виконати дiю.\n";
					break;
			case 2: if ((*gr).isValid() && (*gr).isWindowOpened()) {
				(*gr).toCloseWindow();
			}
					else cout << "Неможливо виконати дiю.\n";
					break;
			case 3: if ((*gr).isValid() && !(*gr).isHeaterOn()) {
				(*gr).toOnHeater();
			}
					else cout << "Неможливо виконати дiю.\n";
					break;
			case 4:if ((*gr).isValid() && (*gr).isHeaterOn()) {
				(*gr).toOfHeater();
			}
				   else cout << "Неможливо виконати дiю.\n";
				   break;
			case 5: cout << "Iнтерактивне керування теплицею завершено.";
				break;
			case 6: (*gr).time();
				break;
			default: cout << "Помилка: ви обрали цифру не з перелiку.\n";
				break;
			}
			cout << (*gr).info();
		}
}