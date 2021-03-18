#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace Constants
{
    const int SIZE_CARDS = 52;
    const int MAX_CARD_IN_HAND = 11;
    const int BLACKJACK = 21;
    const int MAX_RANK_DEALER = 17;
    const int MIN_CARD_IN_DECK = 10;
}

enum class Card_rank
{
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
    ACE,
    SIZE
};

enum class Card_suit
{
    TREFU,
    BYBNU,
    CHERVU,
    PIKI,
    SIZE
};

enum class BJ_Message
{
    PLAYER_ENDGAME,
    PLAYER_PLAY,
    PLAYER_STAND,
    PLAYER_HIT,
    PLAYER_SHOW_NUM_DECK,
    PLAYER_SHUFFLE,
    BLACKJACK_PLAYER_WIN,
    BLACKJACK_DEALER_WIN,
    BLACKJACK_DRAW,
    ERROR_EMPTY_DECK,
    ERROR_MAX_HAND,
    SUCCESS,
    SKIP,
};

class Card
{
private:
    Card_rank c_rank;
    Card_suit c_suit;

public:
    Card()
        : c_rank(Card_rank::TWO), c_suit(Card_suit::TREFU)
    {   }
    Card(Card_rank rank, Card_suit suit)
        : c_rank(rank), c_suit(suit)
    {   }

    void printCard() const
    {
        switch (c_rank)
        {
        case Card_rank::TWO:        std::cout << "[2:"; break;
        case Card_rank::THREE:      std::cout << "[3:"; break;
        case Card_rank::FOUR:       std::cout << "[4:"; break;
        case Card_rank::FIVE:       std::cout << "[5:"; break;
        case Card_rank::SIX:        std::cout << "[6:"; break;
        case Card_rank::SEVEN:      std::cout << "[7:"; break;
        case Card_rank::EIGHT:      std::cout << "[8:"; break;
        case Card_rank::NINE:       std::cout << "[9:"; break;
        case Card_rank::TEN:        std::cout << "[10:"; break;
        case Card_rank::JACK:       std::cout << "[V:"; break;
        case Card_rank::QUEEN:      std::cout << "[Q:"; break;
        case Card_rank::KING:       std::cout << "[K:"; break;
        case Card_rank::ACE:        std::cout << "[A:"; break;
        default:
            std::cout << '?';
            break;
        }
        switch (c_suit)
        {
        case Card_suit::TREFU:      std::cout << "Tref]"; break;
        case Card_suit::BYBNU:      std::cout << "Bybi]"; break;
        case Card_suit::CHERVU:     std::cout << "Cherv]"; break;
        case Card_suit::PIKI:       std::cout << "Piki]"; break;
        default:
            std::cout << '?';
            break;
        }
        std::cout << ' ';
    }

    int getCardValue() const
    {
        switch (c_rank)
        {
        case Card_rank::TWO:        return 2;
        case Card_rank::THREE:      return 3;
        case Card_rank::FOUR:       return 4;
        case Card_rank::FIVE:       return 5;
        case Card_rank::SIX:        return 6;
        case Card_rank::SEVEN:      return 7;
        case Card_rank::EIGHT:      return 8;
        case Card_rank::NINE:       return 9;
        case Card_rank::TEN:
        case Card_rank::JACK:
        case Card_rank::QUEEN:
        case Card_rank::KING:
        case Card_rank::ACE:        return 10;
        }
        return 0;
    }

    Card_rank getRank() const { return c_rank; }
    Card_suit getSuit() const { return c_suit; }
};

class Deck
{
protected:
    std::vector<Card> d_deck;

private:
    void init()
    {
        size_t i = 0;
        for (size_t r = 0; r < static_cast<int>(Card_rank::SIZE); r++)
            for (size_t s = 0; s < static_cast<int>(Card_suit::SIZE); s++)
                d_deck[i++] = Card(static_cast<Card_rank>(r), static_cast<Card_suit>(s));
    }

    void swapCard(Card& c)
    {
        Card tmp = d_deck.back();
        d_deck.back() = c;
        c = tmp;
    }

public:
    Deck()
    {
        d_deck.resize(Constants::SIZE_CARDS);
        init();
        shuffleDeck();
    }
    Deck(int x)
    {
        d_deck.reserve(Constants::MAX_CARD_IN_HAND);
    }

    bool getCard(Card& out)
    {
        if (d_deck.size() == 0)
        {
            std::cerr << "Error: No cards left in the deck" << std::endl;
            return false;
        }

        out = d_deck.back();
        d_deck.pop_back();

        if (d_deck.size() < Constants::MIN_CARD_IN_DECK)
            std::cerr << "Warning: " << d_deck.size() << " cards left in the deck" << std::endl;

        return true;
    }

    void shuffleDeck()
    {
        int countCards = d_deck.size();
        for (size_t i = 0; i < countCards; ++i)
            swapCard(d_deck[rand() % countCards]);
    }
    
    int getNumCards() const
    {
        return d_deck.size();
    }
};

class Player : private Deck
{
private:
    std::string p_name;
    int handValue{ 0 };

public:
    Player(std::string name)
        : Deck(1), p_name(name)
    {   }

    std::string getName() const { return p_name; }

    void printHand() const
    {
        std::cout << ">" << p_name << "'s cards: ";
        for (const auto& elem : d_deck)
            elem.printCard();
        puts("");
    }

    BJ_Message add(Deck& din)
    {
        if (d_deck.size() >= Constants::MAX_CARD_IN_HAND)
        {
            std::cerr << "Error: Maximum cards im hand" << std::endl;
            return BJ_Message::ERROR_MAX_HAND;
        }
        
        Card tmp;
        int countTyz{ 0 }, sum{ 0 };

        if (din.getCard(tmp))
        {
            d_deck.push_back(tmp);

            for (const auto& elem : d_deck)
            {
                if (elem.getRank() == Card_rank::ACE)
                    countTyz++;
                else
                    sum += elem.getCardValue();
            }

            while (countTyz)
            {
                if (sum + static_cast<int>(Card_rank::ACE) > Constants::BLACKJACK)
                    sum++;
                countTyz--;
            }

            handValue = sum;
        }
        else return BJ_Message::ERROR_EMPTY_DECK;
        return BJ_Message::SUCCESS;
    }
    
    int getHandValue() const 
    { 
        return handValue; 
    }
};

int getValue()
{    
    int check;
    while (true)
    {
        std::cin >> check;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "Uncorrect enter. ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            return check;
        }
    }
}

inline BJ_Message getAnswer()
{
    std::cout << "\nEnter action \'0\' or \'1\' \t(show num card in deck \'2\') or (shuffle deck \'3\')  ";

    int answer;
    do {
        answer = getValue();
    } while (answer < 0 || answer > 3);

    return static_cast<BJ_Message>(answer + 2);
}

inline BJ_Message beginMessage()
{
    std::cout << "Will play? \'0\' or \'1\': ";

    int answer;
    do {
        answer = getValue();
    } while (answer < 0 || answer > 1);

    return static_cast<BJ_Message>(answer);
}

BJ_Message resultCalc(Player player, Player dealer)
{
    if (dealer.getHandValue() == 0)
    {
        if (player.getHandValue() > Constants::BLACKJACK)
        {
            std::cout << "You lose. Amount of cards: " << player.getHandValue() << "\n\n";
            return BJ_Message::BLACKJACK_DEALER_WIN;
        }
        if (player.getHandValue() == Constants::BLACKJACK)
        {
            std::cout << "You win. Blackjack!!" << "\n\n";
            return BJ_Message::BLACKJACK_PLAYER_WIN;
        }
        return BJ_Message::SUCCESS;
    }
    else
    {
        if (dealer.getHandValue() > Constants::BLACKJACK)
        {
            std::cout << "You win. Dealer has too much: " << dealer.getHandValue() << "\n\n";
            return BJ_Message::BLACKJACK_PLAYER_WIN;
        }
        if (dealer.getHandValue() == Constants::BLACKJACK)
        {
            std::cout << "You lose. Dealer has Blackjack!!" << "\n\n";
            return BJ_Message::BLACKJACK_DEALER_WIN;
        }
        if (player.getHandValue() > dealer.getHandValue())
        {
            std::cout << "You win. Your cards: " << player.getHandValue() << ". Dealer cards: " << dealer.getHandValue() << "\n\n";
            return BJ_Message::BLACKJACK_PLAYER_WIN;
        }
        if (player.getHandValue() < dealer.getHandValue())
        {
            std::cout << "You lose. Your cards: " << player.getHandValue() << ". Dealer cards: " << dealer.getHandValue() << "\n\n";
            return BJ_Message::BLACKJACK_DEALER_WIN;
        }
        if (player.getHandValue() == dealer.getHandValue())
            std::cout << "Draw! Your cards: " << player.getHandValue() << ". Dealer cards: " << dealer.getHandValue() << "\n\n";
        return BJ_Message::BLACKJACK_DRAW;
    }
}

BJ_Message gameBlackJack(Deck& deck)
{
    Player dealer("Dealer");
    Player player("Semen");

    puts("");
    player.add(deck);
    player.printHand();
    player.add(deck);

    BJ_Message check;
    do
    {
    tryAgain:
        check = getAnswer();
        puts("");

        if (check == BJ_Message::PLAYER_HIT)
            player.printHand();

        if (check == BJ_Message::PLAYER_SHOW_NUM_DECK)
        {
            std::cout << deck.getNumCards() << " cards in a deck\n";
            goto tryAgain;
        }

        if (check == BJ_Message::PLAYER_SHUFFLE)
            return BJ_Message::ERROR_EMPTY_DECK;

        if (check == BJ_Message::PLAYER_ENDGAME)
            return check;

    } while (check == BJ_Message::PLAYER_HIT && player.add(deck) != BJ_Message::ERROR_MAX_HAND);

    check = resultCalc(player, dealer);
    if (check != BJ_Message::SUCCESS)
        return check;

    while (dealer.getHandValue() < Constants::MAX_RANK_DEALER)
        if (check == BJ_Message::ERROR_EMPTY_DECK)
            return check;
        else
            check = dealer.add(deck);
    
    dealer.printHand();

    return resultCalc(player, dealer);
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    Deck deck;
    BJ_Message result, play = beginMessage();

    int scorePl{}, scoreDl{};
    while (play != BJ_Message::PLAYER_ENDGAME)
    {
        result = gameBlackJack(deck);
        switch (result)
        {
        case BJ_Message::BLACKJACK_DEALER_WIN:
            scoreDl++;
            break;
        case BJ_Message::BLACKJACK_PLAYER_WIN:
            scorePl++;
            break;
        case BJ_Message::BLACKJACK_DRAW:
        case BJ_Message::PLAYER_ENDGAME:
            break;
        case BJ_Message::ERROR_EMPTY_DECK:
            deck.shuffleDeck();
            break;
        }
        play = beginMessage();
        system("cls");
    }

    std::cout << "Total score:\n Player - " << scorePl << "\tDealer - " << scoreDl << std::endl;

    return 0;
}
