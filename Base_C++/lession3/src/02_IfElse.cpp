#include <iostream>

using namespace std;

int main() {
	int a;
	cout << "Введите целое число ";
	cin >> a;
	
	if(a > 5) {
		cout << "Введите другое число ";
		cin >> a;
	} else if((a > 5) && (a < 10))
		a -= 5;
	else a = 5 - a;

	if(a == 0)
		cout << "Результат программы равен нулю" << endl;
	if(a < 0)
		cout << "Результат программы меньше нуля" << endl;
	if(a > 0)
		cout << "Результат программы больше нуля" << endl;

	return 0;
}

