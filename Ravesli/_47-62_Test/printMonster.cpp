#include <iostream>
#include <string>

enum class MonsterType
{
    Orge,
    Goblin,
    Skeleton, 
    Orc,
    Troll,
};

struct Monster
{
    MonsterType type;
    std::string name;
    int health = 10;
};

std::string getMosterType(MonsterType t)
{
    switch (t) {
    case MonsterType::Orge:
        return "Ogre";
    case MonsterType::Goblin:
        return "Goblin";
    case MonsterType::Skeleton:
        return "Skeleton";
    case MonsterType::Orc:
        return "Orc";
    case MonsterType::Troll:
        return "Troll";
    default:
        return "Unknown";
    }
}

void printMonster(Monster unit)
{
    std::cout << "This " << getMosterType(unit.type) << " is named "
        << unit.name << " and has " << unit.health << " health." << std::endl;
}

int main()
{
    Monster un1{ MonsterType::Troll, "Gelrush", 250 };
    Monster un2{ MonsterType::Orc, "Greyfield", 300 };

    printMonster(un1);
    printMonster(un2);


    return 0;
}