#include <iostream>
#include <cstdlib>									// для srand(), rand()
#include <ctime>									// для time()

using namespace std;

int main(int argc, char **args) {
	int sticks;
	srand(time(0));									// начальное значение для rand()
	cout << "Введите количество палочек\n";

	do {
		cout << "Их должно быть не более 30 и не менее 10: ";
		cin >> sticks;
	} while(sticks < 10 || sticks > 30);

	int stnumPl, stnumPC;
	while(sticks > 1) {
		cout << "На столе осталось палочек: " << sticks << endl;
		do {
			cout << "Возьмите палочки (от 1 до 3): ";
			cin >> stnumPl;
		} while(stnumPl < 1 || stnumPl > 3);
		sticks -= stnumPl;
		
		if(sticks < 2) {
			cout << "Вы победили" << endl;
			break;
		}
		
		if(sticks % 4 == 2) stnumPC = 1;
		else if(sticks % 4 == 3) stnumPC = 2;
		else if(sticks % 4 == 0) stnumPC = 3;
		else stnumPC = rand() % 3 + 1;				// генератор псевдослучайных чисел
		
		sticks -= stnumPC;
		cout << "Противник взял палочек:" << stnumPC << endl;
		
		if(sticks < 2) {
			cout << "Противник одержал победу" << endl;
		}
	}
	return 0;
}

