#include <iostream>
#include <vector>

namespace Constants
{
    constexpr int MAX_CARD = 52;
    constexpr int BLACK_JACK = 21;
    constexpr int MAX_CARD_DEALER = 21;
}

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

    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

public:
    Card(Suit suit, Rank rank);

    void flip();
    int getValue() const;
};

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

class Deck : public Hand
{

};

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

protected:
    std::string g_name;

public:
    GenericPlayer(const std::string& name);
    virtual ~GenericPlayer() {}

    virtual bool isHitting() const = 0;
    bool isBoosted() const;
    void bust() const;
};

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");
    virtual ~Player() {}
    
    virtual bool isHitting() const override;    // показывает, хочет ли игрок продолжать брать карты
    void win() const;
    void lose() const;
    void push() const;
};

class House : public GenericPlayer
{
public:
    House(std::string name = "House");
    virtual ~House() { }

    virtual bool isHitting() const override;
    void FlipFirstCard();
};



int main(int argc, char const* argv[])
{
    Card c(Suit::PIKI, Rank::SEVEN);
    std::cout << c.getValue() << std::endl;

    Player pl1("Denis");
    House pl2;

    pl1.add(new Card(Suit::PIKI, Rank::EIGHT));
    pl1.add(new Card(Suit::PIKI, Rank::ACE));

    pl2.add(new Card(Suit::PIKI, Rank::FIVE));
    pl2.add(new Card(Suit::PIKI, Rank::ACE));
    pl2.FlipFirstCard();

    std::cout << pl1.getTotal() << std::endl;
    std::cout << pl1 << std::endl;
    std::cout << pl2 << std::endl;




    return 0;
}



    /*********  implementation class Card  *********/

Card::Card(Suit suit, Rank rank)
    : c_suit(suit), c_rank(rank), c_isFaceUp(false)
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

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.c_isFaceUp)
        os << RANKS[static_cast<int>(aCard.c_rank)] << SUITS[static_cast<int>(aCard.c_suit)];
    else
        os << "XX";

    return os;
}


    /*********  implementation class Hand  *********/

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


    /*********  implementation class GenericPlayer  *********/

GenericPlayer::GenericPlayer(const std::string& name)
    : g_name(name)
{   }

bool GenericPlayer::isBoosted() const
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


    /*********  implementation class Player  *********/

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


    /*********  implementation class House  *********/

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