#pragma once

#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
    House(std::string name = "House");
    virtual ~House() { }

    virtual bool isHitting() const override;    // показывает, хочет ли дилер продолжать брать карты
    void FlipFirstCard();                       // переворачивает первую карту
};