#include <iostream>
#include <string>

namespace EQUIP
{
    enum Equip
    {
        HEALTH_POTION,
        TORCHE,
        ARROW,
        MAX_ITEMS,
    };
}

enum class MonsterType
{
    OGRE,
    GOBLIN,
    SKELETON,
    ORC,
    TROLL,
};

struct Player
{
    std::string name;
    MonsterType race;
    int kit[EQUIP::MAX_ITEMS];
};

int countTotalItems(Player *p)
{
    int sumEquip{ 0 };
    for (auto& i : p->kit)
        sumEquip += i;

    return sumEquip;
}

int main() 
{   
    Player gelrush{ "gelrush", MonsterType::TROLL, { 3, 6, 12 } };

    std::cout << "The sum of all " << gelrush.name << "'s equipment: " << countTotalItems(&gelrush) << std::endl;

    return 0;
}
