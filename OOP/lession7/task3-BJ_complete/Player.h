#pragma once

#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");
    virtual ~Player() {}

    virtual bool isHitting() const override;    // показывает, хочет ли игрок продолжать брать карты
    void win() const;                           // объ€вл€ет, что игрок победил
    void lose() const;                          // объ€вл€ет, что игрок проиграл
    void push() const;                          // объ€вл€ет ничью
};