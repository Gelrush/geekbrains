#include "Player.h"

Player::Player(const std::string& name)
    : GenericPlayer(name)
{   }

bool Player::isHitting() const
{
    std::cout << g_name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    std::cout << g_name << " wins.\n";
}

void Player::lose() const
{
    std::cout << g_name << " loses.\n";
}

void Player::push() const
{
    std::cout << g_name << " pushes.\n";
}