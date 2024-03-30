module;

import<raylib.h>;
import screen;
import game;

export module over;

export class Gameover : public screen {
    Game *_gamemanager;
public:
    Gameover(Game *gamemanager) {
        _gamemanager = gamemanager;
    }

    void update() override {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
            _gamemanager->back();
        }
    }

    void draw() override { DrawText("GAME OVER", 400 - MeasureText("GAME OVER", 40) / 2, 250, 40, PINK); }
};