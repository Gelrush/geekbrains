#pragma once

#include <vector>
#include "Card.h"

class Hand
{
protected:
    std::vector<Card*> h_Cards;
public:
    Hand();
    virtual ~Hand();

    void add(Card* pCard);
    void clear();
    int getTotal() const;
};