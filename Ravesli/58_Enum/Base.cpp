#include <iostream>
#include <string>

enum Colors
{
    COLOR_PURPLE, // присваивается 0
    COLOR_GRAY, // присваивается 1
    COLOR_BLUE = -4, // присваивается -4
    COLOR_GREEN, // присваивается -3
    COLOR_BROWN, // присваивается -2
    COLOR_PINK = 10, // присваивается 10
    COLOR_YELLOW, // присваивается 11
    COLOR_MAGENTA // присваивается 12
};
 
void printColor(Colors color)
{
    if (color == COLOR_PURPLE)
        std::cout << "Purple";
    else if (color == COLOR_GRAY)
        std::cout << "Gray";
    else if (color == COLOR_BLUE)
        std::cout << "Blue";
    else if (color == COLOR_GREEN)
        std::cout << "Green";
    else if (color == COLOR_BROWN)
        std::cout << "Brown";
    else if (color == COLOR_PINK)
        std::cout << "Pink";
    else if (color == COLOR_YELLOW)
        std::cout << "Yellow";
    else if (color == COLOR_MAGENTA)
        std::cout << "Magenta";
    else
        std::cout << "Who knows!";
}

enum ItemType
{
    ITEMTYPE_GUN,
    ITEMTYPE_ARBALET,
    ITEMTYPE_SWORD
};
 
std::string getItemName(ItemType itemType)
{
    if (itemType == ITEMTYPE_GUN)
        return std::string("Gun");
    if (itemType == ITEMTYPE_ARBALET)
        return std::string("Arbalet");
    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
}

namespace StudentNames // для ошибок связанными с глобальным пространтвом имен
{
    enum StudentNames
    {
        SMITH, // 0
        ANDREW, // 1
        IVAN, // 2
        JOHN, // 3
        ANTON, // 4
        MISHA, // 5
        MAX_STUDENTS // 6
    };
}

int main()
{
    cout << "Hello World!\n";
    
    // ItemType - это перечисляемый тип, который мы объявили выше.
    // itemType (с маленькой i) - это имя переменной, которую мы определяем ниже (типа ItemType).
    // ITEMTYPE_GUN - это значение перечислителя, которое мы присваиваем переменной itemType
    ItemType itemType(ITEMTYPE_GUN);
 
    std::cout << "You are carrying a " << getItemName(itemType) << "\n";

    int john = StudentNames::JOHN;


    return 0;
}