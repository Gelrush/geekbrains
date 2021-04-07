#pragma once

#include "GenericPlayer.h"

class Deck : public Hand
{
public:
    Deck() { };
    virtual ~Deck() { };

    void populate();                            // создает стандартную колоду из 52 карт
    void shuffle();                             // тасует карты
    void deal(Hand& aHand);                     // раздает одну карту в руку                              
    void addCards(GenericPlayer& aGP);          // дает дополнительные карты игроку
    void printTable();                          // выводит свободные карты
};