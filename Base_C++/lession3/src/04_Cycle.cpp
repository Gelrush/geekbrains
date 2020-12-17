#include <iostream>

using namespace std;

int main(int argc, char **args) {
	unsigned int a;
	cout << "Введит целое число ";
	cin >> a;
	if(a > 3)
	do {
		cout << a << endl;
		a = a - 1;
	} while(a != 0);
	else cout << "Значение не подходит для цикла" << endl;

	return 0;
}
	
