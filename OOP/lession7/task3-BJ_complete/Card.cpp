#include "Card.h"

Card::Card(Suit suit, Rank rank)
    : c_suit(suit), c_rank(rank), c_isFaceUp(true)
{	}

void Card::flip() { c_isFaceUp = !c_isFaceUp; }

int Card::getValue() const
{
    int value{ 0 };
    if (c_isFaceUp)
    {
        value = static_cast<int>(c_rank);
        if (value > 10) return 10;
    }
    return value;
}

const std::string Card::toStringRank() const    // мне кажется так безопаснее
{
    switch (c_rank)
    {
    case Rank::ACE:         return "A";
    case Rank::TWO:         return "2";
    case Rank::THREE:       return "3";
    case Rank::FOUR:        return "4";
    case Rank::FIVE:        return "5";
    case Rank::SIX:         return "6";
    case Rank::SEVEN:       return "7";
    case Rank::EIGHT:       return "8";
    case Rank::NINE:        return "9";
    case Rank::TEN:         return "10";
    case Rank::JACK:        return "J";
    case Rank::QUEEN:       return "Q";
    case Rank::KING:        return "K";
    default:                return "Er";
    }
}

const std::string Card::toStringSuit() const
{
    switch (c_suit)
    {
    case Suit::TREFU:       return "c";
    case Suit::BYBNU:       return "d";
    case Suit::CHERVU:      return "h";
    case Suit::PIKI:        return "s";
    default:                return "Es";
    }
}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    if (aCard.c_isFaceUp)
        os << aCard.toStringRank() << aCard.toStringSuit();
    else
        os << "XX";

    return os;
}