#include "game.h"
#include "playgame.h"
#include <raylib.h>
#include <rlgl.h>

int main() {
    InitWindow(800, 600, "snake");
    Game game;
    game.addScreen(new PlayRun(&game));
    while (!WindowShouldClose()) {
        game.update();
        BeginDrawing();
        rlClearScreenBuffers();
        game.draw();
        DrawFPS(10,10);
        EndDrawing();
    }
    CloseWindow();
}