#include <iostream>

using namespace std;

void print(char str[7]) { 			// при передаче массива в функцию передается только ссылка 
									// на первый его элемент, поэтому в функции невозможно узнать
									// количество элементов
	str[3] = 'd';
	str[0] = 'x';
	cout << str << endl;
}

void print(int arr[5]) {			// перегрузка функции
	cout << arr << endl;
}

int main(int argc, char** args) {
	int ar[5] = {-1, 2, 3, 4, 5};
	char arr[7] = "str";
	print(arr);						// а так же значения изменяемые в функции
									// изменяют значения и в переданном массиве
	
	print(ar);						// следствие: выводится на экран адресс первого элемента а не сам массив
	cout << arr << endl;

	return 0;
}
