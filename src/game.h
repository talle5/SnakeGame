#pragma once
#include "screen.h"
#include <raylib.h>
#include <stack>

class Game
{
    std::stack<screen *> gamemanager{};

    public:

    ~Game() {
        while (!gamemanager.empty()) {
            back();
        }
    }

    void update() { gamemanager.top()->update(); }

    void draw() { gamemanager.top()->draw(); }

    void addScreen(screen *l) { gamemanager.push(l); }

    void back() {
        delete gamemanager.top();
        gamemanager.pop();
    }

    void setScreen(screen *l) {
        gamemanager.pop();
        gamemanager.push(l);
    }
};