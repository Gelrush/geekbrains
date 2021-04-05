#include <iostream>
#include <vector>

namespace Constants
{
    constexpr int MAX_CARD = 52;
    constexpr int BLACK_JACK = 21;
}

enum Rank
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
    bool c_isFaceUp;

public:
    Card(Suit suit, Rank rank)
        : c_suit(suit), c_rank(rank), c_isFaceUp(false)
    {	}

    void flip() { c_isFaceUp = !c_isFaceUp; }
    Rank getRank() const { return c_rank; }
    
    int getValue() const
    {
        int value{0};
        if (c_isFaceUp)
        {
            value = c_rank;
            if (value > 10) return 10;
        }
        return value;
    }
    
    std::string toString() const
    {
        if (c_isFaceUp)
        {
            switch (c_rank)
            {
                case Rank::ACE:     return "ACE";
                case Rank::TWO:     return "TWO";
                case Rank::THREE:   return "THREE";
                case Rank::FOUR:    return "FOUR";
                case Rank::FIVE:    return "FIVE";
                case Rank::SIX:     return "SIX";
                case Rank::SEVEN:   return "SEVEN";
                case Rank::EIGHT:   return "EIGHT";
                case Rank::NINE:    return "NINE";
                case Rank::TEN:     return "TEN";
                case Rank::JACK:    return "JACK";
                case Rank::QUEEN:   return "QUEEN";
                case Rank::KING:    return "KING";
            }
        }
        else
            return "$";
    }
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
    
    virtual ~Hand()
    {
        clear();
    }

    void add(Card* pCard)
    {
        h_Cards.push_back(pCard);
    }

    void clear()
    {
        for (auto& elem : h_Cards)
            delete elem;
        
        h_Cards.clear();
    }

    int getTotal() const
    {
        int sum{0}, countAce{0};

        for (const auto& el : h_Cards)
        {
            sum += el->getValue();
            if (el->getValue() == ACE)
                countAce++;
        }

        while (countAce-- > 0)
            if (sum + 10 <= Constants::BLACK_JACK)
                sum += 10;
        
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
            std::cout << elem->toString() << " ";
        puts("");
    }
};

class Deck : public Hand
{

};

class GenericPlayer : public Hand
{
protected:
    std::string g_name;
public:
    GenericPlayer(std::string name)
        : g_name(name)
    {   }
    
    virtual bool isHitting() = 0;
    
    bool isBoosted() const
    {
        return (getTotal() > Constants::BLACK_JACK) ? true : false;
    }
    
    void bust() const
    {
        std::cout << g_name << " has too much!\n";
    }
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
    hand.add(new Card(Suit::PIKI, Rank::TWO));
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
