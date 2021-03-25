#include <iostream>
#include <vector>

namespace Constants
{
    constexpr int MAX_CARD = 52;
    constexpr int BLACK_JACK = 21;
}

enum Rank
{
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK = 10,
    QUEEN = 10,
    KING = 10,
    ACE = 11,
};

enum class Suit
{
    TREFU,
    BYBNU,
    CHERVU,
    PIKI,
};

class Card
{
private:
    Suit c_suit;
    Rank c_rank;
    bool c_position;

public:
    Card(Suit suit, Rank rank)
        : c_suit(suit), c_rank(rank), c_position(false)
    {	}

    void flip() { c_position = !c_position; }
    int getValue() const { return c_rank; }
};



class Hand
{
protected:
    std::vector<Card*> h_Cards;
public:
    Hand()
    {
        h_Cards.reserve(Constants::MAX_CARD);
    }

    void add(Card* pCard)
    {
        h_Cards.push_back(pCard);
    }

    void clear()
    {
        h_Cards.resize(0); // отношение между картой и рукой - агрегация. Поэтому освобождать память не нужно
    }

    int getTotal()
    {
        int sum{}, countAce{};

        for (const auto& el : h_Cards)
            if (el->getValue() == ACE)
                countAce++;
            else
                sum += el->getValue();

        std::cout << '>' << sum << '\n';
        while (countAce-- > 0)
            if (sum + ACE > Constants::BLACK_JACK)
                sum++;
            else
                sum += ACE;

        return sum;
    }

    void print()
    {
        if (h_Cards.empty())
        {
            std::cout << "Hand is empty" << std::endl;
            return;
        }

        for (const auto& elem : h_Cards)
            std::cout << elem->getValue() << " ";
        puts("");
    }
};

class Deck : public Hand
{

};

class GenericPlayer : public Hand
{

};

class Player : public GenericPlayer
{

};

class House : public GenericPlayer
{

};


int main(int argc, char const* argv[])
{
    Card c(Suit::PIKI, Rank::SEVEN);
    std::cout << c.getValue() << std::endl;

    Hand hand;
    hand.add(&c);
    hand.add(new Card(Suit::PIKI, Rank::TWO));
    hand.add(new Card(Suit::PIKI, Rank::ACE));
    //hand.add(new Card(Suit::PIKI, Rank::ACE));
    std::cout << hand.getTotal() << std::endl;

    hand.print();
    hand.clear();
    hand.print();
    std::cout << hand.getTotal() << std::endl;




    return 0;
}
