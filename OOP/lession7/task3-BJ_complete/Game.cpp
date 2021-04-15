#include "Game.h"

Game::Game(const std::vector<std::string>& names)
{
    // создает вектор игроков из вектора с именами
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
    // выводит всю колоду
    //m_Deck.printTable();

    // раздает каждому по две стартовые карты
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (auto& pPlayer : m_Players)
            m_Deck.deal(pPlayer);
        m_Deck.deal(m_House);
    }

    // прячет первую карту дилера
    m_House.FlipFirstCard();

    // открывает руки всех игроков
    for (auto& pPlayer : m_Players)
        std::cout << pPlayer << std::endl;
    std::cout << m_House << std::endl;

    // раздает игрокам дополнительные карты
    for (auto& pPlayer : m_Players)
        m_Deck.addCards(pPlayer);

    // показывает первую карту дилера
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;

    // раздает дилеру дополнительные карты
    m_Deck.addCards(m_House);

    if (m_House.isBusted())
    {
        // все, кто остался в игре, побеждают
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
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
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

    // очищает руки всех игроков
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    m_House.clear();
}
