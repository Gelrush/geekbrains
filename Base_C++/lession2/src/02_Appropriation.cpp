#include <iostream>
#include <iomanip> //Имена флагов отображения чисел (hex, dex)

using namespace std;

int main(int argc,char** args)
{
	int a = 264000; // 32 разряда
	unsigned long b = 123456789; //от 64 до 128 разрядов в зависимости от разрядности машины

	cout << dec << a << endl;
	cout << hex << &a << endl; //адресс на переменную
	cout << dec << b << endl;
	cout << hex << &b << endl;

	return 0;
}
