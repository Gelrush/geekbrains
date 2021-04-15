#pragma once

#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
    House(std::string name = "House");
    virtual ~House() { }

    virtual bool isHitting() const override;    // ����������, ����� �� ����� ���������� ����� �����
    void FlipFirstCard();                       // �������������� ������ �����
};