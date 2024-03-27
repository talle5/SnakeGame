export module play;

import states;
#include <list>

class PlayRun : public screen {
    std::list<Square> snake;
    std::list<Square> chanchedpositions;
    Square *head;
    Coin coin;
public:

    PlayRun();

    void draw() override;

    void update() override;

    void add();

private:
    void checkposition(Square &square);

    static bool colisionwhime(Square &entity1, Square &entity2);

    void restartgame();
};