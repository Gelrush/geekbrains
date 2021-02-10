#include <iostream>
#include <string>

bool isEqual(const std::string &str1, const std::string &str2)
{
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.size(); i++)
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;

    return true;
}

int main() 
{   
    std::string arrName[]{ "Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly" };
    std::cout << "Enter '0' to finish.\n";

    while (true)
    {
        std::cout << "Enter a name: ";

        std::string input;
        std::getline(std::cin, input);
        if (input == "0") break;

        bool check(false);
        for (const auto& name : arrName)
            if (isEqual(input, name))
            {
                check = true;
                break;
            }

        std::cout << input << " was" << (check? "" : " not") << " found.\n";
    }


    return 0;
}
