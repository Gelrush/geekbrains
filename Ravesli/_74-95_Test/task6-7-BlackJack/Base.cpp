#include <iostream>
#include <array>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include "constants.h"

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

enum class BlackjackResult
{
    BLACKJACK_PLAYER_WIN,
    BLACKJACK_DEALER_WIN,
    BLACKJACK_DRAW,
};

struct Card
{
    Card_rank rank;
    Card_suit suit;
};

void printCard(const Card &c)
{
    switch (c.rank)
    {
    case Card_rank::TWO:        std::cout << '2'; break;
    case Card_rank::THREE:      std::cout << '3'; break;
    case Card_rank::FOUR:       std::cout << '4'; break;
    case Card_rank::FIVE:       std::cout << '5'; break;
    case Card_rank::SIX:        std::cout << '6'; break;
    case Card_rank::SEVEN:      std::cout << '7'; break;
    case Card_rank::EIGHT:      std::cout << '8'; break;
    case Card_rank::NINE:       std::cout << '9'; break;
    case Card_rank::TEN:        std::cout << '0'; break;
    case Card_rank::JACK:       std::cout << 'V'; break;
    case Card_rank::QUEEN:      std::cout << 'Q'; break;
    case Card_rank::KING:       std::cout << 'K'; break;
    case Card_rank::ACE:        std::cout << 'A'; break;
    default:
        std::cout << '?';
        break;
    }
    switch (c.suit)
    {
    case Card_suit::TREFU:      std::cout << 'T'; break;
    case Card_suit::BYBNU:      std::cout << 'B'; break;
    case Card_suit::CHERVU:     std::cout << 'C'; break;
    case Card_suit::PIKI:       std::cout << 'P'; break;
    default:
        std::cout << '?';
        break;
    }
    std::cout << ' ';
}

std::array<Card, Constants::SIZE_CARDS> init()
{
    std::array<Card, Constants::SIZE_CARDS> arr;
    size_t i = 0;

    for (size_t r = 0; r < static_cast<int>(Card_rank::SIZE); r++)
    for (size_t s = 0; s < static_cast<int>(Card_suit::SIZE); s++)
        {
            arr[i].rank = static_cast<Card_rank>(r);
            arr[i].suit = static_cast<Card_suit>(s);
            ++i;
        }
    return arr;
}

void swapCard(Card& x, Card& y)
{
    Card tmp = x;
    x = y;
    y = tmp;
}

void shuffleDeck(std::array<Card, Constants::SIZE_CARDS> &deck)
{
    for (size_t i = 0; i < Constants::SIZE_CARDS; ++i)
        swapCard(deck[i], deck[rand() % 52]);
}

int getCardValue(const Card& c)
{
    switch (c.rank)
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

Card addCard(std::array<Card, Constants::SIZE_CARDS> &deck, int &idxCard)
{
    Card add = deck[idxCard++];

    if (Constants::SIZE_CARDS - idxCard == 0)
    {
        std::cout << "\nShuffle cards!\n";
        shuffleDeck(deck);
        idxCard = 0;
    }
    return add;
}

template<int SIZE>
void printDeck(const std::array<Card, SIZE>& deck, const int &len)
{
    for (int i = 0; i < len; ++i)
        printCard(deck[i]);
    puts("");
}

template<int SIZE>
int sumDeck(const std::array<Card, SIZE>& deck, const int& len)
{
    int sum{ 0 }, countTyz{ 0 };
    for (int i = 0; i < len; ++i)
    {
        if (deck[i].rank == Card_rank::ACE)
        {
            countTyz++;
            continue;
        }
        sum += getCardValue(deck[i]);
    }
    while (countTyz)
    {
        if (sum + static_cast<int>(Card_rank::ACE) > Constants::BLACKJACK)
            sum++;
        countTyz--;
    }
    return sum;
}

bool getCheck()
{
    int check;
    while (true)
    {
        std::cin >> check;

        if (std::cin.fail() || std::cin.peek() != '\n' || (check != 0 && check != 1))
        {
            std::cout << "Uncorrect enter. ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            return (check == 1 ? true : false);
        }
    }
}

BlackjackResult playBlackjack(std::array<Card, Constants::SIZE_CARDS> &deck)
{
    std::array<Card, Constants::MAX_CARD_IN_HAND> dealer; int sumDealer;
    std::array<Card, Constants::MAX_CARD_IN_HAND> player; int sumPlayer;

    int idxDealer{}, idxPlayer{};
    static int idxCard{};

    std::cout << "\tStart.\n";
    std::cout << "Dealer receives a card: ";
    dealer[idxDealer++] = addCard(deck, idxCard);
    printDeck(dealer, idxDealer);

    std::cout << "Your 2 cards: ";
    player[idxPlayer++] = addCard(deck, idxCard);
    
    bool hit;
    do
    {
        player[idxPlayer++] = addCard(deck, idxCard);
        std::cout << "Your cards: ";
        printDeck(player, idxPlayer);
        std::cout << "\n\"hit\"(1) or \"stand\"(0)? ";
        hit = getCheck();
    } while (hit && idxPlayer < Constants::MAX_CARD_IN_HAND);

    sumPlayer = sumDeck(player, idxPlayer);
    
    if (sumPlayer > Constants::BLACKJACK)
    {
        std::cout << "You lose. Amount of cards: " << sumPlayer << std::endl;
        return BlackjackResult::BLACKJACK_DEALER_WIN;
    }
    if (sumPlayer == Constants::BLACKJACK)
    {
        std::cout << "You win. Blackjack!!" << std::endl;
        return BlackjackResult::BLACKJACK_PLAYER_WIN;
    }

    do
    {
        dealer[idxDealer++] = addCard(deck, idxCard);
        sumDealer = sumDeck(dealer, idxDealer);
    } while (sumDealer < Constants::MAX_RANK_DEALER);
    std::cout << "Dealer\'s cards: ";
    printDeck(dealer, idxDealer);

    if (sumDealer > Constants::BLACKJACK)
    {
        std::cout << "You win. Dealer has too much: " << sumDealer << std::endl;
        return BlackjackResult::BLACKJACK_PLAYER_WIN;
    }
    if (sumDealer == Constants::BLACKJACK)
    {
        std::cout << "You lose. Dealer has Blackjack!!" << std::endl;
        return BlackjackResult::BLACKJACK_DEALER_WIN;
    }
    if (sumPlayer > sumDealer)
    {
        std::cout << "You win. Your cards: " << sumPlayer << ". Dealer cards: " << sumDealer << std::endl;
        return BlackjackResult::BLACKJACK_PLAYER_WIN;
    }
    if (sumPlayer < sumDealer)
    {
        std::cout << "You lose. Your cards: " << sumPlayer << ". Dealer cards: " << sumDealer << std::endl;
        return BlackjackResult::BLACKJACK_DEALER_WIN;
    }
    if (sumPlayer == sumDealer)
        std::cout << "Draw! Your cards: " << sumPlayer << ". Dealer cards: " << sumDealer << std::endl;
    return BlackjackResult::BLACKJACK_DRAW;
}

int main() 
{   
    srand(static_cast<unsigned int>(time(0)));
    std::array<Card, Constants::SIZE_CARDS> deck = init();
    shuffleDeck(deck);

    while (true)
    {
        std::cout << "Will play? (0 or 1) ";
        bool check = getCheck();
        if (check)
            playBlackjack(deck);
        else break;
    }

    return 0;
}
