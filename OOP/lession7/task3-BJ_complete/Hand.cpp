#include "Hand.h"

Hand::Hand() { h_Cards.reserve(Constants::MAX_CARD); }

Hand::~Hand() { clear(); }

void Hand::add(Card* pCard) { h_Cards.push_back(pCard); }

void Hand::clear()
{
    for (auto& elem : h_Cards)
        delete elem;

    h_Cards.clear();
}

int Hand::getTotal() const
{
    int sum{ 0 }, countAce{ 0 };

    for (const auto& el : h_Cards)
    {
        sum += el->getValue();
        if (el->getValue() == static_cast<int>(Rank::ACE))
            countAce++;
    }

    while (countAce-- > 0)
        if (sum + 10 <= Constants::BLACK_JACK)
            sum += 10;

    return sum;
}