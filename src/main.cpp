import <raylib.h>;
import <thread>;
import <rlgl.h>;
import game;
import play;

int main() {
    InitWindow(800, 600, "snake");
    Game kk;
    kk.addScreen(new PlayRun(&kk));
    std::chrono::milliseconds sleep_time(16);
    while (!WindowShouldClose()) {
        BeginDrawing();
        rlClearScreenBuffers();
        kk.draw();
        EndDrawing();
        kk.update();
        std::this_thread::sleep_for(sleep_time);
    }
    CloseWindow();
}