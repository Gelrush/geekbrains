/*
Lession №2 - Type and funct
by D. Frolov
vim + gcc
14.10.2020
*/

#include <iostream>
#include "03_head.h"

using namespace std;

void print(char str[4]) {
		cout << str << endl;
}

int main(int argc, char** args) {
							// №1
	short a = 45000;
	unsigned char b = 1400;

	cout << a << endl;
	cout << b << endl;
							// №2
	cout << funct(13, 4) << endl;
							// №3
	char arr[4] = {'s', 't', 'r', 'd' };
	print(arr);

	return 0;
}

int funct(int a, int b) {
	return a % b;
}
