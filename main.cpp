#include <raylib.h>
#include <thread>
#include "playgame.ixx"
#include "rlgl.h"

int main() {
    InitWindow(800, 600, "snake");
    PlayRun game;
    std::chrono::milliseconds sleep_time(16);
    while (!WindowShouldClose()) {
        BeginDrawing();
        rlClearScreenBuffers();
        game.draw();
        EndDrawing();
        game.update();
        std::this_thread::sleep_for(sleep_time);
    }
    CloseWindow();
}