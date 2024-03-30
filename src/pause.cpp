module;

import<raylib.h>;
import screen;
import game;

export module pause;

export class Pause : public screen {
    Game* _gamemanager;
public:

    Pause(Game* gamemanager) : _gamemanager(gamemanager) {}

    void update() override {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
            _gamemanager->back();
        }
    }

    void draw() override { DrawText("Pause", 400 - MeasureText("pause", 40) / 2, 250, 40, PINK); }
};