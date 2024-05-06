#include <raylib.h>
#include <thread>
#include <rlgl.h>
import game;
import play;

int main() {
    InitWindow(800, 600, "snake");
    Game game;
    game.addScreen(new PlayRun(&game));
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