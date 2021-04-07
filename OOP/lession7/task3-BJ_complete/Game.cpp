#include "Game.h"

Game::Game(const std::vector<std::string>& names)
{
    // ������� ������ ������� �� ������� � �������
    std::vector<std::string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        m_Players.push_back(Player(*pName));
    }

    srand(static_cast<unsigned int>(time(0)));
    m_Deck.populate();
    m_Deck.shuffle();
}


void Game::play()
{
    // ������� ��� ������
    //m_Deck.printTable();

    // ������� ������� �� ��� ��������� �����
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (auto& pPlayer : m_Players)
            m_Deck.deal(pPlayer);
        m_Deck.deal(m_House);
    }

    // ������ ������ ����� ������
    m_House.FlipFirstCard();

    // ��������� ���� ���� �������
    for (auto& pPlayer : m_Players)
        std::cout << pPlayer << std::endl;
    std::cout << m_House << std::endl;

    // ������� ������� �������������� �����
    for (auto& pPlayer : m_Players)
        m_Deck.addCards(pPlayer);

    // ���������� ������ ����� ������
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;

    // ������� ������ �������������� �����
    m_Deck.addCards(m_House);

    if (m_House.isBusted())
    {
        // ���, ��� ������� � ����, ���������
        for (auto& pPlayer : m_Players)
        {
            if (!(pPlayer.isBusted()))
            {
                pPlayer.win();
            }
        }
    }
    else
    {
        // ���������� ����� ����� ���� ���������� ������� � ������ ����� ������
        for (auto& pPlayer : m_Players)
        {
            if (!(pPlayer.isBusted()))
            {
                if (pPlayer.getTotal() > m_House.getTotal())
                    pPlayer.win();
                else if (pPlayer.getTotal() < m_House.getTotal())
                    pPlayer.lose();
                else
                    pPlayer.push();
            }
        }

    }

    // ������� ���� ���� �������
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    m_House.clear();
}
