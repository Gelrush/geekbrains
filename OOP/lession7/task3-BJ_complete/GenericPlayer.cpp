#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& name)
    : g_name(name)
{   }

bool GenericPlayer::isBusted() const
{
    return getTotal() > Constants::BLACK_JACK;
}

void GenericPlayer::bust() const
{
    std::cout << g_name << " has too much!\n";
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.g_name << ":\t";

    if (!aGenericPlayer.h_Cards.empty())
    {
        for (const auto& card : aGenericPlayer.h_Cards)
            os << *card << "\t";
        std::cout << "(" << aGenericPlayer.getTotal() << ")";
    }
    else
        os << "<empty>";

    return os;
}