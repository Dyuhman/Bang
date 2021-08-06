#include "player.hpp"
#include "gameSession.hpp"

void beer (GameSession &game, Player &player)
{
    if (player.getCountCards() == 0) return;
    
    if (game.getCurrent() == &player)
    {
        player.setCountCards(-1);
        player.setCountBullets(1);
    }
    
    else
    {
        if (player.getCountBullets() == 1)
        {
            player.setCountCards(-1);
            player.setCountBullets(1);
        }
    }
}