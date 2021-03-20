#include <iostream>

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
    JACK = 10,
    QUEEN = 10,
    KING = 10,
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
protected:
	Suit c_suit;
	Rank c_rank;
	bool position;
public:
	Card(Suit suit, Rank rank)
		: c_suit(suit), c_rank(rank), position(false)
	{	}

	void flip() { position = !position; }
	int getValue() const { return static_cast<int>(c_rank); }

};

int main(int argc, char const *argv[])
{
	Card c(Suit::PIKI, Rank::SEVEN);
	std::cout << c.getValue() << std::endl;
	
	return 0;
}