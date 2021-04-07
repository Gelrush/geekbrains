#pragma once

#include <iostream>
#include "Hand.h"

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

protected:
    std::string g_name;

public:
    GenericPlayer(const std::string& name);
    virtual ~GenericPlayer() {}

    virtual bool isHitting() const = 0;         // показывает, хочет ли игрок продолжать брать карты
    bool isBusted() const;                      // возвращает значение, если у игрока перебор
    void bust() const;                          // объявляет, что игрок имеет перебор
};