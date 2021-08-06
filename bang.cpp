#include "player.hpp"
#include "beer.hpp"
#include "stagecoach.hpp"

int main ()
{
    Player oleg("ОЛЕГ");
    Player maks("МАКС");
    GameSession game(oleg, maks);
    
    int who = 1;

    int action;
    int answer;
    
    bool isGame = true;
    while (isGame)
    {
        cout << "Ход игрока:\n";
        switch (who)
        {
            case 1:
                oleg.print();
                cout << "1. БЭНГ;\n";
                cout << "2. ПИВО;\n";
                cout << "3. ДИЛИЖАНС;\n";
                cout << "4. Завершить ХОД\n";
                cin >> action;
                switch (action)
                {
                    case 1:
                        oleg.setCountCards(-1);
                        cout << "БЭНГ на " << maks.getName() << endl;
                        cout << "Как ответит " << maks.getName() << "?\n";
                        cout << "1. МИМО;\n";
                        cout << "2. ПИВО;\n";
                        cout << "3. ПОТЕРЯТЬ ПУЛЮ;\n";
                        cin >> answer;
                        switch (answer)
                        {
                            case 1:
                                if (maks.getCountCards() > 0)
                                    maks.setCountCards(-1);
                                else
                                {
                                    cout << "У игрока " << maks.getName() << " отсутствуют карты\n";
                                    cout << "Игрок " << maks.getName() << " теряет пулю\n";
                                    maks.setCountBullets(-1);
                                }
                                break;
                            case 2:
                                if (maks.getCountCards() > 0)
                                    beer(game, maks);
                                else
                                {
                                    cout << "У игрока " << maks.getName() << " отсутствуют карты\n";
                                    cout << "Игрок " << maks.getName() << " теряет пулю\n";
                                }
                                maks.setCountBullets(-1);
                                break;
                            case 3:
                                cout << "Игрок " << maks.getName() << " теряет пулю\n";
                                maks.setCountBullets(-1);
                                break;
                        }
                        break;
                    case 2:
                        if (oleg.getCountCards() > 0)
                            beer(game, oleg);
                        break;
                    case 3:
                        if (oleg.getCountCards() > 0)
                            stagecoach(game,oleg);
                        break;
                    case 4:
                        game.setCurrent();
                        who *= -1;
                        break;
                }
                break;
            case -1:
                maks.print();
                cout << "1. БЭНГ;\n";
                cout << "2. ПИВО;\n";
                cout << "3. ДИЛИЖАНС;\n";
                cout << "4. Завершить ХОД\n";
                cin >> action;
                switch (action)
                {
                    case 1:
                        maks.setCountCards(-1);
                        cout << "БЭНГ на " << oleg.getName() << endl;
                        cout << "Как ответит " << oleg.getName() << "?\n";
                        cout << "1. МИМО;\n";
                        cout << "2. ПИВО;\n";
                        cout << "3. ПОТЕРЯТЬ ПУЛЮ;\n";
                        cin >> answer;
                        switch (answer)
                        {
                            case 1:
                                if (oleg.getCountCards() > 0)
                                    oleg.setCountCards(-1);
                                else
                                {
                                    cout << "У игрока " << oleg.getName() << " отсутствуют карты\n";
                                    cout << "Игрок " << oleg.getName() << " теряет пулю\n";
                                    oleg.setCountBullets(-1);
                                }
                                break;
                            case 2:
                                if (oleg.getCountCards() > 0)
                                    beer(game, oleg);
                                else
                                {
                                    cout << "У игрока " << oleg.getName() << " отсутствуют карты\n";
                                    cout << "Игрок " << oleg.getName() << " теряет пулю\n";
                                }
                                oleg.setCountBullets(-1);
                                break;
                            case 3:
                                cout << "Игрок " << oleg.getName() << " теряет пулю\n";
                                oleg.setCountBullets(-1);
                                break;
                        }
                        break;
                    case 2:
                        if (maks.getCountCards() > 0)
                            beer(game, maks);
                        break;
                    case 3:
                        if (maks.getCountCards() > 0)
                            stagecoach(game,maks);
                        break;
                    case 4:
                        game.setCurrent();
                        who *= -1;
                        break;
                }
                break;
        }
    }

    return 0;
}