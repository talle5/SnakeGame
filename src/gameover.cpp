module;

import screen;
import game;
import playgame;

export module gameover;

export class Gameover : Screen {
    Game _gamemanager;

    Gameover(Game gamemanager) : _gamemanager(gamemanager) {}

    void Update() {
        if (Raylib.IsKeyPressed(KeyboardKey.KEY_SPACE) || Raylib.IsKeyPressed(KeyboardKey.KEY_ENTER)) {
            _gamemanager.SetScreen(new PlayRun(_gamemanager));
        }
    }

    void Draw() { Raylib.DrawText("GAME OVER", 400 - Raylib.MeasureText("GAME OVER", 40) / 2, 250, 40, Color.PINK); }
};