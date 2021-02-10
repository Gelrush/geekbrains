#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNum(int from, int to) 
{
	return static_cast<int>(rand() % (to - from + 1) + from);
}

int getUserNum()
{
	int in;
	while (true)
	{
		std::cout << "Enter a double value: ";
		std::cin >> in;

		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cout << "Incorrect input. Try again: ";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		} else return in;
	}
}
bool checkNum(int in, int base)
{
	if (in == base)
	{
		std::cout << "Congratulations!\n";
		return true;
	}
	if (in < base)
		std::cout << "Take it higher.\n";
	else std::cout << "Take it below.\n";
	return false;
}

bool willStill()
{
	char in;
	while (true)
	{
		std::cout << "End game! We will still? (y, n): ";
		std::cin >> in;

		if (std::cin.peek() == '\n') {
			if (in == 'y')
				return true;
			if (in == 'n')
				return false;
		}
		std::cin.ignore(32767, '\n');
	}
}

const int g_minRand(1);
const int g_maxRand(100);
const int g_countTry = 7;

void game()
{
	std::cout << "The computer picked up a random number from " << g_minRand << " to " << g_maxRand << std::endl;
	std::cout << "You have " << g_countTry << " attempts to guess!\n";
	bool continuation(true);
	while (continuation)
	{
		int randNum = getRandomNum(g_minRand, g_maxRand);
		int tryUser;
		bool win(false);
		for (int i = 0; i < g_countTry && !win; i++)
		{
			tryUser = getUserNum();
			win = checkNum(tryUser, randNum);
		}
		if (!win) 
			std::cout << "Trys ended. Correct answer " << randNum << std::endl;

		continuation = willStill();
	}
}

int main()
{   
	srand(static_cast<unsigned int>(time(0)));
	game();
	
    return 0;
}
