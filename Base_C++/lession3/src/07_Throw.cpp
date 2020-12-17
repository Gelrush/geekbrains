#include <iostream>
#include <exception>

using namespace std;

int main(int argc, char **args) {
	int a;
	cin >> a;
	try {
		if(a == 0) throw std::runtime_error("Division by zero\n");		// создание исключения
								// можно создать просто строку (ее тип для перехвата будет char const*)
								// а можно использовать переменную из библиотеки exception
		cout << 4 / a;
	} 
	catch(std::runtime_error &e) {					// перехватить созданную в throw строку
		cout << e.what();
	}

	return 0;
}
