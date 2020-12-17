#include <iostream>

using namespace std;

enum constant_set 
{
	csNum1 = 5,
	csNum2 = 4,
	csNum3 = 3,
	csNum4 = 2,
	csNum5 = 1,
	csNum6 = 0
} numSet;

int main(int argc, char **args) {
	int x;
	cout << "Введит целое число ";
	cin >> x;

	switch(x)
	{
	case csNum1:
	case csNum2:
	case csNum3:
		cout << "Число > 2 && < 6" << endl;
		break;
	case csNum4:
	case csNum5:
	case csNum6:
		cout << "Число > -1 && < 3" << endl;
		break;
	default:
		cout << "Ваш символ не входит в множество!" << endl;
	}
	return 0;
}
