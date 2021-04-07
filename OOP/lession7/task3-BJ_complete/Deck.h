#pragma once

#include "GenericPlayer.h"

class Deck : public Hand
{
public:
    Deck() { };
    virtual ~Deck() { };

    void populate();                            // ������� ����������� ������ �� 52 ����
    void shuffle();                             // ������ �����
    void deal(Hand& aHand);                     // ������� ���� ����� � ����                              
    void addCards(GenericPlayer& aGP);          // ���� �������������� ����� ������
    void printTable();                          // ������� ��������� �����
};