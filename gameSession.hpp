#ifndef GAMESESSION_HPP
#define GAMESESSION_HPP

#include "player.hpp"

class GameSession
{
private:
    Player *m_current;
    Player *m_first;
    Player *m_second;

public:
    GameSession(Player &first, Player &second)
    : m_first(&first), m_second(&second)
    {
        m_current = m_first;
    }

    void setCurrent()
    {
        if (m_current == m_first)
            m_current = m_second;
        else m_current = m_first;
    }

    Player *getCurrent()
    {
        return m_current;
    }
};

#endif