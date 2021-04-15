#pragma once

#include <iostream>
#include "globals.h"

enum class Rank
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    SIZE,
};

enum class Suit
{
    TREFU,
    BYBNU,
    CHERVU,
    PIKI,
    SIZE,
};

class Card
{
private:
    Suit c_suit;
    Rank c_rank;
    bool c_isFaceUp;

    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

public:
    Card(Suit suit, Rank rank);

    void flip();
    int getValue() const;
    const std::string toStringRank() const;
    const std::string toStringSuit() const;
};