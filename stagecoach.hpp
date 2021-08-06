#include "player.hpp"
#include "gameSession.hpp"

void stagecoach (GameSession &game, Player &player)
{
    if (player.getCountCards() == 0) return;

    if (game.getCurrent() == &player)
    {
        player.setCountCards(-1);
        player.setCountCards(2);
    }
}