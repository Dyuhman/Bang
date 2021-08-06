#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

using namespace std;

const int MAX_BULLETS = 4;

class Player
{
private:
    string m_name;
    int m_current_bullets = 4;
    int m_count_cards = 4;
    bool m_isDeath;

public:
    Player()
    {
        m_name = "Player";
        m_isDeath = false;
    }
    Player(string name)
    : m_name(name)
    {
        m_isDeath = false;
    }

    void setCountBullets(int number)
    {
        if (m_isDeath)
        {
            cout << m_name << " МЕРТВ\n";
            return;
        }
        if (m_current_bullets + number > MAX_BULLETS) return;

        m_current_bullets += number;
    }    

    void setCountCards(int number)
    {
        if (m_isDeath)
        {
            cout << m_name << " МЕРТВ\n";
            return;
        }
        if (m_count_cards + number < 0)
        {
            cout << "У " << m_name << " отсутствуют карты\n";
            return;
        }
        m_count_cards += number;
    }

    void setIsDeath()
    {
        if (m_isDeath) return;
        else m_isDeath = true;
    }

    string getName()
    {
        return m_name;
    }

    int getCountBullets()
    {
        return m_current_bullets;
    }

    int getCountCards()
    {
        return m_count_cards;
    }

    void print()
    {
        cout << "Имя         : " << m_name << endl;
        cout << "Пули (шт.)  : " << m_current_bullets << endl;
        cout << "Карты (шт. ): " << m_count_cards << endl;
        m_isDeath ? cout << "Игрок МЕРТВ\n" : cout << "Игрок ЖИВ\n";
    }
};

#endif