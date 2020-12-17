#include <iostream>
#include "03_head.h"

using namespace std;

int main(int argc, char ** args) {
	cout << funct(13, 4) << endl;
	return 0;
}

int funct(int a, int b) {
	return a % b;
}
