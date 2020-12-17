#include <iostream>

using namespace std;

int main(int argc, char **args) {
	const int NUM = 10;
	char arr[NUM];

	for(int i, j = 0; i < NUM; i++, j += 3) {
		arr[i] = 33 + j;
	}
	for(int i = 0; i < NUM; i++) {
		cout << arr[i] << "\t";
	}
	return 0;
}
