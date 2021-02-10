#include <iostream>
#include <string>

int getValue()
{
    while (true)
    {
        int a;
        std::cin >> a;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear(); 
            std::cin.ignore(32767, '\n');
            std::cout << "Uncorrect input. ";
        }
        else
        {
            std::cin.ignore(32767, '\n'); 
            return a;
        }
    }
}

std::string* getArrName(int len)
{
    std::string* arrName = new std::string[len];
    for (int i = 0; i < len; i++)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        getline(std::cin, arrName[i]);
    }
    return arrName;
}

void sortSelect(std::string* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int smallIdx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[smallIdx] > arr[j])
                smallIdx = j;
        }
        std::swap(arr[i], arr[smallIdx]);
    }
}

void printArr(std::string* arr, int len)
{
    for (int i = 0; i < len; i++)
        std::cout << "Name #" << i + 1 << ": " << arr[i] << '\n';
}

int main()
{   
    std::cout << "How many names would you like to enter?: ";
    int countName = getValue();
    std::string* arrName = getArrName(countName);

    sortSelect(arrName, countName);

    std::cout << "Here is your sorted list:\n";
    printArr(arrName, countName);

    
    return 0;
}
