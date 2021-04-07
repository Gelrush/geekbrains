#include "Deck.h"
#include <algorithm>
#include <random>

void Deck::populate()
{
    clear();

    for (int r = 1; r < (int) Rank::SIZE; ++r)
        for (int s = 0; s < (int)Suit::SIZE; ++s)
            add(new Card(static_cast<Suit>(s), static_cast<Rank>(r)));
}

void Deck::shuffle()
{
    /*std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(h_Cards.begin(), h_Cards.end(), g);*/

    for (int i = 0; i < Constants::MAX_CARD; ++i)
        std::swap(h_Cards[i], h_Cards[rand() % 52]);
}

void Deck::deal(Hand& aHand)
{
    if (!h_Cards.empty())
    {
        aHand.add(h_Cards.back());
        h_Cards.pop_back();
    }
    else
    {
        std::cout << "Out of cards. Unable to deal.";
    }
}

void Deck::addCards(GenericPlayer& aGP)
{
    std::cout << std::endl;

    while (!(aGP.isBusted()) && aGP.isHitting())
    {
        deal(aGP);
        std::cout << aGP << std::endl;

        if (aGP.isBusted())
        {
            aGP.bust();
        }
    }
}

void Deck::printTable()
{
    for (auto& elCard : h_Cards)
        std::cout << *elCard << ' ';
    std::cout << std::endl;
}

