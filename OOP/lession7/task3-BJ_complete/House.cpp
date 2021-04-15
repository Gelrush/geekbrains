#include "House.h"

House::House(std::string name)
    : GenericPlayer(name)
{   }

bool House::isHitting() const
{
    return getTotal() <= Constants::MAX_CARD_DEALER;
}

void House::FlipFirstCard()
{
    if (h_Cards.empty())
        std::cout << "No card to flip!\n";
    else
        h_Cards[0]->flip();
}